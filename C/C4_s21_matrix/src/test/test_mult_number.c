#include "tests.h"

START_TEST(test_s21_mult_number0) {
  double number = 2.0;

  matrix_t s21_result;
  int return_code_mult_number = s21_mult_number(NULL, number, &s21_result);
  ck_assert_int_eq(return_code_mult_number, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_mult_number1) {
  double number = NAN;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(1, 1, &matrix_1);
  matrix_1.matrix[0][0] = 1.0;

  matrix_t s21_result = {0};
  int return_code_mult_number = s21_mult_number(&matrix_1, number, &s21_result);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_mult_number, CALCULATION_ERROR);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&s21_result);
}
END_TEST

START_TEST(test_s21_mult_number2) {
  int input_rows = 4;
  int input_columns = 2;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(input_rows, input_columns, &matrix_1);
  double data1[] = {-230.482, 7.999574, 1.0,           -0.346,
                    549.262,  10.1641,  -722642.20198, 180.6100166};
  s21_fill_matrix(data1, &matrix_1);

  double number = -87.88;
  int return_code_mult_number = s21_mult_number(&matrix_1, number, NULL);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_mult_number, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(test_s21_mult_number3) {
  int input_rows = 3;
  int input_columns = 2;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(input_rows, input_columns, &matrix_1);
  double data1[] = {5339.2, 58.2041459, 34145.25904,
                    5.445,  6.2311,     3894.1534703};
  s21_fill_matrix(data1, &matrix_1);

  double number = 78.86;

  matrix_t expected_result;
  int return_code_3 =
      s21_create_matrix(input_rows, input_columns, &expected_result);
  double data_expected_result[] = {421049.312,      4589.978945674,
                                   2692695.1278944, 429.39270,
                                   491.384546,      307092.942667858};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int return_code_mult_number = s21_mult_number(&matrix_1, number, &s21_result);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_3, OK);
  ck_assert_int_eq(return_code_mult_number, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_number4) {
  int input_rows = 5;
  int input_columns = 10;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(input_rows, input_columns, &matrix_1);
  double data1[] = {
      91347.19,    31.3509154,     -13.9476,   2.8,           -3.2012,
      26.4528,     74132.7577431,  1.9078,     736958.2,      0.88,
      -529913.096, -600848.2406,   8.045,      -258.830708,   0.846881,
      3.6051139,   -4466.75,       7.0,        -6998.6751743, -2929.65902,
      -727118.0,   -807000.0,      -3.523,     74583.800312,  84263.520696,
      -167.787,    27768.3458043,  -0.18,      -572.0,        18337.986,
      -515.21132,  -124292.76,     -253547.0,  54.7038278,    258.16,
      43.2488463,  189095.9958237, 1.0,        1704.904,      -77.0922144,
      5833.836,    -8067.0,        96.0,       -90.0888,      96.7198,
      3.0,         -6.82,          6092.39456, -9754.6,       0.575447};
  s21_fill_matrix(data1, &matrix_1);

  double number = -1.0;

  matrix_t expected_result;
  int return_code_3 =
      s21_create_matrix(input_rows, input_columns, &expected_result);
  double data_expected_result[] = {
      -91347.190,       -31.35091540, 13.94760,        -2.80,
      3.20120,          -26.45280,    -74132.75774310, -1.90780,
      -736958.20,       -0.880,       529913.0960,     600848.24060,
      -8.0450,          258.8307080,  -0.8468810,      -3.60511390,
      4466.750,         -7.00,        6998.67517430,   2929.659020,
      727118.00,        807000.00,    3.5230,          -74583.8003120,
      -84263.5206960,   167.7870,     -27768.34580430, 0.180,
      572.00,           -18337.9860,  515.211320,      124292.760,
      253547.00,        -54.70382780, -258.160,        -43.24884630,
      -189095.99582370, -1.00,        -1704.9040,      77.09221440,
      -5833.8360,       8067.00,      -96.00,          90.08880,
      -96.71980,        -3.00,        6.820,           -6092.394560,
      9754.60,          -0.5754470};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int return_code_mult_number = s21_mult_number(&matrix_1, number, &s21_result);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_3, OK);
  ck_assert_int_eq(return_code_mult_number, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_number5) {
  int input_rows = 4;
  int input_columns = 2;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(input_rows, input_columns, &matrix_1);
  double data1[] = {-230.482, 7.999574, 1.0,           -0.346,
                    549.262,  10.1641,  -722642.20198, 180.6100166};
  s21_fill_matrix(data1, &matrix_1);

  double number = -87.88;

  matrix_t expected_result;
  int return_code_3 =
      s21_create_matrix(input_rows, input_columns, &expected_result);
  double data_expected_result[] = {
      20254.75816,  -703.00256312, -87.880,          30.40648,
      -48269.14456, -893.221108,   63505796.7100024, -15872.008258808};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int return_code_mult_number = s21_mult_number(&matrix_1, number, &s21_result);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_3, OK);
  ck_assert_int_eq(return_code_mult_number, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

START_TEST(test_s21_mult_number6) {
  int input_rows = 1;
  int input_columns = 2;

  matrix_t matrix_1;
  int return_code_1 = s21_create_matrix(input_rows, input_columns, &matrix_1);
  double data1[] = {-78396.50282, -8.21319};
  s21_fill_matrix(data1, &matrix_1);

  double number = -388.0;

  matrix_t expected_result;
  int return_code_3 =
      s21_create_matrix(input_rows, input_columns, &expected_result);
  double data_expected_result[] = {30417843.094160, 3186.717720};
  s21_fill_matrix(data_expected_result, &expected_result);

  matrix_t s21_result;
  int return_code_mult_number = s21_mult_number(&matrix_1, number, &s21_result);

  ck_assert_int_eq(return_code_1, OK);
  ck_assert_int_eq(return_code_3, OK);
  ck_assert_int_eq(return_code_mult_number, OK);

  ck_assert_int_eq(s21_eq_matrix(&s21_result, &expected_result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&s21_result);
  s21_remove_matrix(&expected_result);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *suite = suite_create("mult_number_suite");

  TCase *test_case = tcase_create("tests");

  tcase_add_test(test_case, test_s21_mult_number0);
  tcase_add_test(test_case, test_s21_mult_number1);
  tcase_add_test(test_case, test_s21_mult_number2);
  tcase_add_test(test_case, test_s21_mult_number3);
  tcase_add_test(test_case, test_s21_mult_number4);
  tcase_add_test(test_case, test_s21_mult_number5);
  tcase_add_test(test_case, test_s21_mult_number6);

  suite_add_tcase(suite, test_case);

  return suite;
}
