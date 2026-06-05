#include "s21_tests.h"

START_TEST(s21_strncmp_1) {
  char str1[] = "School21";
  char str2[] = "School21";
  int res = s21_strncmp(str1, str2, 5);
  int original = strncmp(str1, str2, 5);
  if (res > 1) res = 1;
  if (original > 1) original = 1;
  if (res < -1) res = -1;
  if (original < -1) original = -1;
  ck_assert_int_eq(res, original);
}

START_TEST(s21_strncmp_2) {
  char str1[] = "School21";
  char str2[] = "School22";
  int res = s21_strncmp(str1, str2, 5);
  int original = strncmp(str1, str2, 5);
  if (res > 1) res = 1;
  if (original > 1) original = 1;
  if (res < -1) res = -1;
  if (original < -1) original = -1;
  ck_assert_int_eq(res, original);
}

START_TEST(s21_strncmp_3) {
  char str1[3] = "";
  char str2[] = "";
  int res = s21_strncmp(str1, str2, 3);
  int original = strncmp(str1, str2, 3);
  if (res > 1) res = 1;
  if (original > 1) original = 1;
  if (res < -1) res = -1;
  if (original < -1) original = -1;
  ck_assert_int_eq(res, original);
}

START_TEST(s21_strncmp_4) {
  char str1[] = "";
  char str2[] = "School21";
  int res = s21_strncmp(str1, str2, 0);
  int original = strncmp(str1, str2, 0);
  if (res > 1) res = 1;
  if (original > 1) original = 1;
  if (res < -1) res = -1;
  if (original < -1) original = -1;
  ck_assert_int_eq(res, original);
}

START_TEST(s21_strncmp_5) {
  char s1[] = "kjh";
  char s2[] = "j";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_6) {
  char s1[] = "1234567890123456789";
  char s2[] = "1234567890123456789";
  s21_size_t n = 19;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_7) {
  char s1[] = "1234567890123456789";
  char s2[] = "1234567890123456789";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_8) {
  char s1[] = "g124243425";
  char s2[] = "124243424";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  int n2 = s21_strncmp(s1, s2, n);
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *s21_strncmp_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_strncmp_1);
  tcase_add_test(tcase, s21_strncmp_2);
  tcase_add_test(tcase, s21_strncmp_3);
  tcase_add_test(tcase, s21_strncmp_4);
  tcase_add_test(tcase, s21_strncmp_5);
  tcase_add_test(tcase, s21_strncmp_6);
  tcase_add_test(tcase, s21_strncmp_7);
  tcase_add_test(tcase, s21_strncmp_8);
  tcase_add_test(tcase, s21_strncmp_9);

  suite_add_tcase(suite, tcase);
  return suite;
}
