#include "s21_tests.h"

#include <limits.h>
int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {s21_strlen_tests(),     s21_memchr_tests(),
                              s21_strncat_tests(),    s21_memcmp_tests(),
                              s21_strncpy_tests(),    s21_strcspn_tests(),
                              s21_strerror_tests(),   s21_strpbrk_tests(),
                              s21_strchr_tests(),     s21_strncmp_tests(),
                              s21_strrchr_tests(),    s21_strstr_tests(),
                              s21_strtok_tests(),     s21_memset_tests(),
                              s21_memcpy_tests(),     s21_to_upper_tests(),
                              s21_to_lower_tests(),   s21_insert_tests(),
                              s21_trim_tests(),       test_sprintf_c(),
                              test_sprintf_d(),       test_sprintf_f(),
                              test_sprintf_s(),       test_sprintf_u(),
                              test_sprintf_percent(), S21_NULL};

  for (int i = 0; s21_string_test[i] != S21_NULL; i++) {
    SRunner *sr = S21_NULL;
    sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed == 0 ? 0 : 1;
}
