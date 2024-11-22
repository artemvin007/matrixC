#include "s21_matrix.h"

int minus_one_pow(int i, int j) {
  int res = 1;
  if ((i + j) % 2) {
    res = -1;
  }
  return res;
}

int s21_create_minor_matrix(matrix_t *dest, int row_i, int col_i,
                            matrix_t *res) {
  s21_create_matrix(dest->rows - 1, dest->columns - 1, res);

  for (int i = 0; i < row_i; i++) {
    for (int j = 0; j < col_i; j++) {
      res->matrix[i][j] = dest->matrix[i][j];
    }
    for (int j = col_i + 1; j < dest->columns; j++) {
      res->matrix[i][j - 1] = dest->matrix[i][j];
    }
  }
  for (int i = row_i + 1; i < dest->rows; i++) {
    for (int j = 0; j < col_i; j++) {
      res->matrix[i - 1][j] = dest->matrix[i][j];
    }
    for (int j = col_i + 1; j < dest->columns; j++) {
      res->matrix[i - 1][j - 1] = dest->matrix[i][j];
    }
  }
  return res != NULL;
}

int is_nan_or_inf(const matrix_t *A) {
  int res = 0;
  for (int row = 0; row < A->rows && res == CODE_OK; row++) {
    for (int column = 0; column < A->columns && res == CODE_OK; ++column) {
      if (isnan(A->matrix[row][column]) || isinf(A->matrix[row][column])) {
        res = 1;
      }
    }
  }
  return res;
}

int is_matrix_square(matrix_t *A) {
  int res = 1;
  if (A->columns != A->rows) {
    res = 0;
  }
  return res;
}

int is_matrix_correct(matrix_t *A) {
  int res = 1;
  if ((A == NULL) || (A->columns <= 0) || (A->rows <= 0)) {
    res = 0;
  }
  return res;
}