#include "s21_tests.h"

START_TEST(test_s21_memcpy) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";
  char test_8[10] = "";

  ck_assert_ptr_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_ptr_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_ptr_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_ptr_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
  ck_assert_ptr_eq(s21_memcpy(test_8, test_5, 6), memcpy(test_8, test_5, 6));
}
END_TEST

Suite *s21_memcpy_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_memcpy);

  suite_add_tcase(suite, tcase);
  return suite;
}
