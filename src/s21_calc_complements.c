#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err_code = CODE_OK;
  if (!is_matrix_correct(A) || result == NULL) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else if (!is_matrix_square(A) || is_nan_or_inf(A) || A->columns < 2 ||
             s21_create_matrix(A->rows, A->columns, result) != CODE_OK) {
    err_code = ERROR_CALCULATION;
  } else {
    just_calc_complements(A, result);
  }
  return err_code;
}

void just_calc_complements(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t temp = {0, 0, 0};
      s21_create_minor_matrix(A, i, j, &temp);
      s21_determinant(&temp, &result->matrix[i][j]);
      result->matrix[i][j] *= minus_one_pow(i, j);
      s21_remove_matrix(&temp);
    }
  }
}