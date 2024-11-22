#ifndef S21_MATRIX
#define S21_MATRIX

#define CODE_OK 0
#define ERROR_INCORRECT_MATRIX 1
#define ERROR_CALCULATION 2

#define SUCCESS 1
#define FAILURE 0

#include <math.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
int markup_matrix(int rows, int columns, double **matrix);

void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void just_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void just_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
void just_mult_number(matrix_t *A, double number, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void just_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
void just_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);
void just_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);
void just_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int calc_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_create_minor_matrix(matrix_t *dest, int row_i, int col_i,
                            matrix_t *res);
int minus_one_pow(int i, int j);

int is_matrix_correct(matrix_t *A);
int is_nan_or_inf(const matrix_t *A);
int is_matrix_square(matrix_t *A);

#endif  // S21_MATRIX