#include <stdbool.h>

#include "s21_tests.h"

START_TEST(test_s21_trim_1) {
  const char *src = "  abc  ";
  const char *trim_chars = " ";
  char *result = (char *)s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "abc");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  const char *src = "xxabcxx";
  const char *trim_chars = "x";
  char *result = (char *)s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "abc");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  const char *src = "";
  const char *trim_chars = " ";
  char *result = (char *)s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_4) {
  const char *src = "abc";
  const char *trim_chars = "";
  char *result = (char *)s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "abc");
  free(result);
}
END_TEST

START_TEST(test_s21_trim_5) {
  const char *src = "xxx";
  const char *trim_chars = "x";
  char *result = (char *)s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *s21_trim_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_trim_1);
  tcase_add_test(tcase, test_s21_trim_2);
  tcase_add_test(tcase, test_s21_trim_3);
  tcase_add_test(tcase, test_s21_trim_4);
  tcase_add_test(tcase, test_s21_trim_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
