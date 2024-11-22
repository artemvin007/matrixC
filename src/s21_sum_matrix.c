#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_code = CODE_OK;
  if (!is_matrix_correct(A) || !is_matrix_correct(B)) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else if (is_nan_or_inf(A) || is_nan_or_inf(B) || A->rows != B->rows ||
             A->columns != B->columns) {
    err_code = ERROR_CALCULATION;
  } else {
    just_sum_matrix(A, B, result);
  }
  return err_code;
}

void just_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
}