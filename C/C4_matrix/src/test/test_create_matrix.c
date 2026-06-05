#include "tests.h"

START_TEST(test_s21_create_matrix0) {
  matrix_t matrix;

  int rows = 3;
  int columns = 4;

  int create_mat = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_ptr_nonnull(matrix.matrix);

  for (int i = 0; i < matrix.rows; i++) {
    ck_assert_ptr_nonnull(matrix.matrix[i]);
  }

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_create_matrix1) {
  matrix_t matrix;

  int rows = 0;
  int columns = 2;

  int create_mat = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(create_mat, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix2) {
  matrix_t matrix;

  int rows = 3;
  int columns = 0;

  int create_mat = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(create_mat, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix3) {
  int rows = 1;
  int columns = 1;

  int create_mat = s21_create_matrix(rows, columns, NULL);

  ck_assert_int_eq(create_mat, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix4) {
  matrix_t matrix;

  int rows = 1;
  int columns = 6;
  double data[6] = {1, 2, 3, 4, 5, 7};

  int create_mat = s21_create_matrix(rows, columns, &matrix);
  s21_fill_matrix(data, &matrix);

  ck_assert_int_eq(create_mat, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_ptr_nonnull(matrix.matrix);

  int idx = 0;
  for (int i = 0; i < matrix.rows; i++) {
    ck_assert_ptr_nonnull(matrix.matrix[i]);
    for (int j = 0; j < matrix.columns; j++) {
      ck_assert_double_eq_tol(matrix.matrix[i][j], data[idx++], ACCURACY);
    }
  }
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *create_matrix_suite() {
  Suite *suite = suite_create("create_matrix_suite");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_create_matrix0);
  tcase_add_test(tc, test_s21_create_matrix1);
  tcase_add_test(tc, test_s21_create_matrix2);
  tcase_add_test(tc, test_s21_create_matrix3);
  tcase_add_test(tc, test_s21_create_matrix4);

  suite_add_tcase(suite, tc);

  return suite;
}
