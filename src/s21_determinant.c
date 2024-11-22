#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err_code = CODE_OK;
  *result = 0;
  if (!is_matrix_correct(A)) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else if (is_nan_or_inf(A) || !is_matrix_square(A)) {
    err_code = ERROR_CALCULATION;
  } else {
    just_determinant(A, result);
  }
  return err_code;
}

void just_determinant(matrix_t *A, double *result) {
  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < A->columns; i++) {
      matrix_t temp = {0, 0, 0};
      s21_create_minor_matrix(A, 0, i, &temp);
      double minor = 0;
      just_determinant(&temp, &minor);
      *result += A->matrix[0][i] * minor * minus_one_pow(i, 0);
      s21_remove_matrix(&temp);
    }
  }
}