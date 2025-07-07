@types('int', 'int', 'int', 'int', 'int[:]', 'int[:]', 'double[:,:,:,:]', 'double[:,:,:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]',  'double[:,:]',  'double[:,:]')
def assemble_norm_ex01(ne1, ne2, p1, p2, spans_1, spans_2,  basis_1, basis_2,  weights_1, weights_2, points_1, points_2, vector_m1, vector_m2, vector_u, rhs):

    from numpy import exp
    from numpy import pi
    from numpy import sin, sinh
    from numpy import arctan2
    from numpy import cos, cosh
    from numpy import sqrt
    from numpy import zeros
    # ... sizes
    k1 = weights_1.shape[1]
    k2 = weights_2.shape[1]

    #.. circle

    # ...
    lcoeffs_m1 = zeros((p1+1,p2+1))
    lcoeffs_m2 = zeros((p1+1,p2+1))
    lcoeffs_u  = zeros((p1+1,p2+1))
    # ...
    lvalues_ux = zeros((k1, k2))
    lvalues_uy = zeros((k1, k2))
    lvalues_u  = zeros((k1, k2))

    error_l2 = 0.
    error_H1 = 0.
    # ...
    for ie1 in range(0, ne1):
        i_span_1 = spans_1[ie1]
        for ie2 in range(0, ne2):
            i_span_2 = spans_2[ie2]

            lvalues_u[ : , : ]  = 0.0
            lvalues_ux[ : , : ]  = 0.0
            lvalues_uy[ : , : ]  = 0.0
            lcoeffs_u[ : , : ] = vector_u[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            for il_1 in range(0, p1+1):
                for il_2 in range(0, p2+1):
                    coeff_u = lcoeffs_u[il_1,il_2]

                    for g1 in range(0, k1):
                        b1 = basis_1[ie1,il_1,0,g1]
                        db1 = basis_1[ie1,il_1,1,g1]
                        for g2 in range(0, k2):
                            b2 = basis_2[ie2,il_2,0,g2]
                            db2 = basis_2[ie2,il_2,1,g2]

                            lvalues_u[g1,g2]   += coeff_u*b1*b2
                            lvalues_ux[g1,g2]  += coeff_u*db1*b2
                            lvalues_uy[g1,g2]  += coeff_u*b1*db2

            w = 0.0
            v = 0.0
            lcoeffs_m1[ : , : ] = vector_m1[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            lcoeffs_m2[ : , : ] = vector_m2[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            for g1 in range(0, k1):
                for g2 in range(0, k2):

                    x   = 0.0
                    y   = 0.0
                    F1x = 0.0
                    F1y = 0.0
                    F2x = 0.0
                    F2y = 0.0
                    for il_1 in range(0, p1+1):
                          for il_2 in range(0, p2+1):

                              bj_0     = basis_1[ie1,il_1,0,g1]*basis_2[ie2,il_2,0,g2]
                              bj_x     = basis_1[ie1,il_1,1,g1]*basis_2[ie2,il_2,0,g2]
                              bj_y     = basis_1[ie1,il_1,0,g1]*basis_2[ie2,il_2,1,g2]

                              coeff_m1 =  lcoeffs_m1[il_1,il_2]
                              x       +=  coeff_m1 * bj_0
                              F1x     +=  coeff_m1 * bj_x
                              F1y     +=  coeff_m1 * bj_y

                              coeff_m2 =  lcoeffs_m2[il_1,il_2]
                              y       +=  coeff_m2 * bj_0
                              F2x     +=  coeff_m2 * bj_x
                              F2y     +=  coeff_m2 * bj_y

                    det_J = abs(F1x*F2y-F1y*F2x)
                    
                    # ...                              
                    wvol  = weights_1[ie1, g1] * weights_2[ie2, g2]
                    x1    =  points_1[ie1, g1]
                    x2    =  points_2[ie2, g2]

                    uh    = lvalues_u[g1,g2]
                    sx    = lvalues_ux[g1,g2]
                    sy    = lvalues_uy[g1,g2]
                   
                    #... Test 0
                    f    = sin(pi*x)*sin(pi*y)
                    fx   = pi*cos(pi*x)*sin(pi*y)
                    fy   = pi*sin(pi*x)*cos(pi*y)
                    
                    # ... Test 1                    
                    #f    = x*sin(pi*y)
                    #fx   = sin(pi*y)
                    #fy   = pi*x*cos(pi*y)
                    
                    
                    # ... Test 2
                    #f =  x**2*y*(1 - y)
                    #fx=  2*x*y*(1 - y)
                    #fy=  -x**2*y + x**2*(1 - y)

                    # ...
                    uhx   = (F2y*sx-F2x*sy)/det_J
                    uhy   = (F1x*sy-F1y*sx)/det_J

                    w    += ((uhx-fx)**2 +(uhy-fy)**2)* wvol * det_J
                    v    += (uh-f)**2 * wvol * det_J

            error_H1      += w
            error_l2      += v
    rhs[p1,p2]   = sqrt(error_l2)
    rhs[p1,p2+1] = sqrt(error_H1)
    #...
