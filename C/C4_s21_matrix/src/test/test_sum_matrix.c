#include "tests.h"

START_TEST(test_s21_sum_matrix0) {
  int rows = 1;
  int columns = 2;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {-70057.0, -84401.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(1, 1, &mat2);
  double data2[] = {-23053.3520146};
  s21_fill_matrix(data2, &mat2);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, CALCULATION_ERROR);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sum_matrix1) {
  int rows = 1;
  int columns = 2;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {-70057.0, -84401.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(2, 1, &mat2);
  double data2[] = {-23053.3520146, -40346.042992};
  s21_fill_matrix(data2, &mat2);

  matrix_t res;
  int return_code = s21_sum_matrix(&mat1, &mat2, &res);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, CALCULATION_ERROR);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sum_matrix2) {
  int rows = 4;
  int columns = 2;

  matrix_t matrix;
  int create_mat = s21_create_matrix(rows, columns, &matrix);
  double data[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
  s21_fill_matrix(data, &matrix);

  matrix_t result;
  int return_code = s21_sum_matrix(NULL, &matrix, &result);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(return_code, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_sum_matrix3) {
  int rows = 4;
  int columns = 2;

  matrix_t matrix;
  int create_mat = s21_create_matrix(rows, columns, &matrix);
  double data[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  s21_fill_matrix(data, &matrix);

  matrix_t res;
  int return_code = s21_sum_matrix(&matrix, NULL, &res);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(return_code, INCORRECT_MATRIX);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_sum_matrix4) {
  int rows = 4;
  int columns = 2;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
  s21_fill_matrix(data2, &mat2);

  int return_code = s21_sum_matrix(&mat1, &mat2, NULL);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, INCORRECT_MATRIX);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sum_matrix5) {
  int rows = 4;
  int columns = 2;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sum_matrix6) {
  int rows = 5;
  int columns = 1;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {-47365.9723, -655.34, -1970.29, -5.50212, 82556.36697};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {4.0, -535771.87, 6993.7, 87727.8346443, -6.6};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {-47361.9723, -536427.21, 5023.41, 87722.3325243,
                       82549.76697};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sum_matrix7) {
  int rows = 1;
  int columns = 5;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {-8774.6112726, 907427.42, 2.0, 0.0, 1611.6};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {-9456.0, -8969.4, 4008.3939428, -4520.7587, 4969.121541};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {-18230.6112726, 898458.02, 4010.3939428, -4520.7587,
                       6580.721541};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sum_matrix8) {
  int rows = 2;
  int columns = 2;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {-71496.935, -50398.9451589, 0.0, -23.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {75.0, 7.71, -0.8853413, 23.0};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {-71421.935, -50391.2351589, -0.8853413, 0.0};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sum_matrix9) {
  int rows = 2;
  int columns = 3;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(test_s21_sum_matrix10) {
  int rows = 2;
  int columns = 3;

  matrix_t mat1;
  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  s21_fill_matrix(data1, &mat1);

  matrix_t mat2;
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
  s21_fill_matrix(data2, &mat2);

  matrix_t expected;
  int return_code_exp = s21_create_matrix(rows, columns, &expected);
  double data_exp[] = {7.0, 7.0, 7.0, 7.0, 7.0, 7.0};
  s21_fill_matrix(data_exp, &expected);

  matrix_t result;
  int return_code = s21_sum_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code_exp, OK);
  ck_assert_int_eq(return_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *sum_matrix_suite() {
  Suite *s = suite_create("sum_matrix_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sum_matrix0);
  tcase_add_test(tc_core, test_s21_sum_matrix1);
  tcase_add_test(tc_core, test_s21_sum_matrix2);
  tcase_add_test(tc_core, test_s21_sum_matrix3);
  tcase_add_test(tc_core, test_s21_sum_matrix4);
  tcase_add_test(tc_core, test_s21_sum_matrix5);
  tcase_add_test(tc_core, test_s21_sum_matrix6);
  tcase_add_test(tc_core, test_s21_sum_matrix7);
  tcase_add_test(tc_core, test_s21_sum_matrix8);
  tcase_add_test(tc_core, test_s21_sum_matrix9);
  tcase_add_test(tc_core, test_s21_sum_matrix10);

  suite_add_tcase(s, tc_core);

  return s;
}
