#include "s21_tests.h"

START_TEST(s21_strstr_1) {
  char str[] = "He";
  char res[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(res, str), strstr(res, str));
}

START_TEST(s21_strstr_2) {
  char str[] = "Ry";
  char res[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(res, str), strstr(res, str));
}

START_TEST(s21_strstr_3) {
  char str[] = "";
  char res[] = "";
  ck_assert_pstr_eq(s21_strstr(res, str), strstr(res, str));
}

START_TEST(s21_strstr_4) {
  char str[] = "";
  char res[] = "wr";
  ck_assert_str_eq(s21_strstr(res, str), strstr(res, str));
}

Suite *s21_strstr_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_strstr_1);
  tcase_add_test(tcase, s21_strstr_2);
  tcase_add_test(tcase, s21_strstr_3);
  tcase_add_test(tcase, s21_strstr_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
