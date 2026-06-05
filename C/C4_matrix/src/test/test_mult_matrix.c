#include "tests.h"

START_TEST(test_s21_mult_matrix0) {
  int rows = 3;
  int columns = 4;

  matrix_t matrix;
  int create_mat = s21_create_matrix(rows, columns, &matrix);
  double data2[] = {-627.6, 17.0,   -1.56,  4.099,   -474.2, 3.4,
                    -74.0,  1786.0, 5888.0, -6485.0, 11.7,   0.5};
  s21_fill_matrix(data2, &matrix);

  matrix_t s21_result;
  int create_mat_mult_matrix = s21_mult_matrix(NULL, &matrix, &s21_result);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(create_mat_mult_matrix, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_mult_matrix1) {
  int columns = 3;
  int rows = 1;

  matrix_t matrix_1;
  int create_mat_1 = s21_create_matrix(rows, columns, &matrix_1);
  double data1[] = {588.213, -0.0, -0.1};
  s21_fill_matrix(data1, &matrix_1);

  matrix_t s21_result;
  int create_mat_mult_matrix = s21_mult_matrix(&matrix_1, NULL, &s21_result);

  ck_assert_int_eq(create_mat_1, OK);
  ck_assert_int_eq(create_mat_mult_matrix, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_mult_matrix2) {
  int columns = 3;
  int rows = 1;
  int second_columns = 4;

  matrix_t matrix_1;
  int create_mat_1 = s21_create_matrix(rows, columns, &matrix_1);
  double data1[] = {588.213, -0.032, -0.1};
  s21_fill_matrix(data1, &matrix_1);

  matrix_t matrix_2;
  int create_mat_2 = s21_create_matrix(columns, second_columns, &matrix_2);
  double data2[] = {-627.6, 17.0,   -1.56, 4.099,   -474.2, 3.4,
                    -74.0,  1786.0, NAN,   -6485.0, 11.7,   0.5};
  s21_fill_matrix(data2, &matrix_2);

  matrix_t s21_result;
  int create_mat_mult_matrix =
      s21_mult_matrix(&matrix_1, &matrix_2, &s21_result);

  ck_assert_int_eq(create_mat_1, OK);
  ck_assert_int_eq(create_mat_2, OK);
  ck_assert_int_eq(create_mat_mult_matrix, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_s21_mult_matrix3) {
  int columns = 3;
  int rows = 1;
  int second_columns = 4;

  matrix_t matrix_1;
  int create_mat_1 = s21_create_matrix(2, rows, &matrix_1);
  double data1[] = {588.213, -0.1};
  s21_fill_matrix(data1, &matrix_1);

  matrix_t matrix_2;
  int create_mat_2 = s21_create_matrix(columns, second_columns, &matrix_2);
  double data2[] = {-627.6, 17.0,   -1.56,  4.099,   -474.2, 3.4,
                    -74.0,  1786.0, 5888.0, -6485.0, 11.7,   0.5};
  s21_fill_matrix(data2, &matrix_2);

  matrix_t s21_result;
  int create_mat_mult_matrix =
      s21_mult_matrix(&matrix_1, &matrix_2, &s21_result);

  ck_assert_int_eq(create_mat_1, OK);
  ck_assert_int_eq(create_mat_2, OK);
  ck_assert_int_eq(create_mat_mult_matrix, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_s21_mult_matrix4) {
  int columns = 2;
  int rows = 6;
  int second_columns = 2;

  matrix_t matrix_1;
  int create_mat_1 = s21_create_matrix(rows, columns, &matrix_1);
  double data1[] = {-31.11, 0.788, 39.87, -9.0,    -9.048, -0.82,
                    0.41,   0.0,   315.0, 538.926, -38.9,  897.653};
  s21_fill_matrix(data1, &matrix_1);

  matrix_t matrix_2;
  int create_mat_2 = s21_create_matrix(columns, second_columns, &matrix_2);
  double data2[] = {45.23, 8.42, -144.85, -773.99};
  s21_fill_matrix(data2, &matrix_2);

  matrix_t expected_result;
  int create_mat_3 = s21_create_matrix(rows, second_columns, &expected_result);
  double data_expected_result[] = {-1521.24710,   -871.85032,    3106.9701,
                                   7301.6154,     -290.46404,    558.48764,
                                   18.5443,       3.4522,        -63815.98110,
                                   -414471.03474, -131784.48405, -695101.98347};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int create_mat_mult_matrix =
      s21_mult_matrix(&matrix_1, &matrix_2, &s21_result);

  ck_assert_int_eq(create_mat_1, OK);
  ck_assert_int_eq(create_mat_2, OK);
  ck_assert_int_eq(create_mat_3, OK);
  ck_assert_int_eq(create_mat_mult_matrix, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_matrix5) {
  int columns = 2;
  int rows = 3;
  int second_columns = 7;

  matrix_t matrix_1;
  int create_mat_1 = s21_create_matrix(rows, columns, &matrix_1);
  double data1[] = {0.0, -38.0, -37.122, -0.0, 0.0, -3.4};
  s21_fill_matrix(data1, &matrix_1);

  matrix_t matrix_2;
  int create_mat_2 = s21_create_matrix(columns, second_columns, &matrix_2);
  double data2[] = {-391.359, -53.1, -9.551, -3.0,     -87.499, -62.31, 4.0,
                    -64.0,    -7.0,  22.5,   -347.404, -320.06, 374.0,  46.199};
  s21_fill_matrix(data2, &matrix_2);

  matrix_t expected_result;
  int create_mat_3 = s21_create_matrix(rows, second_columns, &expected_result);
  double data_expected_result[] = {
      2432.0000,  266.00,       -855.0000, 13201.3520, 12162.2800, -14212.000,
      -1755.5620, 14528.028798, 1971.1782, 354.552222, 111.3660,   3248.137878,
      2313.07182, -148.4880,    217.6000,  23.80,      -76.5000,   1181.1736,
      1088.2040,  -1271.600,    -157.0766};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int create_mat_mult_matrix =
      s21_mult_matrix(&matrix_1, &matrix_2, &s21_result);

  ck_assert_int_eq(create_mat_1, OK);
  ck_assert_int_eq(create_mat_2, OK);
  ck_assert_int_eq(create_mat_3, OK);
  ck_assert_int_eq(create_mat_mult_matrix, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_matrix6) {
  int rows = 3;
  int columns = 4;

  matrix_t matrix;
  int create_mat = s21_create_matrix(rows, columns, &matrix);
  double data2[] = {-627.6, 17.0,   -1.56,  4.099,   -474.2, 3.4,
                    -74.0,  1786.0, 5888.0, -6485.0, 11.7,   0.5};
  s21_fill_matrix(data2, &matrix);

  int create_mat_mult_matrix = s21_mult_matrix(&matrix, &matrix, NULL);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(create_mat_mult_matrix, INCORRECT_MATRIX);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_mult_matrix7) {
  matrix_t A, B, result;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  double data_1[] = {1, 2, 3, 4};
  double data_2[] = {5, 6, 7, 8};
  s21_fill_matrix(data_1, &A);
  s21_fill_matrix(data_2, &B);

  int create_mat = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(create_mat, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 19.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[0][1], 22.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][0], 43.0, 1e-6);
  ck_assert_double_eq_tol(result.matrix[1][1], 50.0, 1e-6);

  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_matrix_suite(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("suite_mult_matrix");
  tc = tcase_create("mult_matrix_suite");

  tcase_add_test(tc, test_s21_mult_matrix0);
  tcase_add_test(tc, test_s21_mult_matrix1);
  tcase_add_test(tc, test_s21_mult_matrix2);
  tcase_add_test(tc, test_s21_mult_matrix3);
  tcase_add_test(tc, test_s21_mult_matrix4);
  tcase_add_test(tc, test_s21_mult_matrix5);
  tcase_add_test(tc, test_s21_mult_matrix6);
  tcase_add_test(tc, test_s21_mult_matrix7);

  suite_add_tcase(s, tc);
  return s;
}
