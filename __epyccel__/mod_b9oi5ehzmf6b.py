@types('int', 'int', 'int', 'int', 'int[:]', 'int[:]', 'double[:,:,:,:]', 'double[:,:,:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]')
def assemble_vector_ex01(ne1, ne2, p1, p2, spans_1, spans_2, basis_1, basis_2, weights_1, weights_2, points_1, points_2, vector_d,  rhs):

    from numpy import exp
    from numpy import pi
    from numpy import sin
    from numpy import arctan2
    from numpy import cos, cosh
    from numpy import sqrt
    from numpy import zeros 
    from numpy import empty

    # ... sizes
    k1        = weights_1.shape[1]
    k2        = weights_2.shape[1]

    # ...
    lcoeffs_d   = zeros((p1+1,p2+1))
    # ... build rhs
    for ie1 in range(0, ne1):
        i_span_1 = spans_1[ie1]
        for ie2 in range(0, ne2):
            i_span_2 = spans_2[ie2]
            for il_1 in range(0, p1+1):
                for il_2 in range(0, p2+1):
                    i1 = i_span_1 - p1 + il_1
                    i2 = i_span_2 - p2 + il_2

                    v = 0.0
                    for g1 in range(0, k1):
                        for g2 in range(0, k2):
                            
                            bi_0 = basis_1[ie1, il_1, 0, g1] * basis_2[ie2, il_2, 0, g2]

                            wvol  = weights_1[ie1, g1]*weights_2[ie2, g2]
                            x  = points_1[ie1, g1]
                            y  = points_2[ie2, g2]
                            # .. Test 0
                            u    = 2*pi**2*sin(pi*x)*sin(pi*y)
                            # ... test 1                                 
                            #u  = -(15625.0 - 31250.0*x)*(2*x - 1.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2) 
                            #u += 7812.5*(15625.0 - 31250.0*x)*(4*x - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2) 
                            #u += -(15625.0 - 31250.0*y)*(2*y - 1.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2) 
                            #u += 7812.5*(15625.0 - 31250.0*y)*(4*y - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2) 
                            #u += -2*(-31250.0*(x - 0.5)**2 - 31250.0*(y - 0.5)**2 + 3000.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                            # ..
                            v += bi_0 * u * wvol

                    rhs[i1+p1,i2+p2] += v  
