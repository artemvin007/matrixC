#include "s21_matrix_test.h"

START_TEST(s21_create_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(CODE_OK, s21_create_matrix(rows, columns, &matrix));
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_int_eq(matrix.rows, rows);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix2) {
  int rows = 4367;
  int columns = 4;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(CODE_OK, s21_create_matrix(rows, columns, &matrix));
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_int_eq(matrix.rows, rows);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix3) {
  int rows = 2;
  int columns = 8420;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(CODE_OK, s21_create_matrix(rows, columns, &matrix));
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_int_eq(matrix.rows, rows);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix4) {
  int rows = -9;
  int columns = -6;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(ERROR_INCORRECT_MATRIX,
                   s21_create_matrix(rows, columns, &matrix));
}
END_TEST

START_TEST(s21_create_matrix5) {
  int rows = 0;
  int columns = rand() % 100 + 1;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(ERROR_INCORRECT_MATRIX,
                   s21_create_matrix(rows, columns, &matrix));
}
END_TEST

START_TEST(s21_create_matrix6) {
  int rows = rand() % 100 + 1;
  int columns = 0;
  matrix_t matrix = {0, 0, 0};
  ck_assert_int_eq(ERROR_INCORRECT_MATRIX,
                   s21_create_matrix(rows, columns, &matrix));
}
END_TEST

Suite *suite_s21_create_matrix() {
  Suite *s = suite_create("create_matrix");
  TCase *tc = tcase_create("create_matrix_tc");

  tcase_add_loop_test(tc, s21_create_matrix1, 0, 100);
  tcase_add_test(tc, s21_create_matrix2);
  tcase_add_test(tc, s21_create_matrix3);
  tcase_add_test(tc, s21_create_matrix4);
  tcase_add_test(tc, s21_create_matrix5);
  tcase_add_test(tc, s21_create_matrix6);

  suite_add_tcase(s, tc);
  return s;
}