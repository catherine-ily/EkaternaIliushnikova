#ifndef TESTS_H_
#define TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

void run_suite(Suite *current_suite, int *total_number_run,
               int *total_number_failed);

void s21_helper_matrix_fill(double input[], matrix_t *output);

Suite *create_matrix_suite();
Suite *remove_matrix_suite();
Suite *eq_matrix_suite();
Suite *sum_matrix_suite();
Suite *sub_matrix_suite();
Suite *mult_number_suite();
Suite *mult_matrix_suite();
Suite *transpose_suite();
Suite *determinant_suite();
Suite *inverse_matrix_suite();
Suite *calc_complements_suite();

#endif  // TESTS_H_
