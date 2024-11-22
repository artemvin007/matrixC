#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err_code = CODE_OK;
  if (!is_matrix_correct(A) && result != NULL) {
    err_code = ERROR_INCORRECT_MATRIX;
  } else {
    err_code = calc_inverse_matrix(A, result);
  }
  return err_code;
}

int calc_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err_code = CODE_OK;
  double det = 0.0;
  matrix_t complements = {0, 0, 0};
  matrix_t transponse_complements = {0, 0, 0};
  if (!err_code) err_code = s21_determinant(A, &det);
  if (fabs(det) <= 1e-06)
    err_code = ERROR_CALCULATION;
  else
    det = 1 / det;
  if (!err_code) err_code = s21_calc_complements(A, &complements);
  if (!err_code)
    err_code = s21_transpose(&complements, &transponse_complements);
  if (!err_code)
    err_code = s21_mult_number(&transponse_complements, det, result);

  s21_remove_matrix(&transponse_complements);
  s21_remove_matrix(&complements);
  return err_code;
}