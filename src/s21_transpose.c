#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err_code = CODE_OK;
  if (!is_matrix_correct(A)) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else {
    if (s21_create_matrix(A->columns, A->rows, result) == CODE_OK) {
      just_transpose(A, result);
    }
  }
  return err_code;
}

void just_transpose(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
}