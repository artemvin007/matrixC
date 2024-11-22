#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err_code = CODE_OK;
  if (!is_matrix_correct(A)) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else if (is_nan_or_inf(A) || isnan(number) || isinf(number)) {
    err_code = ERROR_CALCULATION;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    just_mult_number(A, number, result);
  }
  return err_code;
}

void just_mult_number(matrix_t *A, double number, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
}