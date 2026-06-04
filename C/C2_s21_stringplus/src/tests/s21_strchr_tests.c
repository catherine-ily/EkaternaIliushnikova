#include "s21_tests.h"

START_TEST(s21_strchr_1) {
  char str[] = "Hello, School21!";
  ck_assert_pstr_eq(strchr(str, 'c'), s21_strchr(str, 'c'));
}

START_TEST(s21_strchr_2) {
  char str[] = "Hello, School21!";
  ck_assert_pstr_eq(strchr(str, 'x'), s21_strchr(str, 'x'));
}

START_TEST(s21_strchr_3) {
  char str[] = "";
  ck_assert_pstr_eq(strchr(str, 'o'), s21_strchr(str, 'o'));
}

START_TEST(s21_strchr_4) {
  char str[] = "Hello, School21!";
  ck_assert_pstr_eq(strchr(str, 'H'), s21_strchr(str, 'H'));
}

START_TEST(s21_strchr_5) {
  char str[] = "Hello, School21!";
  ck_assert_pstr_eq(strchr(str, 'o'), s21_strchr(str, 'o'));
}

START_TEST(s21_strchr_6) {
  char a_4[] = "Hello\0World";
  char b_4 = '\0';
  char *res_4 = s21_strchr(a_4, b_4);
  char *actual_res_4 = strchr(a_4, b_4);
  ck_assert_ptr_eq(res_4, actual_res_4);
}

Suite *s21_strchr_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_strchr_1);
  tcase_add_test(tcase, s21_strchr_2);
  tcase_add_test(tcase, s21_strchr_3);
  tcase_add_test(tcase, s21_strchr_4);
  tcase_add_test(tcase, s21_strchr_5);
  tcase_add_test(tcase, s21_strchr_6);

  suite_add_tcase(suite, tcase);
  return suite;
}
