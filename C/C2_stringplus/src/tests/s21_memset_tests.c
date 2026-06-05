#include "s21_tests.h"

START_TEST(test_s21_memset_1) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  int value = 9;
  s21_size_t num = s21_strlen(str1);
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  int value = ' ';
  s21_size_t num = s21_strlen(str1);
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  int value = 'y';
  s21_size_t num = 5;
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_4) {
  char str1[] = "";
  char str2[] = "";
  int value = '\0';
  s21_size_t num = 0;
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_5) {
  char str1[] = "            ";
  char str2[] = "            ";
  int value = 'y';
  s21_size_t num = 5;
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_6) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  int value = '\n';
  s21_size_t num = 5;
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

START_TEST(test_s21_memset_7) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  int value = 101;
  s21_size_t num = s21_strlen(str1);
  ck_assert_str_eq(memset(str1, value, num), s21_memset(str2, value, num));
}
END_TEST

Suite *s21_memset_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_memset_1);
  tcase_add_test(tcase, test_s21_memset_2);
  tcase_add_test(tcase, test_s21_memset_3);
  tcase_add_test(tcase, test_s21_memset_4);
  tcase_add_test(tcase, test_s21_memset_5);
  tcase_add_test(tcase, test_s21_memset_6);
  tcase_add_test(tcase, test_s21_memset_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
