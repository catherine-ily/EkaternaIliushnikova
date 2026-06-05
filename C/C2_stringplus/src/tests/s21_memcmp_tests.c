#include "s21_tests.h"

int check_memcmp(int num) {
  int res = 0;
  if (num > 0) {
    res = 1;
  } else if (num < 0) {
    res = -1;
  }
  return res;
}

START_TEST(s21_memcmp_1) {
  char str_1[] = "School21";
  char str_2[] = "School21";
  ck_assert_int_eq(check_memcmp(memcmp(str_1, str_2, 8)),
                   check_memcmp(s21_memcmp(str_1, str_2, 8)));
}
END_TEST

START_TEST(s21_memcmp_2) {
  char str_1[] = "\n";
  char str_2[] = "School21";
  ck_assert_int_eq(check_memcmp(memcmp(str_1, str_2, 2)),
                   check_memcmp(s21_memcmp(str_1, str_2, 2)));
}
END_TEST

START_TEST(s21_memcmp_3) {
  char str_1[] = "chool";
  char str_2[] = "School21";
  ck_assert_int_eq(check_memcmp(memcmp(str_1, str_2, 6)),
                   check_memcmp(s21_memcmp(str_1, str_2, 6)));
}
END_TEST

START_TEST(s21_memcmp_4) {
  char str_1[] = "School/021";
  char str_2[] = "School21";
  ck_assert_int_eq(check_memcmp(memcmp(str_1, str_2, 9)),
                   check_memcmp(s21_memcmp(str_1, str_2, 9)));
}
END_TEST

START_TEST(s21_memcmp_5) {
  char str_1[] = "abc";
  char str_2[] = "abc";
  ck_assert_int_eq(check_memcmp(memcmp(str_1, str_2, 4)),
                   check_memcmp(s21_memcmp(str_1, str_2, 4)));
}
END_TEST

Suite *s21_memcmp_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_memcmp_1);
  tcase_add_test(tcase, s21_memcmp_2);
  tcase_add_test(tcase, s21_memcmp_3);
  tcase_add_test(tcase, s21_memcmp_4);
  tcase_add_test(tcase, s21_memcmp_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
