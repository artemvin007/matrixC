#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_code = ERROR_INCORRECT_MATRIX;
  if (result != NULL) {
    result->rows = 0;
    result->columns = 0;
    result->matrix = NULL;
    if (rows > 0 && columns > 0) {
      double **matrix = (double **)malloc(rows * sizeof(double *) +
                                          rows * columns * sizeof(double));
      err_code = markup_matrix(rows, columns, matrix);
      result->matrix = matrix;
      result->rows = rows;
      result->columns = columns;
    }
  }
  return err_code;
}

int markup_matrix(int rows, int columns, double **matrix) {
  int err_code = ERROR_INCORRECT_MATRIX;
  if (matrix != NULL) {
    double *start = (double *)(matrix + rows);
    for (int i = 0; i < rows; i++) {
      matrix[i] = (double *)(start + i * columns);
      for (int j = 0; j < columns; j++) {
        matrix[i][j] = 0.0;
      }
    }
    err_code = CODE_OK;
  }
  return err_code;
}