#include "s21_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str_1[] = "Hello, World!";
  char str_2[] = "abcd";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str_1[] = "Hello, World!";
  char str_2[] = "\0";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str_1[] = "Hello, World!";
  char str_2[] = "";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str_1[] = "Hello, World!";
  char str_2[] = "\n";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char str_1[] = "Hello, World!";
  char str_2[] = "12345";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char str_1[] = "";
  char str_2[] = "abcd";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char str_1[] = "\0";
  char str_2[] = "abcd";
  ck_assert_int_eq(strcspn(str_1, str_2), s21_strcspn(str_1, str_2));
}
END_TEST

Suite *s21_strcspn_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_strcspn_1);
  tcase_add_test(tcase, test_s21_strcspn_2);
  tcase_add_test(tcase, test_s21_strcspn_3);
  tcase_add_test(tcase, test_s21_strcspn_4);
  tcase_add_test(tcase, test_s21_strcspn_5);
  tcase_add_test(tcase, test_s21_strcspn_6);
  tcase_add_test(tcase, test_s21_strcspn_7);

  suite_add_tcase(suite, tcase);
  return suite;
}
