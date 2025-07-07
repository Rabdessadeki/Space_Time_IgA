module mod_n521fqn2ds3f


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine assemble_vector_un_ex01_without_ddm(ne1, ne2, p1, p2, &
        spans_1, spans_2, basis_1, basis_2, weights_1, weights_2, &
        points_1, points_2, vector_m1, vector_m2, vector_d, rhs)

    implicit none

    integer(i64), value :: ne1
    integer(i64), value :: ne2
    integer(i64), value :: p1
    integer(i64), value :: p2
    integer(i64), intent(in) :: spans_1(0:)
    integer(i64), intent(in) :: spans_2(0:)
    real(f64), intent(in) :: basis_1(0:,0:,0:,0:)
    real(f64), intent(in) :: basis_2(0:,0:,0:,0:)
    real(f64), intent(in) :: weights_1(0:,0:)
    real(f64), intent(in) :: weights_2(0:,0:)
    real(f64), intent(in) :: points_1(0:,0:)
    real(f64), intent(in) :: points_2(0:,0:)
    real(f64), intent(in) :: vector_m1(0:,0:)
    real(f64), intent(in) :: vector_m2(0:,0:)
    real(f64), intent(in) :: vector_d(0:,0:)
    real(f64), intent(inout) :: rhs(0:,0:)
    integer(i64) :: k1
    integer(i64) :: k2
    real(f64), allocatable :: lcoeffs_m1(:,:)
    real(f64), allocatable :: lcoeffs_m2(:,:)
    real(f64), allocatable :: lcoeffs_di(:,:)
    real(f64), allocatable :: lvalues_u(:,:)
    real(f64), allocatable :: arr_J_mat0(:,:)
    real(f64), allocatable :: arr_J_mat1(:,:)
    real(f64), allocatable :: arr_J_mat2(:,:)
    real(f64), allocatable :: arr_J_mat3(:,:)
    real(f64), allocatable :: lvalues_Jac(:,:)
    real(f64), allocatable :: lvalues_udx(:,:)
    real(f64), allocatable :: lvalues_udy(:,:)
    integer(i64) :: ie1
    integer(i64) :: i_span_1
    integer(i64) :: ie2
    integer(i64) :: i_span_2
    integer(i64) :: g1
    integer(i64) :: g2
    real(f64) :: x
    real(f64) :: y
    real(f64) :: F1x
    real(f64) :: F1y
    real(f64) :: F2x
    real(f64) :: F2y
    real(f64) :: udx
    real(f64) :: udy
    integer(i64) :: il_1
    integer(i64) :: il_2
    real(f64) :: bj_0
    real(f64) :: bj_x
    real(f64) :: bj_y
    real(f64) :: coeff_m1
    real(f64) :: coeff_m2
    real(f64) :: coeff_di
    real(f64) :: J_mat
    real(f64) :: f
    integer(i64) :: i1
    integer(i64) :: i2
    real(f64) :: v
    real(f64) :: bi_0
    real(f64) :: bi_x1
    real(f64) :: bi_x2
    real(f64) :: wvol
    real(f64) :: bi_x
    real(f64) :: bi_y
    real(f64) :: u

    !... sizes
    k1 = size(weights_1, 1_i64, i64)
    k2 = size(weights_2, 1_i64, i64)
    !...
    allocate(lcoeffs_m1(0:p2 + 1_i64 - 1_i64, 0:p1 + 1_i64 - 1_i64))
    lcoeffs_m1 = 0.0_f64
    allocate(lcoeffs_m2(0:p2 + 1_i64 - 1_i64, 0:p1 + 1_i64 - 1_i64))
    lcoeffs_m2 = 0.0_f64
    allocate(lcoeffs_di(0:p2 + 1_i64 - 1_i64, 0:p1 + 1_i64 - 1_i64))
    lcoeffs_di = 0.0_f64
    !..
    allocate(lvalues_u(0:k2 - 1_i64, 0:k1 - 1_i64))
    lvalues_u = 0.0_f64
    allocate(arr_J_mat0(0:k2 - 1_i64, 0:k1 - 1_i64))
    arr_J_mat0 = 0.0_f64
    allocate(arr_J_mat1(0:k2 - 1_i64, 0:k1 - 1_i64))
    arr_J_mat1 = 0.0_f64
    allocate(arr_J_mat2(0:k2 - 1_i64, 0:k1 - 1_i64))
    arr_J_mat2 = 0.0_f64
    allocate(arr_J_mat3(0:k2 - 1_i64, 0:k1 - 1_i64))
    arr_J_mat3 = 0.0_f64
    allocate(lvalues_Jac(0:k2 - 1_i64, 0:k1 - 1_i64))
    lvalues_Jac = 0.0_f64
    allocate(lvalues_udx(0:k2 - 1_i64, 0:k1 - 1_i64))
    lvalues_udx = 0.0_f64
    allocate(lvalues_udy(0:k2 - 1_i64, 0:k1 - 1_i64))
    lvalues_udy = 0.0_f64
    !... build rhs
    do ie1 = 0_i64, ne1 - 1_i64
      i_span_1 = spans_1(ie1)
      do ie2 = 0_i64, ne2 - 1_i64
        i_span_2 = spans_2(ie2)
        lcoeffs_m1(:, :) = vector_m1(i_span_2:i_span_2 + p2 + 1_i64 - &
              1_i64, i_span_1:i_span_1 + p1 + 1_i64 - 1_i64)
        lcoeffs_m2(:, :) = vector_m2(i_span_2:i_span_2 + p2 + 1_i64 - &
              1_i64, i_span_1:i_span_1 + p1 + 1_i64 - 1_i64)
        lcoeffs_di(:, :) = vector_d(i_span_2:i_span_2 + p2 + 1_i64 - &
              1_i64, i_span_1:i_span_1 + p1 + 1_i64 - 1_i64)
        do g1 = 0_i64, k1 - 1_i64
          do g2 = 0_i64, k2 - 1_i64
            x = 0.0_f64
            y = 0.0_f64
            F1x = 0.0_f64
            F1y = 0.0_f64
            F2x = 0.0_f64
            F2y = 0.0_f64
            !...
            udx = 0.0_f64
            udy = 0.0_f64
            do il_1 = 0_i64, p1 + 1_i64 - 1_i64
              do il_2 = 0_i64, p2 + 1_i64 - 1_i64
                bj_0 = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, 0_i64 &
                      , il_2, ie2)
                bj_x = basis_1(g1, 1_i64, il_1, ie1) * basis_2(g2, 0_i64 &
                      , il_2, ie2)
                bj_y = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, 1_i64 &
                      , il_2, ie2)
                coeff_m1 = lcoeffs_m1(il_2, il_1)
                x = x + coeff_m1 * bj_0
                F1x = F1x + coeff_m1 * bj_x
                F1y = F1y + coeff_m1 * bj_y
                coeff_m2 = lcoeffs_m2(il_2, il_1)
                y = y + coeff_m2 * bj_0
                F2x = F2x + coeff_m2 * bj_x
                F2y = F2y + coeff_m2 * bj_y
                coeff_di = lcoeffs_di(il_2, il_1)
                udx = udx + coeff_di * bj_x
                udy = udy + coeff_di * bj_y
              end do
            end do
            J_mat = abs(F1x * F2y - F1y * F2x)
            arr_J_mat0(g2, g1) = F2y
            arr_J_mat1(g2, g1) = F1x
            arr_J_mat2(g2, g1) = F1y
            arr_J_mat3(g2, g1) = F2x
            lvalues_udx(g2, g1) = F2y * udx - F2x * udy
            lvalues_udx(g2, g1) = lvalues_udx(g2, g1) / J_mat
            lvalues_udy(g2, g1) = F1x * udy - F1y * udx
            lvalues_udy(g2, g1) = lvalues_udy(g2, g1) / J_mat
            !.. Test 0
            !f = 2*pi**2*sin(pi*y)*sin(pi*x)
            f = 3.141592653589793_f64 * 3.141592653589793_f64 * x * sin( &
                  3.141592653589793_f64 * y)
            !
            !... Test 1
            !f = 2*x**2 - 2*y*(1 - y)# Non vanishing Neumann at  x =  1
            !.. Test 2 Quart annnulus
            !f =  -20.0*x*y*(800*x - 400.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 - 1562.5*y**3*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)**2/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**3
            !f += 781.25*y**3*(-x**2 - y**2 + 1.0)/cosh(-6.25*y**2 + 400*(x - 0.5)**2) + 250.0*y**3*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 - 6400000.0*y*(x - 0.5)**2*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)**2/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**3
            !f += 5.0*y*(640000*(x - 0.5)**2)*(-x**2 - y**2 + 1.0)/cosh(-6.25*y**2 + 400*(x - 0.5)**2) + 3812.5*y*(-x**2 - y**2 + 1.0)*sinh(-6.25*y**2 + 400*(x - 0.5)**2)/cosh(-6.25*y**2 + 400*(x - 0.5)**2)**2 + 40.0*y/cosh(-6.25*y**2 + 400*(x - 0.5)**2)
            lvalues_u(g2, g1) = f
            lvalues_Jac(g2, g1) = J_mat
          end do
        end do
        do il_1 = 0_i64, p1 + 1_i64 - 1_i64
          do il_2 = 0_i64, p2 + 1_i64 - 1_i64
            i1 = i_span_1 - p1 + il_1
            i2 = i_span_2 - p2 + il_2
            v = 0.0_f64
            do g1 = 0_i64, k1 - 1_i64
              do g2 = 0_i64, k2 - 1_i64
                bi_0 = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, 0_i64 &
                      , il_2, ie2)
                bi_x1 = basis_1(g1, 1_i64, il_1, ie1) * basis_2(g2, &
                      0_i64, il_2, ie2)
                bi_x2 = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, &
                      1_i64, il_2, ie2)
                !...
                wvol = weights_1(g1, ie1) * weights_2(g2, ie2)
                !...
                bi_x = arr_J_mat0(g2, g1) * bi_x1 - arr_J_mat3(g2, g1) * &
                      bi_x2
                bi_y = arr_J_mat1(g2, g1) * bi_x2 - arr_J_mat2(g2, g1) * &
                      bi_x1
                u = lvalues_u(g2, g1)
                udx = lvalues_udx(g2, g1)
                udy = lvalues_udy(g2, g1)
                v = v + (bi_0 * u * wvol * lvalues_Jac(g2, g1) - (udx * &
                      bi_x + udy * bi_y) * wvol)
              end do
            end do
            rhs(i2 + p2, i1 + p1) = rhs(i2 + p2, i1 + p1) + v
          end do
        end do
      end do
    end do
    if (allocated(lvalues_udy)) then
      deallocate(lvalues_udy)
    end if
    if (allocated(lcoeffs_m2)) then
      deallocate(lcoeffs_m2)
    end if
    if (allocated(lvalues_u)) then
      deallocate(lvalues_u)
    end if
    if (allocated(lcoeffs_di)) then
      deallocate(lcoeffs_di)
    end if
    if (allocated(arr_J_mat0)) then
      deallocate(arr_J_mat0)
    end if
    if (allocated(arr_J_mat1)) then
      deallocate(arr_J_mat1)
    end if
    if (allocated(lvalues_udx)) then
      deallocate(lvalues_udx)
    end if
    if (allocated(arr_J_mat2)) then
      deallocate(arr_J_mat2)
    end if
    if (allocated(lvalues_Jac)) then
      deallocate(lvalues_Jac)
    end if
    if (allocated(arr_J_mat3)) then
      deallocate(arr_J_mat3)
    end if
    if (allocated(lcoeffs_m1)) then
      deallocate(lcoeffs_m1)
    end if

  end subroutine assemble_vector_un_ex01_without_ddm
  !........................................

end module mod_n521fqn2ds3f
