#include "tests.h"

START_TEST(test_s21_eq_matrix0) {
  int rows = 2;
  int columns = 4;
  matrix_t mat1, mat2;

  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  int create_mat2 = s21_create_matrix(rows, columns, &mat2);

  double data[] = {3.1234567, 3.1234567, 3.1234567, 3.1234567,
                   3.1234567, 3.1234567, 3.1234567, 3.1234567};
  s21_fill_matrix(data, &mat1);
  s21_fill_matrix(data, &mat2);

  int comparison_result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(comparison_result, SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix1) {
  int size = 3;
  matrix_t mat1, mat2;

  int create_mat1 = s21_create_matrix(size, size, &mat1);
  int create_mat2 = s21_create_matrix(size, size, &mat2);

  double data[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
  s21_fill_matrix(data, &mat1);
  s21_fill_matrix(data, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix2) {
  int rows = 3, columns = 2;
  matrix_t mat1, mat2;

  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {1.00000001, 1.00000001, 1.000000,
                    1.00000007, 1.00000009, 1.000000};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {1.0000000, 1.00000009, 1.00000009,
                    1.0000000, 1.0000000,  1.0000000838};
  s21_fill_matrix(data2, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(result, SUCCESS);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix3) {
  int rows = 4;
  int columns = 2;
  matrix_t mat1, mat2;

  int create_mat1 = s21_create_matrix(rows, columns, &mat1);
  double data1[] = {5.000002, 1.0, 1.0, 1.0, 1.0, 5.0, 1.0, 1.0};
  s21_fill_matrix(data1, &mat1);

  int create_mat2 = s21_create_matrix(rows, columns, &mat2);
  double data2[] = {5.000001, 1.0, 1.0, 1.0, 1.0, 5.0, 1.0, 1.0};
  s21_fill_matrix(data2, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix4) {
  int size = 2;
  matrix_t mat1, mat2;

  int create_mat1 = s21_create_matrix(size, size, &mat1);
  int create_mat2 = s21_create_matrix(size, size, &mat2);

  double data1[] = {2.1234567, 1.0, 1.0, 1.0};
  double data2[] = {2.1234559999, 1.0, 1.0, 1.0};
  s21_fill_matrix(data1, &mat1);
  s21_fill_matrix(data2, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix5) {
  double data[] = {1.0, 1.0, 1.0, 1.0};

  matrix_t mat1;
  int rows1 = 2, columns1 = 2;
  int create_mat1 = s21_create_matrix(rows1, columns1, &mat1);
  s21_fill_matrix(data, &mat1);

  matrix_t mat2;
  int rows2 = 1, columns2 = 4;
  int create_mat2 = s21_create_matrix(rows2, columns2, &mat2);
  s21_fill_matrix(data, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat1, OK);
  ck_assert_int_eq(create_mat2, OK);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(test_s21_eq_matrix6) {
  int rows = 2;
  int columns = 1;
  matrix_t mat;

  int create_mat = s21_create_matrix(rows, columns, &mat);
  double data[] = {-3.1234567, 3.1234567};
  s21_fill_matrix(data, &mat);

  int result = s21_eq_matrix(&mat, NULL);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_eq_matrix7) {
  int rows = 2;
  int columns = 1;
  matrix_t mat1 = {0}, mat2;

  int create_mat = s21_create_matrix(rows, columns, &mat2);
  double data[] = {-0.12345678, -0.1234567};
  s21_fill_matrix(data, &mat2);

  int result = s21_eq_matrix(&mat1, &mat2);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(result, FAILURE);

  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

Suite *eq_matrix_suite() {
  Suite *suite = suite_create("eq_matrix_suite");
  TCase *test_case = tcase_create("Core Functions");

  tcase_add_test(test_case, test_s21_eq_matrix0);
  tcase_add_test(test_case, test_s21_eq_matrix1);
  tcase_add_test(test_case, test_s21_eq_matrix2);
  tcase_add_test(test_case, test_s21_eq_matrix3);
  tcase_add_test(test_case, test_s21_eq_matrix4);
  tcase_add_test(test_case, test_s21_eq_matrix5);
  tcase_add_test(test_case, test_s21_eq_matrix6);
  tcase_add_test(test_case, test_s21_eq_matrix7);

  suite_add_tcase(suite, test_case);
  return suite;
}