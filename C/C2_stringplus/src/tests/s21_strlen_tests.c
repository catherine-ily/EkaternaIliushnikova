#include "s21_tests.h"

START_TEST(test_s21_strlen_1) {
  char str[] = "Hello";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char str[] = "\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char str[] = "........";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  char str[] = "4568757=609-679;3'45;;452";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_6) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_7) {
  char str[] = "erkvybgvsKUYYFVHFB-345_8";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_8) {
  char str[] = "          ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *s21_strlen_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_strlen_1);
  tcase_add_test(tcase, test_s21_strlen_2);
  tcase_add_test(tcase, test_s21_strlen_3);
  tcase_add_test(tcase, test_s21_strlen_4);
  tcase_add_test(tcase, test_s21_strlen_5);
  tcase_add_test(tcase, test_s21_strlen_6);
  tcase_add_test(tcase, test_s21_strlen_7);
  tcase_add_test(tcase, test_s21_strlen_8);

  suite_add_tcase(suite, tcase);
  return suite;
}
