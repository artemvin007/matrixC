#include "s21_matrix_test.h"

START_TEST(s21_calc_complements1) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(0, -2, &matrix);
  ck_assert_int_eq(s21_calc_complements(&matrix, &result),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements2) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(1, 11, &matrix1);
  ck_assert_int_eq(s21_calc_complements(&matrix1, &matrix2), ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_calc_complements3) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(1, 1, &matrix1);
  ck_assert_int_eq(s21_calc_complements(&matrix1, &matrix2), ERROR_CALCULATION);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_calc_complements4) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(5, 5, &matrix);

  matrix.matrix[0][0] = 2;
  matrix.matrix[0][1] = 0.3;
  matrix.matrix[0][2] = 2.3;
  matrix.matrix[0][3] = -1;
  matrix.matrix[0][4] = -0.4;
  matrix.matrix[1][0] = 0.2;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 2;
  matrix.matrix[1][3] = 6;
  matrix.matrix[1][4] = 8;
  matrix.matrix[2][0] = 9;
  matrix.matrix[2][1] = -5;
  matrix.matrix[2][2] = -0.5;
  matrix.matrix[2][3] = 0.4;
  matrix.matrix[2][4] = 0.6;
  matrix.matrix[3][0] = 7;
  matrix.matrix[3][1] = 2;
  matrix.matrix[3][2] = 7;
  matrix.matrix[3][3] = 2;
  matrix.matrix[3][4] = 9;
  matrix.matrix[4][0] = -3;
  matrix.matrix[4][1] = -5;
  matrix.matrix[4][2] = -1;
  matrix.matrix[4][3] = 2;
  matrix.matrix[4][4] = -2;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(5, 5, &check);
  check.matrix[0][0] = 756.6;
  check.matrix[0][1] = 1070.48;
  check.matrix[0][2] = 1569.6;
  check.matrix[0][3] = 2085.34;
  check.matrix[0][4] = -2510.56;
  check.matrix[1][0] = 317.04;
  check.matrix[1][1] = 578.9;
  check.matrix[1][2] = 69.48;
  check.matrix[1][3] = 1250.41;
  check.matrix[1][4] = -707.14;
  check.matrix[2][0] = 476.4;
  check.matrix[2][1] = 16.6;
  check.matrix[2][2] = -291.96;
  check.matrix[2][3] = 378.8;
  check.matrix[2][4] = -231.32;
  check.matrix[3][0] = -350.52;
  check.matrix[3][1] = -602.048;
  check.matrix[3][2] = 137.88;
  check.matrix[3][3] = -963.796;
  check.matrix[3][4] = 998.164;
  check.matrix[4][0] = -317.58;
  check.matrix[4][1] = -602.732;
  check.matrix[4][2] = 496.872;
  check.matrix[4][3] = 361.13;
  check.matrix[4][4] = -85.76;

  ck_assert_int_eq(s21_calc_complements(&matrix, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements5) {
  matrix_t matrix = {0, 0, 0}, result = {0, 0, 0};
  s21_create_matrix(3, 3, &matrix);
  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[1][1] = 4;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 2;
  matrix.matrix[2][2] = 1;

  matrix_t check = {0, 0, 0};
  s21_create_matrix(3, 3, &check);

  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  ck_assert_int_eq(s21_calc_complements(&matrix, &result), CODE_OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&matrix);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_s21_calc_complements() {
  Suite *s = suite_create("calc_complements");
  TCase *tc = tcase_create("calc_complements_tc");

  tcase_add_test(tc, s21_calc_complements1);
  tcase_add_test(tc, s21_calc_complements2);
  tcase_add_test(tc, s21_calc_complements3);
  tcase_add_test(tc, s21_calc_complements4);
  tcase_add_test(tc, s21_calc_complements5);

  suite_add_tcase(s, tc);
  return s;
}