#include "tests.h"

START_TEST(test_s21_remove_matrix0) {
  matrix_t matrix;

  int rows = 4;
  int columns = 5;

  int create_mat = s21_create_matrix(rows, columns, &matrix);

  s21_remove_matrix(&matrix);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(test_s21_remove_matrix1) {
  matrix_t matrix;

  int rows = 2;
  int columns = 7;
  double data1[14] = {10, 20, 30,  40,  50,  60,  70,
                      80, 90, 100, 110, 120, 130, 140};

  int create_mat = s21_create_matrix(rows, columns, &matrix);
  s21_fill_matrix(data1, &matrix);

  s21_remove_matrix(&matrix);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

Suite *remove_matrix_suite() {
  Suite *remove_matrix_suite = suite_create("remove_matrix_suite");
  TCase *tc_core;

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_remove_matrix0);
  tcase_add_test(tc_core, test_s21_remove_matrix1);

  suite_add_tcase(remove_matrix_suite, tc_core);

  return remove_matrix_suite;
}
