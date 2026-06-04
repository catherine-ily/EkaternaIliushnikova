#include "s21_tests.h"

START_TEST(test_s21_strerror_1) {
  int n = 1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int n = 107;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(test_s21_strerror_3) {
  int n = 0;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(test_s21_strerror_4) {
  int n = -8;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(test_s21_strerror_5) {
  int n = 134;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(test_s21_strerror_6) {
  int n = 170;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

Suite *s21_strerror_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_strerror_1);
  tcase_add_test(tcase, test_s21_strerror_2);
  tcase_add_test(tcase, test_s21_strerror_3);
  tcase_add_test(tcase, test_s21_strerror_4);
  tcase_add_test(tcase, test_s21_strerror_5);
  tcase_add_test(tcase, test_s21_strerror_6);

  suite_add_tcase(suite, tcase);
  return suite;
}
