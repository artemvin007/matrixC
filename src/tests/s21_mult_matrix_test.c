#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0}, result = {0, 0, 0},
           check = {0, 0, 0};
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(cols, rows, &matrix2);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      matrix1.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      matrix2.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);

  s21_create_matrix(matrix1.rows, matrix2.columns, &check);

  for (int i = 0; i < matrix1.rows; i++) {
    for (int j = 0; j < matrix2.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < matrix1.columns; k++)
        check.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
    }
  }

  ck_assert_int_eq(s21_mult_matrix(&matrix1, &matrix2, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix2) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(4, 1, &matrix2);
  ck_assert_int_eq(s21_mult_matrix(&matrix1, &matrix2, &result),
                   ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_mult_matrix3) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(2, 0, &matrix1);
  s21_create_matrix(-1, 1, &matrix2);
  ck_assert_int_eq(s21_mult_matrix(&matrix1, &matrix2, &result),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

Suite *suite_s21_mult_matrix() {
  Suite *s = suite_create("mult_matrix");
  TCase *tc = tcase_create("mult_matrix_tc");

  tcase_add_loop_test(tc, s21_mult_matrix1, 0, 100);
  tcase_add_test(tc, s21_mult_matrix2);
  tcase_add_test(tc, s21_mult_matrix3);

  suite_add_tcase(s, tc);
  return s;
}
