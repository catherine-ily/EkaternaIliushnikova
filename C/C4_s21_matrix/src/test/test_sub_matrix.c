#include "tests.h"

START_TEST(test_s21_sub_matrix0) {
  matrix_t mat1, mat2, result;

  int create_mat1 = s21_create_matrix(1, 2, &mat1);
  double data1[] = {-70057.0, -84401.0};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(1, 1, &mat2);
  double data2[] = {-23053.3520146};
  s21_fill_matrix(data2, &mat2);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, CALCULATION_ERROR);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sub_matrix1) {
  matrix_t mat1, mat2, result;

  int create_mat1 = s21_create_matrix(1, 2, &mat1);
  double data1[] = {-70057.0, -84401.0};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(2, 1, &mat2);
  double data2[] = {-23053.3520146, -40346.042992};
  s21_fill_matrix(data2, &mat2);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, CALCULATION_ERROR);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sub_matrix2) {
  matrix_t mat2, result;

  int create_mat2 = s21_create_matrix(4, 2, &mat2);
  double data2[] = {2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0};
  s21_fill_matrix(data2, &mat2);

  int return_code = s21_sub_matrix(NULL, &mat2, &result);

  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(return_code, INCORRECT_MATRIX);

  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_sub_matrix3) {
  matrix_t mat1, mat2, expected_result, result;

  int create_mat1 = s21_create_matrix(1, 3, &mat1);
  double data1[] = {-0.5307, -203.8286, 83122.8562348};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(1, 3, &mat2);
  double data2[] = {-0.636106, 34.8, -5506.5};
  s21_fill_matrix(data2, &mat2);

  int create_result = s21_create_matrix(1, 3, &expected_result);
  double expected_data[] = {0.105406, -238.6286, 88629.3562348};
  s21_fill_matrix(expected_data, &expected_result);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(create_result, OK);
  ck_assert_int_eq(return_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix4) {
  matrix_t mat1, mat2, expected_result, result;

  int create_mat1 = s21_create_matrix(3, 2, &mat1);
  double data1[] = {7789.247, 2988.4099, -4776.0362481,
                    -9131.2,  0.390429,  -2.0};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(3, 2, &mat2);
  double data2[] = {-26.3827158, -8.53007, 4.18385, 85351.2319025, -6.1, -0.0};
  s21_fill_matrix(data2, &mat2);

  int create_result = s21_create_matrix(3, 2, &expected_result);
  double expected_data[] = {7815.6297158,   2996.93997, -4780.2200981,
                            -94482.4319025, 6.490429,   -2.0};
  s21_fill_matrix(expected_data, &expected_result);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(create_result, OK);
  ck_assert_int_eq(return_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix5) {
  matrix_t mat1, mat2, expected_result, result;

  int create_mat1 = s21_create_matrix(3, 3, &mat1);
  double data1[] = {3047.6,    -52196.0, -0.4,      8.89,    942751.153,
                    2943.1457, 1081.14,  -59403.55, -0.88745};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(3, 3, &mat2);
  double data2[] = {54.3401, -0.586885,     -16851.7166, 857876.1462, -0.769759,
                    794.1,   907087.517357, -37570.434,  -147083.8};
  s21_fill_matrix(data2, &mat2);

  int create_result = s21_create_matrix(3, 3, &expected_result);
  double expected_data[] = {2993.2599,      -52195.413115, 16851.3166,
                            -857867.2562,   942751.922759, 2149.0457,
                            -906006.377357, -21833.116,    147082.91255};
  s21_fill_matrix(expected_data, &expected_result);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(create_result, OK);
  ck_assert_int_eq(return_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix6) {
  matrix_t mat1, mat2, expected_result, result;

  int create_mat1 = s21_create_matrix(1, 8, &mat1);
  double data1[] = {318209.658674, 4.4738,  42.6215, 5.72,
                    -8.0,          0.08691, 9.6633,  -771.4591};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(1, 8, &mat2);
  double data2[] = {158696.35893, 89.8172948, 538094.46, -0.879771,
                    -5.346,       0.23637,    728.0,     -90241.22};
  s21_fill_matrix(data2, &mat2);

  int create_result = s21_create_matrix(1, 8, &expected_result);
  double expected_data[] = {159513.299744, -85.3434948, -538051.8385,
                            6.599771,      -2.654,      -0.14946,
                            -718.3367,     89469.7609};
  s21_fill_matrix(expected_data, &expected_result);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(create_result, OK);
  ck_assert_int_eq(return_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix7) {
  matrix_t mat1, mat2, expected_result, result;

  int create_mat1 = s21_create_matrix(2, 2, &mat1);
  double data1[] = {35098.86789, 3.737, 4.0, -42.0};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(2, 2, &mat2);
  double data2[] = {-1122.7, -2.7, -108.7, 0.0};
  s21_fill_matrix(data2, &mat2);

  int create_result = s21_create_matrix(2, 2, &expected_result);
  double expected_data[] = {36221.56789, 6.437, 112.7, -42.0};
  s21_fill_matrix(expected_data, &expected_result);

  int return_code = s21_sub_matrix(&mat1, &mat2, &result);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(create_result, OK);
  ck_assert_int_eq(return_code, OK);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected_result), SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
  s21_remove_matrix(&expected_result);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sub_matrix_suite(void) {
  Suite *s = suite_create("sub_matrix_suite");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sub_matrix0);
  tcase_add_test(tc_core, test_s21_sub_matrix1);
  tcase_add_test(tc_core, test_s21_sub_matrix2);
  tcase_add_test(tc_core, test_s21_sub_matrix3);
  tcase_add_test(tc_core, test_s21_sub_matrix4);
  tcase_add_test(tc_core, test_s21_sub_matrix5);
  tcase_add_test(tc_core, test_s21_sub_matrix6);
  tcase_add_test(tc_core, test_s21_sub_matrix7);

  suite_add_tcase(s, tc_core);
  return s;
}
