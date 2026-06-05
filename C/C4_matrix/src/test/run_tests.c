#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "tests.h"

void run_suite(Suite *suite, int *total_run, int *total_failed);

int main(void) {
  int total_run = 0;
  int total_failed = 0;

  Suite *suites[] = {
      create_matrix_suite(), remove_matrix_suite(),    eq_matrix_suite(),
      mult_number_suite(),   calc_complements_suite(), mult_matrix_suite(),
      determinant_suite(),   sum_matrix_suite(),       sub_matrix_suite(),
      transpose_suite(),     inverse_matrix_suite(),   NULL};

  for (Suite **s = suites; *s != NULL; s++) {
    run_suite(*s, &total_run, &total_failed);
  }

  printf("\n======== Test Summary ========\n");
  printf("Total tests run:\t%d\n", total_run);
  printf("Total tests passed:\t%d\n", total_run - total_failed);
  printf("Total tests failed:\t%d\n", total_failed);
  printf("==============================\n");

  return (total_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void run_suite(Suite *suite, int *total_run, int *total_failed) {
  SRunner *sr = srunner_create(suite);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  *total_run += srunner_ntests_run(sr);
  *total_failed += srunner_ntests_failed(sr);

  srunner_free(sr);
}
