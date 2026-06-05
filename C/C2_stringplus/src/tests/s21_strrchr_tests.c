#include "s21_tests.h"

START_TEST(s21_strrchr_1) {
  char str1[] = "School21";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}

START_TEST(s21_strrchr_2) {
  char str1[] = "School21";
  char str2 = 'a';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}

START_TEST(s21_strrchr_3) {
  char str1[] = "";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}

START_TEST(s21_strrchr_4) {
  char str1[] = "School21";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}

Suite *s21_strrchr_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_strrchr_1);
  tcase_add_test(tcase, s21_strrchr_2);
  tcase_add_test(tcase, s21_strrchr_3);
  tcase_add_test(tcase, s21_strrchr_4);

  suite_add_tcase(suite, tcase);
  return suite;
}
