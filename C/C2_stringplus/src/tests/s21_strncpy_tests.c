#include "s21_tests.h"

START_TEST(test_s21_strncpy_1) {
  char src[] = "World";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char src[] = "\0";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 1;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char src[] = "\n";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 1;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char src[] = "0";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 0;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char src[] = "uygrehgvkedVJHBJKYBJK";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char src[] = "";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char src[] = "\\n\0gfdds";
  char dest_1[30] = "Hello, ";
  char dest_2[30] = "Hello, ";
  s21_size_t n = 15;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_8) {
  char src[] = "World";
  char dest_1[30] = "";
  char dest_2[30] = "";
  s21_size_t n = 5;
  ck_assert_str_eq(strncpy(dest_1, src, n), s21_strncpy(dest_2, src, n));
}
END_TEST

Suite *s21_strncpy_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_strncpy_1);
  tcase_add_test(tcase, test_s21_strncpy_2);
  tcase_add_test(tcase, test_s21_strncpy_3);
  tcase_add_test(tcase, test_s21_strncpy_4);
  tcase_add_test(tcase, test_s21_strncpy_5);
  tcase_add_test(tcase, test_s21_strncpy_6);
  tcase_add_test(tcase, test_s21_strncpy_7);
  tcase_add_test(tcase, test_s21_strncpy_8);

  suite_add_tcase(suite, tcase);
  return suite;
}
