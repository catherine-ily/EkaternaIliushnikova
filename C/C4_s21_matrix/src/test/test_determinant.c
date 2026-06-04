#include "tests.h"

START_TEST(test_s21_determinant0) {
  double result;
  int code = s21_determinant(NULL, &result);

  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_determinant1) {
  int size = 1;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {1.0};
  s21_fill_matrix(vals, &mat);

  int rc_det = s21_determinant(&mat, NULL);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, INCORRECT_MATRIX);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant2) {
  int rows = 1, cols = 4;
  matrix_t mat;
  int rc_create = s21_create_matrix(rows, cols, &mat);
  double vals[] = {-921.56, -799.69, 88.9862, 891.8899};
  s21_fill_matrix(vals, &mat);

  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, CALCULATION_ERROR);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant3) {
  int size = 1;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {0.0};
  s21_fill_matrix(vals, &mat);

  double expected = 0.0;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant4) {
  int size = 1;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {10.0};
  s21_fill_matrix(vals, &mat);

  double expected = 10.0;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant5) {
  int size = 3;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0};
  s21_fill_matrix(vals, &mat);

  double expected = 0.0;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant6) {
  int size = 4;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {-0.015,  -0.0476, 2.82,   24.1345, 5884.18, -2.506,
                   -2.7138, -6.8,    10.3,   0.059,   -79.0,   6.65,
                   67.894,  751.951, 450.45, -8.98};
  s21_fill_matrix(vals, &mat);

  double expected = -8523729344.118084;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant7) {
  int size = 3;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {-0.5891, -1883.6, -6.06,  389.709, 7.0,
                   9.2,     -9.2529, -973.0, -4.66};
  s21_fill_matrix(vals, &mat);

  double expected = -968130.0766519993;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant8) {
  int size = 5;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {0.99,  976.0,   80.0,    -0.1,   -29.4368, -0.0,    3615.563,
                   -0.72, -4488.5, -1613.0, 2.0,    -0.777,   -4.829,  6.0,
                   0.84,  -514.0,  0.9,     -0.11,  264.4783, -3.7369, 5.796,
                   66.6,  2.245,   44.7264, 858.832};
  s21_fill_matrix(vals, &mat);

  double expected = -9976903813281.12;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant9) {
  int size = 3;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {70.0,   30.89,   30.4778, 69.78,  0.3,
                   -9.098, -8.5586, -71.0,   -5722.8};
  s21_fill_matrix(vals, &mat);

  double expected = 12021608.512336815;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

START_TEST(test_s21_determinant10) {
  int size = 3;
  matrix_t mat;
  int rc_create = s21_create_matrix(size, size, &mat);
  double vals[] = {0.0, 2.0, 2.0, 3.0, 0.3, -3.0, -8.0, -71.0, 12.0};
  s21_fill_matrix(vals, &mat);

  double expected = -445.2;
  double det_result;
  int rc_det = s21_determinant(&mat, &det_result);

  ck_assert_int_eq(rc_create, OK);
  ck_assert_int_eq(rc_det, OK);
  ck_assert_float_eq_tol(det_result, expected, ACCURACY);

  s21_remove_matrix(&mat);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *suite = suite_create("determinant_suite");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_determinant0);
  tcase_add_test(tc, test_s21_determinant1);
  tcase_add_test(tc, test_s21_determinant2);
  tcase_add_test(tc, test_s21_determinant3);
  tcase_add_test(tc, test_s21_determinant4);
  tcase_add_test(tc, test_s21_determinant5);
  tcase_add_test(tc, test_s21_determinant6);
  tcase_add_test(tc, test_s21_determinant7);
  tcase_add_test(tc, test_s21_determinant8);
  tcase_add_test(tc, test_s21_determinant9);
  tcase_add_test(tc, test_s21_determinant10);

  suite_add_tcase(suite, tc);

  return suite;
}
