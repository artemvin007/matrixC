#include "s21_matrix_test.h"

START_TEST(s21_mult_number1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t matrix1 = {0, 0, 0}, check = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(rows, cols, &check);
  double number = (double)rand() / ((double)rand() + 0.1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix1.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);
      check.matrix[i][j] = matrix1.matrix[i][j] * number;
    }
  }

  ck_assert_int_eq(s21_mult_number(&matrix1, number, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_number2) {
  matrix_t matrix1 = {0, 0, 0}, result = {0, 0, 0};
  double number = (double)rand() / ((double)rand() + 0.1);
  s21_create_matrix(2, 0, &matrix1);
  ck_assert_int_eq(s21_mult_number(&matrix1, number, &result),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number3) {
  matrix_t matrix1 = {0, 0, 0}, result = {0, 0, 0};
  double number = NAN;
  s21_create_matrix(2, 1, &matrix1);
  ck_assert_int_eq(s21_mult_number(&matrix1, number, &result),
                   ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
}
END_TEST

Suite *suite_s21_mult_number() {
  Suite *s = suite_create("mult_number");
  TCase *tc = tcase_create("mult_number_tc");

  tcase_add_loop_test(tc, s21_mult_number1, 0, 100);
  tcase_add_test(tc, s21_mult_number2);
  tcase_add_test(tc, s21_mult_number3);

  suite_add_tcase(s, tc);
  return s;
}
