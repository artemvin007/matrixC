#include "s21_matrix_test.h"

int main() {
  int failed = 0;
  Suite *s[] = {
      suite_s21_create_matrix(),    suite_s21_sub_matrix(),
      suite_s21_sum_matrix(),       suite_s21_eq_matrix(),
      suite_s21_mult_number(),      suite_s21_mult_matrix(),
      suite_s21_transpose(),        suite_s21_determinant(),
      suite_s21_calc_complements(), suite_s21_inverse_matrix(),
  };

  for (size_t i = 0; i < sizeof(s) / sizeof(Suite *); i++) {
    SRunner *runner = srunner_create(s[i]);
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}