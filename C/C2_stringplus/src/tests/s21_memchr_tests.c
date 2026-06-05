#include "s21_tests.h"

START_TEST(test_s21_memchr_1) {
  char str[] = "Hello";
  int sym = 'e';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char str[] = "       ";
  int sym = '\n';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char str[] = "RFJERFKDJNM";
  int sym = '6';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_4) {
  char str[] = "RFJERFKDJNM";
  int sym = 'M';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char str[] = "597t8264957-4/4";
  int sym = '/';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  char str[] = "          ";
  int sym = '\0';
  ck_assert_ptr_eq(memchr(str, sym, s21_strlen(str)),
                   s21_memchr(str, sym, s21_strlen(str)));
}
END_TEST

START_TEST(test_s21_memchr_7) {
  char str[] = "Hello, World!";
  int sym = 'e';
  ck_assert_ptr_eq(memchr(str, sym, 10), s21_memchr(str, sym, 10));
}
END_TEST

START_TEST(test_s21_memchr_8) {
  char str[] = "Hello, World!";
  int sym = '!';
  ck_assert_ptr_eq(memchr(str, sym, 5), s21_memchr(str, sym, 5));
}
END_TEST

START_TEST(test_s21_memchr_9) {
  char str[] = "11115";
  int sym = '1';
  ck_assert_ptr_eq(memchr(str, sym, 4), s21_memchr(str, sym, 4));
}
END_TEST

Suite *s21_memchr_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_memchr_1);
  tcase_add_test(tcase, test_s21_memchr_2);
  tcase_add_test(tcase, test_s21_memchr_3);
  tcase_add_test(tcase, test_s21_memchr_4);
  tcase_add_test(tcase, test_s21_memchr_5);
  tcase_add_test(tcase, test_s21_memchr_6);
  tcase_add_test(tcase, test_s21_memchr_7);
  tcase_add_test(tcase, test_s21_memchr_8);
  tcase_add_test(tcase, test_s21_memchr_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
