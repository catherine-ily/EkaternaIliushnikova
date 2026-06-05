#include "tests.h"

START_TEST(test_s21_transpose0) {
  matrix_t result_matrix;
  int code = s21_transpose(NULL, &result_matrix);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_transpose1) {
  int rows = 1;
  int cols = 6;

  matrix_t input_matrix;
  int create_code = s21_create_matrix(rows, cols, &input_matrix);
  double values[] = {-58405.520561, -40.34,  2063.1380588,
                     9486.26,       -57.409, 8160.60715};
  s21_fill_matrix(values, &input_matrix);

  int transpose_code = s21_transpose(&input_matrix, NULL);

  ck_assert_int_eq(create_code, OK);
  ck_assert_int_eq(transpose_code, INCORRECT_MATRIX);

  s21_remove_matrix(&input_matrix);
}
END_TEST

START_TEST(test_s21_transpose2) {
  int rows = 5;
  int cols = 1;

  matrix_t mat_a;
  int c1 = s21_create_matrix(rows, cols, &mat_a);
  double vals[] = {4570.2234401, -208677.6, -1758.082, 800436.043, 28.4};
  s21_fill_matrix(vals, &mat_a);

  matrix_t expected;
  int c2 = s21_create_matrix(cols, rows, &expected);
  double expected_vals[] = {4570.2234401, -208677.6, -1758.082, 800436.043,
                            28.4};
  s21_fill_matrix(expected_vals, &expected);

  matrix_t result;
  int trans_code = s21_transpose(&mat_a, &result);

  ck_assert_int_eq(c1, OK);
  ck_assert_int_eq(c2, OK);
  ck_assert_int_eq(trans_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat_a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose3) {
  int rows = 1;
  int cols = 6;

  matrix_t mat_a;
  int c1 = s21_create_matrix(rows, cols, &mat_a);
  double vals[] = {-58405.520561, -40.34,  2063.1380588,
                   9486.26,       -57.409, 8160.60715};
  s21_fill_matrix(vals, &mat_a);

  matrix_t expected;
  int c2 = s21_create_matrix(cols, rows, &expected);
  double expected_vals[] = {-58405.520561, -40.34,  2063.1380588,
                            9486.26,       -57.409, 8160.60715};
  s21_fill_matrix(expected_vals, &expected);

  matrix_t result;
  int trans_code = s21_transpose(&mat_a, &result);

  ck_assert_int_eq(c1, OK);
  ck_assert_int_eq(c2, OK);
  ck_assert_int_eq(trans_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat_a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose4) {
  int rows = 4;
  int cols = 8;

  matrix_t input;
  int c1 = s21_create_matrix(rows, cols, &input);
  double vals[] = {
      -1918.203347, 2425.3,    -7.401764, 17164.23,   6.13,        -2.4184755,
      -78.4964,     468.5,     -785.5496, 24670.8435, -151.87,     -9525.434,
      -423207.3006, 6.5423595, 0.761178,  133514.0,   3760.853926, 9.6565,
      653550.446,   57.607442, 6864.14,   -317.699,   -7.7,        4.5,
      0.5665,       1.2,       1.9642,    -0.0,       -42.13,      -0.71,
      -0.45,        -51.022};
  s21_fill_matrix(vals, &input);

  matrix_t expected;
  int c2 = s21_create_matrix(cols, rows, &expected);
  double expected_vals[] = {
      -1918.203347, -785.5496, 3760.853926, 0.5665,    2425.3,     24670.8435,
      9.6565,       1.2,       -7.401764,   -151.87,   653550.446, 1.9642,
      17164.23,     -9525.434, 57.607442,   -0.0,      6.13,       -423207.3006,
      6864.14,      -42.13,    -2.4184755,  6.5423595, -317.699,   -0.71,
      -78.4964,     0.761178,  -7.7,        -0.45,     468.5,      133514.0,
      4.5,          -51.022};
  s21_fill_matrix(expected_vals, &expected);

  matrix_t result;
  int trans_code = s21_transpose(&input, &result);

  ck_assert_int_eq(c1, OK);
  ck_assert_int_eq(c2, OK);
  ck_assert_int_eq(trans_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&input);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose5) {
  int rows = 1;
  int cols = 1;

  matrix_t mat;
  int c1 = s21_create_matrix(rows, cols, &mat);
  double val = 267.15142;
  s21_fill_matrix(&val, &mat);

  matrix_t expected;
  int c2 = s21_create_matrix(cols, rows, &expected);
  s21_fill_matrix(&val, &expected);

  matrix_t result;
  int trans_code = s21_transpose(&mat, &result);

  ck_assert_int_eq(c1, OK);
  ck_assert_int_eq(c2, OK);
  ck_assert_int_eq(trans_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_transpose6) {
  int rows = 4;
  int cols = 4;

  matrix_t input;
  int c1 = s21_create_matrix(rows, cols, &input);
  double vals[] = {6.2059,      63539.282356, 257.18696,   -280.35746,
                   3009.195754, 215777.92,    -186078.1,   -90.1205,
                   -278.30699,  21.6906686,   -2274.46567, -790.4,
                   581.19,      16387.441484, 7537.34,     74.94024};
  s21_fill_matrix(vals, &input);

  matrix_t expected;
  int c2 = s21_create_matrix(cols, rows, &expected);
  double expected_vals[] = {
      6.2059,     3009.195754,  -278.30699, 581.19,    63539.282356, 215777.92,
      21.6906686, 16387.441484, 257.18696,  -186078.1, -2274.46567,  7537.34,
      -280.35746, -90.1205,     -790.4,     74.94024};
  s21_fill_matrix(expected_vals, &expected);

  matrix_t result;
  int trans_code = s21_transpose(&input, &result);

  ck_assert_int_eq(c1, OK);
  ck_assert_int_eq(c2, OK);
  ck_assert_int_eq(trans_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&input);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *transpose_suite() {
  Suite *suite = suite_create("transpose_suite");
  TCase *test_case_group;

  test_case_group = tcase_create("MainTests");

  tcase_add_test(test_case_group, test_s21_transpose0);
  tcase_add_test(test_case_group, test_s21_transpose1);
  tcase_add_test(test_case_group, test_s21_transpose2);
  tcase_add_test(test_case_group, test_s21_transpose3);
  tcase_add_test(test_case_group, test_s21_transpose4);
  tcase_add_test(test_case_group, test_s21_transpose5);
  tcase_add_test(test_case_group, test_s21_transpose6);

  suite_add_tcase(suite, test_case_group);

  return suite;
}
