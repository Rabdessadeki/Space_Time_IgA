module mod_coyxijamz1yc


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine assemble_matrix_un_ex01(ne1, ne2, p1, p2, spans_1, spans_2, &
        basis_1, basis_2, weights_1, weights_2, points_1, points_2, &
        matrix)

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
    real(f64), intent(inout) :: matrix(0:,0:,0:,0:)
    integer(i64) :: k1
    integer(i64) :: k2
    integer(i64) :: ie1
    integer(i64) :: i_span_1
    integer(i64) :: ie2
    integer(i64) :: i_span_2
    integer(i64) :: g1
    integer(i64) :: g2
    real(f64) :: x1
    real(f64) :: x2
    integer(i64) :: il_1
    integer(i64) :: il_2
    integer(i64) :: jl_1
    integer(i64) :: jl_2
    integer(i64) :: i1
    integer(i64) :: j1
    integer(i64) :: i2
    integer(i64) :: j2
    real(f64) :: v
    real(f64) :: bi_x1
    real(f64) :: bi_x2
    real(f64) :: bj_x1
    real(f64) :: bj_x2
    real(f64) :: wvol

    !... sizes
    k1 = size(weights_1, 1_i64, i64)
    k2 = size(weights_2, 1_i64, i64)
    !... build matrices
    do ie1 = 0_i64, ne1 - 1_i64
      i_span_1 = spans_1(ie1)
      do ie2 = 0_i64, ne2 - 1_i64
        i_span_2 = spans_2(ie2)
        do g1 = 0_i64, k1 - 1_i64
          do g2 = 0_i64, k2 - 1_i64
            x1 = points_1(g1, ie1)
            x2 = points_2(g2, ie2)
          end do
        end do
        do il_1 = 0_i64, p1 + 1_i64 - 1_i64
          do il_2 = 0_i64, p2 + 1_i64 - 1_i64
            do jl_1 = 0_i64, p1 + 1_i64 - 1_i64
              do jl_2 = 0_i64, p2 + 1_i64 - 1_i64
                i1 = i_span_1 - p1 + il_1
                j1 = i_span_1 - p1 + jl_1
                i2 = i_span_2 - p2 + il_2
                j2 = i_span_2 - p2 + jl_2
                v = 0.0_f64
                do g1 = 0_i64, k1 - 1_i64
                  do g2 = 0_i64, k2 - 1_i64
                    bi_x1 = basis_1(g1, 1_i64, il_1, ie1) * basis_2(g2, &
                          0_i64, il_2, ie2)
                    bi_x2 = basis_1(g1, 0_i64, il_1, ie1) * basis_2(g2, &
                          1_i64, il_2, ie2)
                    bj_x1 = basis_1(g1, 1_i64, jl_1, ie1) * basis_2(g2, &
                          0_i64, jl_2, ie2)
                    bj_x2 = basis_1(g1, 0_i64, jl_1, ie1) * basis_2(g2, &
                          1_i64, jl_2, ie2)
                    wvol = weights_1(g1, ie1) * weights_2(g2, ie2)
                    !...
                    v = v + (bj_x1 * bi_x1 + bj_x2 * bi_x2) * wvol
                  end do
                end do
                matrix(p2 + j2 - i2, p1 + j1 - i1, p2 + i2, p1 + i1) = &
                      matrix(p2 + j2 - i2, p1 + j1 - i1, p2 + i2, p1 + &
                      i1) + v
              end do
            end do
          end do
        end do
      end do
    end do

  end subroutine assemble_matrix_un_ex01
  !........................................

end module mod_coyxijamz1yc
