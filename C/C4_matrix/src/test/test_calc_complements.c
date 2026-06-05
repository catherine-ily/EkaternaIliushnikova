#include "tests.h"

START_TEST(test_s21_calc_complements0) {
  matrix_t matrix_1;
  int size = 1;

  int code_create = s21_create_matrix(size, size, &matrix_1);
  matrix_1.matrix[0][0] = 3;

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, OK);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements1) {
  matrix_t matrix_1;
  int rows = 1;
  int cols = 3;

  int code_create = s21_create_matrix(rows, cols, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_calc_complements2) {
  matrix_t matrix_1;
  int rows = 3;
  int cols = 1;

  int code_create = s21_create_matrix(rows, cols, &matrix_1);
  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[2][0] = 3;

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_calc_complements3) {
  matrix_t result;
  int code_calc = s21_calc_complements(NULL, &result);

  ck_assert_int_eq(code_calc, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_calc_complements4) {
  int rows = 5;
  int cols = 5;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {-51.81, 21.82,  45.3, 29.7, 3.0,  -0.4, -19.38, 0.96, 26.3,
                     -0.5,   -0.72,  -0.8, -0.7, 0.78, 0.1,  -83.0,  -1.0, 10.0,
                     -1.0,   -18.77, 5.8,  8.4,  35.0, -0.7, -0.7};
  s21_fill_matrix(values, &matrix_1);

  int code_calc = s21_calc_complements(&matrix_1, NULL);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_calc_complements5) {
  int rows = 1;
  int cols = 3;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {37.0, 1.0, 0.6};
  s21_fill_matrix(values, &matrix_1);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_calc_complements6) {
  int rows = 3;
  int cols = 1;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {37.0, 1.0, 0.6};
  s21_fill_matrix(values, &matrix_1);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_calc_complements7) {
  int rows = 1;
  int cols = 1;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {37.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_calc, OK);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements8) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {50.0, -7.8, 0.44, 8.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {7.999999999999998, -0.44, 7.800000000000002,
                              49.99999999999999};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements9) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {0.0, -0.2, -1.0, -1.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {-1.0, 1.0, 0.2, 0.0};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements10) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {-0.57, 34.12, -2.12, 0.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {0.0, 2.12, -34.12, -0.57};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements11) {
  int rows = 3;
  int cols = 3;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {-0.12, -13.8, 0.6, -2.5, 4.5, -0.5, 80.8, 1.0, -7.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {-31.0,    -57.90, -366.10, -96,   -47.640,
                              -1114.92, 4.20,   -1.56,   -35.04};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements12) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {-0.6, 0.79, 0.55, -1.0};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {-1.0, -0.55, -0.79, -0.6};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements13) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {-0.01, 3.0, -0.0, 0.7};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {0.7, -0.0, -3.0, -0.010};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements14) {
  int rows = 2;
  int cols = 2;

  matrix_t matrix_1;
  int code_create = s21_create_matrix(rows, cols, &matrix_1);

  double values[] = {6.4, 0.0, -3.7, -0.98};
  s21_fill_matrix(values, &matrix_1);

  matrix_t expected;
  int code_create_expected = s21_create_matrix(cols, rows, &expected);

  double expected_values[] = {-0.98, 3.70, -0.0, 6.4};
  s21_fill_matrix(expected_values, &expected);

  matrix_t result_matrix;
  int code_calc = s21_calc_complements(&matrix_1, &result_matrix);

  ck_assert_int_eq(code_create, OK);
  ck_assert_int_eq(code_create_expected, OK);
  ck_assert_int_eq(code_calc, OK);

  ck_assert_int_eq(s21_eq_matrix(&result_matrix, &expected), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result_matrix);
}
END_TEST

Suite *calc_complements_suite() {
  Suite *suite = suite_create("calc_complements_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_calc_complements0);
  tcase_add_test(tc_core, test_s21_calc_complements1);
  tcase_add_test(tc_core, test_s21_calc_complements2);
  tcase_add_test(tc_core, test_s21_calc_complements3);
  tcase_add_test(tc_core, test_s21_calc_complements4);
  tcase_add_test(tc_core, test_s21_calc_complements5);
  tcase_add_test(tc_core, test_s21_calc_complements6);
  tcase_add_test(tc_core, test_s21_calc_complements7);
  tcase_add_test(tc_core, test_s21_calc_complements8);
  tcase_add_test(tc_core, test_s21_calc_complements9);
  tcase_add_test(tc_core, test_s21_calc_complements10);
  tcase_add_test(tc_core, test_s21_calc_complements11);
  tcase_add_test(tc_core, test_s21_calc_complements12);
  tcase_add_test(tc_core, test_s21_calc_complements13);
  tcase_add_test(tc_core, test_s21_calc_complements14);

  suite_add_tcase(suite, tc_core);
  return suite;
}
