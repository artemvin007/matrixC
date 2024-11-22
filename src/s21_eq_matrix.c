#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (is_matrix_correct(A) && is_matrix_correct(B) &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && res; i++) {
      for (int j = 0; j < B->columns && res; j++) {
        res = res && (fabs(A->matrix[i][j] - B->matrix[i][j]) <= 1e-06);
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}