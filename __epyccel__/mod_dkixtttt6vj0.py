@types('int', 'int', 'int', 'int', 'int[:]', 'int[:]', 'double[:,:,:,:]', 'double[:,:,:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]',  'double[:,:]','double[:,:]')
def assemble_norm_ex01(ne1, ne2, p1, p2, spans_1, spans_2,  basis_1, basis_2,  weights_1, weights_2, points_1, points_2, vector_u, rhs):

    from numpy import exp
    from numpy import cos
    from numpy import sin
    from numpy import pi
    from numpy import sqrt
    from numpy import zeros

    # ... sizes
    k1 = weights_1.shape[1]
    k2 = weights_2.shape[1]
    # ...

    lcoeffs_u = zeros((p1+1,p2+1))
    lvalues_u = zeros((k1, k2))
    lvalues_ux = zeros((k1, k2))
    lvalues_uy = zeros((k1, k2))

    norm_l2 = 0.
    norm_H1 = 0.
    # ...
    for ie1 in range(0, ne1):
        i_span_1 = spans_1[ie1]
        for ie2 in range(0, ne2):
            i_span_2 = spans_2[ie2]

            lvalues_u[ : , : ]  = 0.0
            lvalues_ux[ : , : ] = 0.0
            lvalues_uy[ : , : ] = 0.0
            lcoeffs_u[ : , : ]  = vector_u[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            for il_1 in range(0, p1+1):
                for il_2 in range(0, p2+1):
                    coeff_u = lcoeffs_u[il_1,il_2]

                    for g1 in range(0, k1):
                        b1  = basis_1[ie1,il_1,0,g1]
                        db1 = basis_1[ie1,il_1,1,g1]
                        for g2 in range(0, k2):
                            b2  = basis_2[ie2,il_2,0,g2]
                            db2 = basis_2[ie2,il_2,1,g2]

                            lvalues_u[g1,g2]  += coeff_u*b1*b2
                            lvalues_ux[g1,g2] += coeff_u*db1*b2
                            lvalues_uy[g1,g2] += coeff_u*b1*db2

            v = 0.0
            w = 0.0
            for g1 in range(0, k1):
                for g2 in range(0, k2):
                    wvol = weights_1[ie1, g1] * weights_2[ie2, g2]

                    x    = points_1[ie1, g1]
                    y    = points_2[ie2, g2]

                    # ... test 0
                    u   = sin(pi*x)*sin(pi*y)
                    ux  = pi*cos(pi*x)*sin(pi*y)
                    uy  = pi*sin(pi*x)*cos(pi*y) 
                    # ... test 1
                    #u  = exp(-200.*(((x-.5)/0.4)**2+((y-.5)/0.4)**2-0.6)**2 )
                    #ux = -7812.5*(4*x - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                    #uy = -7812.5*(4*y - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2) 
                    # ... test 2
                    
                    uh  = lvalues_u[g1,g2]
                    uhx = lvalues_ux[g1,g2]
                    uhy = lvalues_uy[g1,g2]

                    v  += (u-uh)**2 * wvol
                    w  += ((ux-uhx)**2+(uy-uhy)**2) * wvol
            norm_l2 += v
            norm_H1 += w

    norm_l2 = sqrt(norm_l2)
    norm_H1 = sqrt(norm_H1)

    rhs[p1,p2]   = norm_l2
    rhs[p1,p2+1] = norm_H1
    # ...
