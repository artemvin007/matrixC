#include "s21_matrix_test.h"

START_TEST(s21_transpose1) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t matrix1 = {0, 0, 0}, check = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(rows, cols, &matrix1);
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = (double)rand() / ((double)rand() + 0.1);
      matrix1.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  ck_assert_int_eq(s21_transpose(&matrix1, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_transpose2) {
  matrix_t matrix1 = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(0, 3, &matrix1);
  ck_assert_int_eq(s21_transpose(&matrix1, &result), ERROR_INCORRECT_MATRIX);
}
END_TEST

Suite *suite_s21_transpose() {
  Suite *s = suite_create("transpose");
  TCase *tc = tcase_create("transpose2");

  tcase_add_loop_test(tc, s21_transpose1, 0, 100);
  tcase_add_test(tc, s21_transpose2);

  suite_add_tcase(s, tc);
  return s;
}
