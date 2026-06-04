#include "s21_tests.h"

START_TEST(test_s21_insert_1) {
  char *src = "World";
  char *result;
  result = s21_insert(src, "Hello ", 0);
  ck_assert_pstr_eq(result, "Hello World");
  free(result);
}
END_TEST

START_TEST(test_s21_insert_2) {
  char *src = "";
  char *result = {0};
  result = s21_insert(src, "Hello", 0);
  ck_assert_pstr_eq(result, "Hello");
  free(result);
}
END_TEST

Suite *s21_insert_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_insert_1);
  tcase_add_test(tcase, test_s21_insert_2);

  suite_add_tcase(suite, tcase);
  return suite;
}
