#include "s21_tests.h"

START_TEST(sprintf_1_s) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemorrhoids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_s) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %s Test2";
  char *val = "3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_s) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_s) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "s";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_s(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_S=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_s);
  tcase_add_test(tc, sprintf_2_s);
  tcase_add_test(tc, sprintf_3_s);
  tcase_add_test(tc, sprintf_4_s);
  tcase_add_test(tc, sprintf_5_s);

  suite_add_tcase(s, tc);
  return s;
}
