#include "s21_matrix_test.h"

START_TEST(s21_eq_matrix1) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(rows, columns, &matrix1);
  s21_create_matrix(rows, columns, &matrix2);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double random_num = (double)rand() / ((double)rand() + 0.1);
      matrix1.matrix[i][j] = random_num;
      matrix2.matrix[i][j] = random_num;
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix2) {
  int rows = 5;
  int columns = 10;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(rows, columns, &matrix1);
  s21_create_matrix(rows, columns, &matrix2);

  matrix1.matrix[0][1] = 3.243321;
  matrix2.matrix[0][1] = 3.243321;
  matrix1.matrix[4][9] = 563478290;
  matrix2.matrix[4][9] = 563478290;

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix3) {
  int rows = 57;
  int columns = 12;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  double random_num = 0;
  s21_create_matrix(rows, columns, &matrix1);
  s21_create_matrix(rows, columns, &matrix2);

  matrix1.matrix[0][1] = 3.243321;
  matrix2.matrix[0][1] = 3.243321;
  matrix1.matrix[4][9] = 563478290;
  matrix2.matrix[4][9] = 563478290;
  random_num = (double)rand() / ((double)rand() + 0.1);
  matrix1.matrix[32][2] = random_num;
  matrix2.matrix[32][2] = random_num;
  random_num = (double)rand() / ((double)rand() + 0.1);
  matrix1.matrix[50][7] = random_num;
  matrix2.matrix[50][7] = random_num;

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), SUCCESS);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix4) {
  int rows = rand() % 100 + 1;
  int columns = rand() % 100 + 1;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(rows, columns, &matrix1);
  s21_create_matrix(rows, columns, &matrix2);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix1.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);
      matrix2.matrix[i][j] = (double)rand() / ((double)rand() + 0.1);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix5) {
  int rows = 57;
  int columns = 12;
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  double random_num = 0;
  s21_create_matrix(rows, columns, &matrix1);
  s21_create_matrix(rows, columns, &matrix2);

  matrix1.matrix[0][1] = 3.243321;
  matrix2.matrix[0][1] = 3.321;
  matrix1.matrix[4][9] = 478290;
  matrix2.matrix[4][9] = 563478290;
  random_num = (double)rand() / ((double)rand() + 0.1);
  matrix1.matrix[32][2] = random_num;
  matrix2.matrix[32][2] = -(random_num);
  random_num = (double)rand() / ((double)rand() + 0.1);
  matrix1.matrix[50][7] = random_num;
  matrix2.matrix[50][7] = 0;

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix6) {
  matrix_t matrix1 = {0, 0, 0}, matrix2 = {0, 0, 0};
  s21_create_matrix(12, 13, &matrix1);
  s21_create_matrix(12, 52, &matrix2);

  ck_assert_int_eq(s21_eq_matrix(&matrix1, &matrix2), FAILURE);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}

Suite *suite_s21_eq_matrix() {
  Suite *s = suite_create("eq_matrix");
  TCase *tc = tcase_create("eq_matrix_tc");

  tcase_add_loop_test(tc, s21_eq_matrix1, 0, 100);
  tcase_add_test(tc, s21_eq_matrix2);
  tcase_add_test(tc, s21_eq_matrix3);
  tcase_add_test(tc, s21_eq_matrix4);
  tcase_add_test(tc, s21_eq_matrix5);
  tcase_add_test(tc, s21_eq_matrix6);

  suite_add_tcase(s, tc);
  return s;
}
