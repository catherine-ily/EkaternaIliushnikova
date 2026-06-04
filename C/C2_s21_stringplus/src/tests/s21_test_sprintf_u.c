#include "s21_tests.h"

START_TEST(sprintf_1_u) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_u) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_u) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %-u %+u %.u % .u";
  unsigned int val = 0;

  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val));

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_u(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_U=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_u);
  tcase_add_test(tc, sprintf_2_u);
  tcase_add_test(tc, sprintf_3_u);
  tcase_add_test(tc, sprintf_4_u);
  tcase_add_test(tc, sprintf_5_u);

  suite_add_tcase(s, tc);
  return s;
}
