#include "s21_matrix_test.h"

START_TEST(s21_inverse_matrix1) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(1, 0, &matrix1);
  ck_assert_int_eq(s21_inverse_matrix(&matrix1, &matrix2),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix2) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(1, 11, &matrix1);
  ck_assert_int_eq(s21_inverse_matrix(&matrix1, &matrix2), ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_inverse_matrix3) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(1, 1, &matrix1);
  ck_assert_int_eq(s21_inverse_matrix(&matrix1, &matrix2), ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_inverse_matrix4) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0}, check = {0, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;

  s21_create_matrix(3, 3, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = -0.5;
  check.matrix[0][2] = 0;
  check.matrix[1][0] = -9.5;
  check.matrix[1][1] = 5.5;
  check.matrix[1][2] = 1;
  check.matrix[2][0] = 8;
  check.matrix[2][1] = -4.5;
  check.matrix[2][2] = -1;

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix5) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0}, check = {0, 0, 0};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 2;
  matrix.matrix[1][0] = 2;
  matrix.matrix[1][1] = 2;
  matrix.matrix[1][2] = -2;
  matrix.matrix[1][3] = -1;
  matrix.matrix[2][0] = 4;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 2;
  matrix.matrix[2][3] = 2;
  matrix.matrix[3][0] = 2;
  matrix.matrix[3][1] = 2;
  matrix.matrix[3][2] = 3;
  matrix.matrix[3][3] = 4;

  s21_create_matrix(4, 4, &check);
  check.matrix[0][0] = -0.5;
  check.matrix[0][1] = 0;
  check.matrix[0][2] = 0.5;
  check.matrix[0][3] = 0;
  check.matrix[1][0] = 1;
  check.matrix[1][1] = 0.2;
  check.matrix[1][2] = -0.5;
  check.matrix[1][3] = -0.2;
  check.matrix[2][0] = 1;
  check.matrix[2][1] = -0.4;
  check.matrix[2][2] = 0;
  check.matrix[2][3] = -0.6;
  check.matrix[3][0] = -1;
  check.matrix[3][1] = 0.2;
  check.matrix[3][2] = 0;
  check.matrix[3][3] = 0.8;

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix6) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0}, check = {0, 0, 0};
  s21_create_matrix(4, 4, &matrix);
  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = 6;
  matrix.matrix[0][2] = 4;
  matrix.matrix[0][3] = 2;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 4;
  matrix.matrix[1][3] = 6;
  matrix.matrix[2][0] = 2;
  matrix.matrix[2][1] = -4;
  matrix.matrix[2][2] = 2;
  matrix.matrix[2][3] = 4;
  matrix.matrix[3][0] = -4;
  matrix.matrix[3][1] = -2;
  matrix.matrix[3][2] = -4;
  matrix.matrix[3][3] = -4;

  s21_create_matrix(4, 4, &check);
  check.matrix[0][0] = -7;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = -6;
  check.matrix[0][3] = -11;
  check.matrix[1][0] = -1;
  check.matrix[1][1] = 0;
  check.matrix[1][2] = -1;
  check.matrix[1][3] = -1.5;
  check.matrix[2][0] = 10;
  check.matrix[2][1] = 1;
  check.matrix[2][2] = 8.5;
  check.matrix[2][3] = 15;
  check.matrix[3][0] = -2.5;
  check.matrix[3][1] = 0;
  check.matrix[3][2] = -2;
  check.matrix[3][3] = -3.5;

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix7) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 4;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 2;
  matrix.matrix[1][0] = 6;
  matrix.matrix[1][1] = NAN;
  matrix.matrix[1][2] = 4;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = -2;
  matrix.matrix[2][2] = -3;

  ck_assert_int_eq(s21_inverse_matrix(&matrix, &result), ERROR_CALCULATION);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_s21_inverse_matrix() {
  Suite *s = suite_create("inverse_matrix");
  TCase *tc = tcase_create("inverse_matrix_tc");

  tcase_add_test(tc, s21_inverse_matrix1);
  tcase_add_test(tc, s21_inverse_matrix2);
  tcase_add_test(tc, s21_inverse_matrix3);
  tcase_add_test(tc, s21_inverse_matrix4);
  tcase_add_test(tc, s21_inverse_matrix5);
  tcase_add_test(tc, s21_inverse_matrix6);
  tcase_add_test(tc, s21_inverse_matrix7);

  suite_add_tcase(s, tc);
  return s;
}