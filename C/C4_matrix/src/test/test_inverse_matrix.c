#include "tests.h"

START_TEST(test_s21_inverse_matrix0) {
  matrix_t result;
  int code = s21_inverse_matrix(NULL, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_inverse_matrix1) {
  matrix_t m;
  int size = 2;
  int create_code = s21_create_matrix(size, size, &m);
  double values[] = {52.0, -80.0, -67.15, -5.93};
  s21_fill_matrix(values, &m);

  int inverse_code = s21_inverse_matrix(&m, NULL);

  ck_assert_int_eq(create_code, OK);
  ck_assert_int_eq(inverse_code, INCORRECT_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_s21_inverse_matrix2) {
  matrix_t m;
  int rows = 1, cols = 3;
  int create_code = s21_create_matrix(rows, cols, &m);
  double values[] = {52.0, -80.0, -67.15};
  s21_fill_matrix(values, &m);

  matrix_t result;
  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(create_code, OK);
  ck_assert_int_eq(inverse_code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_s21_inverse_matrix3) {
  matrix_t m, expected, result;
  int size = 1;

  int create_code1 = s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;

  int create_code2 = s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 0.5;

  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
  ck_assert_int_eq(create_code1, OK);
  ck_assert_int_eq(create_code2, OK);
  ck_assert_int_eq(inverse_code, OK);

  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix4) {
  matrix_t m, result;
  int size = 1;
  int create_code = s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 0.0;

  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(create_code, OK);
  ck_assert_int_eq(inverse_code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_s21_inverse_matrix5) {
  matrix_t m, result;
  int size = 3;
  int create_code = s21_create_matrix(size, size, &m);
  double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  s21_fill_matrix(values, &m);

  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(create_code, OK);
  ck_assert_int_eq(inverse_code, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_s21_inverse_matrix6) {
  matrix_t m, expected, result;
  int size = 4;

  int create_code1 = s21_create_matrix(size, size, &m);
  double values1[] = {0.0,     0.904, -0.0, -42.7, -0.48, 10.0,  1.0,   -31.0,
                      -24.777, 22.8,  1.0,  -1.0,  18.0,  0.394, 0.615, 3.4};
  s21_fill_matrix(values1, &m);

  int create_code2 = s21_create_matrix(size, size, &expected);
  double values2[] = {
      0.09172944280702405,   -0.11525894816588249,  0.04493928710154292,
      0.11434091229973918,   0.2181837202087795,    -0.2828738539519266,
      0.15570299987232292,   0.20678187655220118,   -2.720608461223542,
      3.5877642002977974,    -1.4332712985626859,   -1.8772242304635962,
      -0.018800044893003822, -0.005988711100059524, 0.003296382011348476,
      0.0043777708759529235};
  s21_fill_matrix(values2, &expected);

  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(create_code1, OK);
  ck_assert_int_eq(create_code2, OK);
  ck_assert_int_eq(inverse_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix7) {
  matrix_t m, expected, result;
  int size = 3;

  int create_code1 = s21_create_matrix(size, size, &m);
  double values1[] = {16.832, -91.0, -0.4, 0.9, 3.0, -3.0, 14.0, 0.4, -8.822};
  s21_fill_matrix(values1, &m);

  int create_code2 = s21_create_matrix(size, size, &expected);
  double values2[] = {
      -0.00938957404709068,  -0.2984038294941829,  0.10190062549324248,
      -0.012657752313730628, -0.05310275126010341, 0.018631983077057643,
      -0.015474624527857831, -0.4759572334416916,  0.049202170725030386};
  s21_fill_matrix(values2, &expected);

  int inverse_code = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(create_code1, OK);
  ck_assert_int_eq(create_code2, OK);
  ck_assert_int_eq(inverse_code, OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_matrix_suite() {
  Suite *s = suite_create("inverse_matrix_suite");
  TCase *tc = tcase_create("Core");

  tcase_add_test(tc, test_s21_inverse_matrix0);
  tcase_add_test(tc, test_s21_inverse_matrix1);
  tcase_add_test(tc, test_s21_inverse_matrix2);
  tcase_add_test(tc, test_s21_inverse_matrix3);
  tcase_add_test(tc, test_s21_inverse_matrix4);
  tcase_add_test(tc, test_s21_inverse_matrix5);
  tcase_add_test(tc, test_s21_inverse_matrix6);
  tcase_add_test(tc, test_s21_inverse_matrix7);

  suite_add_tcase(s, tc);
  return s;
}