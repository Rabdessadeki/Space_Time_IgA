@types('int', 'int', 'int', 'int',  'int[:]', 'int[:]', 'double[:,:,:,:]', 'double[:,:,:,:]',  'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]', 'double[:,:]')
def assemble_vector_un_ex01_without_ddm(ne1, ne2, p1, p2,  
    			    spans_1, spans_2,
    			    basis_1, basis_2, 
    			    weights_1, weights_2,
    			    points_1, points_2,
    			    vector_m1, vector_m2,
    			    vector_d, rhs):
    from numpy import exp
    from numpy import empty
    from numpy import cos, cosh
    from numpy import sin, sinh
    from numpy import pi
    from numpy import arctan2
    from numpy import sqrt
    from numpy import zeros

    # ... sizes
    k1 = weights_1.shape[1]
    k2 = weights_2.shape[1]

    # ...
    lcoeffs_m1  = zeros((p1+1,p2+1))
    lcoeffs_m2  = zeros((p1+1,p2+1))
    lcoeffs_di  = zeros((p1+1,p2+1))
    #..
    lvalues_u   = zeros((k1, k2))
    arr_J_mat0  = zeros((k1, k2))
    arr_J_mat1  = zeros((k1, k2))
    arr_J_mat2  = zeros((k1, k2))
    arr_J_mat3  = zeros((k1, k2))
    lvalues_Jac = zeros((k1, k2))
    lvalues_udx = zeros((k1, k2))
    lvalues_udy = zeros((k1, k2))

    # ... build rhs
    for ie1 in range(0, ne1):
        i_span_1 = spans_1[ie1]
        for ie2 in range(0, ne2):
            i_span_2 = spans_2[ie2]
            
            lcoeffs_m1[ : , : ] = vector_m1[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            lcoeffs_m2[ : , : ] = vector_m2[i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            lcoeffs_di[ : , : ] = vector_d[ i_span_1 : i_span_1+p1+1, i_span_2 : i_span_2+p2+1]
            for g1 in range(0, k1):
                for g2 in range(0, k2):

                    x    = 0.0
                    y    = 0.0
                    F1x  = 0.0
                    F1y  = 0.0
                    F2x  = 0.0
                    F2y  = 0.0
                    # ...
                    udx  = 0.0
                    udy  = 0.0
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

                              coeff_di =  lcoeffs_di[il_1,il_2]
                              udx     +=  coeff_di * bj_x
                              udy     +=  coeff_di * bj_y
                              
                    J_mat = abs(F1x*F2y-F1y*F2x)
                    arr_J_mat0[g1,g2] = F2y
                    arr_J_mat1[g1,g2] = F1x
                    arr_J_mat2[g1,g2] = F1y
                    arr_J_mat3[g1,g2] = F2x
                    lvalues_udx[g1, g2]  = (F2y * udx - F2x*udy)
                    lvalues_udx[g1, g2] /= J_mat
                    lvalues_udy[g1, g2]  = (F1x * udy - F1y*udx)
                    lvalues_udy[g1, g2] /= J_mat
                    #.. Test 0
                    
                    #f = pi**2*x*sin(pi*y) #  Non vanishing Dirichlet at x = 1
                    # 
                    # ... Test 1
                    f = 2*x**2 - 2*y*(1 - y)# Non vanishing Neumann at  x =  1

                    
                    # .. Test 2 Quart annnulus
                    #f =  -20.0*x*y*(800*x - 400.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 - 1562.5*y**3*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)**2/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**3 
                    #f += 781.25*y**3*(-x**2 - y**2 + 1.0)/cosh(-6.25*y**2 + 400*(x - 0.5)**2) + 250.0*y**3*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 - 6400000.0*y*(x - 0.5)**2*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)**2/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**3 
                    #f += 5.0*y*(640000*(x - 0.5)**2)*(-x**2 - y**2 + 1.0)/cosh(-6.25*y**2 + 400*(x - 0.5)**2) + 3812.5*y*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 + 40.0*y/cosh(-6.25*y**2 + 400*(x - 0.5)**2) 
                    

                    lvalues_u[g1,g2]   = f 
                    lvalues_Jac[g1,g2] = J_mat
            for il_1 in range(0, p1+1):
                for il_2 in range(0, p2+1):
                    i1 = i_span_1 - p1 + il_1
                    i2 = i_span_2 - p2 + il_2

                    v = 0.0
                    for g1 in range(0, k1):
                        for g2 in range(0, k2):
                            bi_0  = basis_1[ie1, il_1, 0, g1] * basis_2[ie2, il_2, 0, g2]
                            bi_x1 = basis_1[ie1, il_1, 1, g1] * basis_2[ie2, il_2, 0, g2]
                            bi_x2 = basis_1[ie1, il_1, 0, g1] * basis_2[ie2, il_2, 1, g2]
                            # ...
                            wvol  = weights_1[ie1, g1] * weights_2[ie2, g2]
                            # ...
                            bi_x  = arr_J_mat0[g1,g2] * bi_x1 - arr_J_mat3[g1,g2] * bi_x2
                            bi_y  = arr_J_mat1[g1,g2] * bi_x2 - arr_J_mat2[g1,g2] * bi_x1
                            
                            u     = lvalues_u[g1,g2]
                            udx   = lvalues_udx[g1, g2]
                            udy   = lvalues_udy[g1, g2]
                            v    += bi_0 * u * wvol * lvalues_Jac[g1,g2] -  (udx * bi_x+ udy * bi_y) * wvol

                    rhs[i1+p1,i2+p2] += v
