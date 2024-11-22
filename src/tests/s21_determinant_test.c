#include "s21_matrix_test.h"

START_TEST(s21_determinant1) {
  int size = 1;
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);
  matrix.matrix[0][0] = 673.23;
  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq(673.23, result);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant2) {
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(0, 4, &matrix);
  ck_assert_int_eq(ERROR_INCORRECT_MATRIX, s21_determinant(&matrix, &result));
}
END_TEST

START_TEST(s21_determinant3) {
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(5, 4, &matrix);
  ck_assert_int_eq(ERROR_CALCULATION, s21_determinant(&matrix, &result));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant4) {
  int size = 2;
  double result = 0, check = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);
    }
  }
  check = matrix.matrix[0][0] * matrix.matrix[1][1] -
          matrix.matrix[1][0] * matrix.matrix[0][1];
  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq(check, result);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant5) {
  int size = 5;
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);
  matrix.matrix[0][0] = 43.3;
  matrix.matrix[0][1] = 1;
  matrix.matrix[0][2] = 23;
  matrix.matrix[0][3] = 0;
  matrix.matrix[0][4] = 0.22;
  matrix.matrix[1][0] = 54.2;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 43;
  matrix.matrix[1][3] = 5.45;
  matrix.matrix[1][4] = 0.11;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 0.3;
  matrix.matrix[2][2] = 5;
  matrix.matrix[2][3] = 654;
  matrix.matrix[2][4] = 4.34;
  matrix.matrix[3][0] = 2;
  matrix.matrix[3][1] = 0.54;
  matrix.matrix[3][2] = 6;
  matrix.matrix[3][3] = 0;
  matrix.matrix[3][4] = 55.3;
  matrix.matrix[4][0] = 4;
  matrix.matrix[4][1] = 0.434;
  matrix.matrix[4][2] = 8;
  matrix.matrix[4][3] = 65.33;
  matrix.matrix[4][4] = 2;

  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq_tol(8182890.618145, result, 1e-6);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant6) {
  int size = 3;
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);
  matrix.matrix[0][0] = 43.3;
  matrix.matrix[0][1] = 1;
  matrix.matrix[0][2] = 23;
  matrix.matrix[1][0] = 54.2;
  matrix.matrix[1][1] = 3;
  matrix.matrix[1][2] = 43;
  matrix.matrix[2][0] = 5;
  matrix.matrix[2][1] = 0.3;
  matrix.matrix[2][2] = 5;
  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq_tol(63.91, result, 1e-6);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant7) {
  int size = 3;
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);
  matrix.matrix[0][0] = 55;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 54;
  matrix.matrix[1][0] = 3;
  matrix.matrix[1][1] = 89;
  matrix.matrix[1][2] = 2;
  matrix.matrix[2][0] = 3;
  matrix.matrix[2][1] = 4;
  matrix.matrix[2][2] = 6;
  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq_tol(15136, result, 1e-6);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_determinant8) {
  int size = 4;
  double result = 0;
  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(size, size, &matrix);
  matrix.matrix[0][0] = 3;
  matrix.matrix[0][1] = 76;
  matrix.matrix[0][2] = 2;
  matrix.matrix[0][3] = 256;
  matrix.matrix[1][0] = 2;
  matrix.matrix[1][1] = 76;
  matrix.matrix[1][2] = 2;
  matrix.matrix[1][3] = 3;
  matrix.matrix[2][0] = 45;
  matrix.matrix[2][1] = 5;
  matrix.matrix[2][2] = 8;
  matrix.matrix[2][3] = 0;
  matrix.matrix[3][0] = 11;
  matrix.matrix[3][1] = 9;
  matrix.matrix[3][2] = 8;
  matrix.matrix[3][3] = 7;
  ck_assert_int_eq(CODE_OK, s21_determinant(&matrix, &result));
  ck_assert_double_eq_tol(5073198, result, 1e-6);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *suite_s21_determinant() {
  Suite *s = suite_create("determinant");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, s21_determinant1);
  tcase_add_test(tc, s21_determinant2);
  tcase_add_test(tc, s21_determinant3);
  tcase_add_loop_test(tc, s21_determinant4, 0, 100);
  tcase_add_test(tc, s21_determinant5);
  tcase_add_test(tc, s21_determinant6);
  tcase_add_test(tc, s21_determinant7);
  tcase_add_test(tc, s21_determinant8);

  suite_add_tcase(s, tc);
  return s;
}