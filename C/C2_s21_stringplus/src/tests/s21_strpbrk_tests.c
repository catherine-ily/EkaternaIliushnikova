#include "s21_tests.h"

START_TEST(test_s21_strpbrk_1) {
  const char str_1[] = "Hello, World!";
  const char str_2[] = "oy";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  const char str_1[] = "Hello, World!";
  const char str_2[] = "";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  const char str_1[] = "";
  const char str_2[] = "oy";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  const char str_1[] = " ";
  const char str_2[] = "o y";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  const char str_1[] = "\n";
  const char str_2[] = "o\ny";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  const char str_1[] = "Hello, World!";
  const char str_2[] = "\0";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  const char str_1[] = "Hello, World!";
  const char str_2[] = "356324";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  const char str_1[] = "Hello, World!";
  const char str_2[] = "---";
  const char *orig = strpbrk(str_1, str_2);
  const char *s21 = s21_strpbrk(str_1, str_2);
  ck_assert_ptr_eq(orig, s21);
}
END_TEST

Suite *s21_strpbrk_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_strpbrk_1);
  tcase_add_test(tcase, test_s21_strpbrk_2);
  tcase_add_test(tcase, test_s21_strpbrk_3);
  tcase_add_test(tcase, test_s21_strpbrk_4);
  tcase_add_test(tcase, test_s21_strpbrk_5);
  tcase_add_test(tcase, test_s21_strpbrk_6);
  tcase_add_test(tcase, test_s21_strpbrk_7);
  tcase_add_test(tcase, test_s21_strpbrk_8);

  suite_add_tcase(suite, tcase);
  return suite;
}
