module mod_ap0u31w6ejqm


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine assemble_vector_ex01(ne1, ne2, p1, p2, spans_1, spans_2, &
        basis_1, basis_2, weights_1, weights_2, points_1, points_2, &
        vector_d, rhs)

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
    real(f64), intent(in) :: vector_d(0:,0:)
    real(f64), intent(inout) :: rhs(0:,0:)
    integer(i64) :: k1
    integer(i64) :: k2
    real(f64), allocatable :: lcoeffs_d(:,:)
    integer(i64) :: ie1
    integer(i64) :: i_span_1
    integer(i64) :: ie2
    integer(i64) :: i_span_2
    integer(i64) :: il_1
    integer(i64) :: il_2
    integer(i64) :: i1
    integer(i64) :: i2
    real(f64) :: v
    integer(i64) :: g1
    integer(i64) :: g2
    real(f64) :: bi_0
    real(f64) :: wvol
    real(f64) :: x
    real(f64) :: y
    real(f64) :: u

    !... sizes
    k1 = size(weights_1, 1_i64, i64)
    k2 = size(weights_2, 1_i64, i64)
    !...
    allocate(lcoeffs_d(0:p2 + 1_i64 - 1_i64, 0:p1 + 1_i64 - 1_i64))
    lcoeffs_d = 0.0_f64
    !... build rhs
    do ie1 = 0_i64, ne1 - 1_i64
      i_span_1 = spans_1(ie1)
      do ie2 = 0_i64, ne2 - 1_i64
        i_span_2 = spans_2(ie2)
        do il_1 = 0_i64, p1 + 1_i64 - 1_i64
          do il_2 = 0_i64, p2 + 1_i64 - 1_i64
            i1 = i_span_1 - p1 + il_1
            i2 = i_span_2 - p2 + il_2
            v = 0.0_f64
            do g1 = 0_i64, k1 - 1_i64
              do g2 = 0_i64, k2 - 1_i64
                bi_0 = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, 0_i64 &
                      , il_2, ie2)
                wvol = weights_1(g1, ie1) * weights_2(g2, ie2)
                x = points_1(g1, ie1)
                y = points_2(g2, ie2)
                !.. Test 0
                u = 2_i64 * (3.141592653589793_f64 * &
                      3.141592653589793_f64) * sin( &
                      3.141592653589793_f64 * x) * sin( &
                      3.141592653589793_f64 * y)
                !... test 1
                !u  = -(15625.0 - 31250.0*x)*(2*x - 1.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                !u += 7812.5*(15625.0 - 31250.0*x)*(4*x - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                !u += -(15625.0 - 31250.0*y)*(2*y - 1.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                !u += 7812.5*(15625.0 - 31250.0*y)*(4*y - 2.0)*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                !u += -2*(-31250.0*(x - 0.5)**2 - 31250.0*(y - 0.5)**2 + 3000.0)*exp(-7812.5*((x - 0.5)**2 + (y - 0.5)**2 - 0.096)**2)
                !..
                v = v + bi_0 * u * wvol
              end do
            end do
            rhs(i2 + p2, i1 + p1) = rhs(i2 + p2, i1 + p1) + v
          end do
        end do
      end do
    end do
    if (allocated(lcoeffs_d)) then
      deallocate(lcoeffs_d)
    end if

  end subroutine assemble_vector_ex01
  !........................................

end module mod_ap0u31w6ejqm
