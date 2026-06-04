#include "s21_tests.h"

START_TEST(test_s21_to_lower_1) {
  const char *str = "hello";
  char *result_custom = (char *)s21_to_lower(str);
  char *result_real = malloc(strlen(str) + 1);
  if (result_real != S21_NULL) {
    strcpy(result_real, str);
  }
  for (s21_size_t i = 0; i < strlen(result_real); i++) {
    result_real[i] = (char)tolower(result_real[i]);
  }
  ck_assert_str_eq(result_custom, result_real);
  free(result_custom);
  free(result_real);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  const char *str = "helLO WoRlD";
  char *result_custom = (char *)s21_to_lower(str);
  char *result_real = malloc(strlen(str) + 1);
  if (result_real != S21_NULL) {
    strcpy(result_real, str);
  }
  for (s21_size_t i = 0; i < strlen(result_real); i++) {
    result_real[i] = (char)tolower(result_real[i]);
  }
  ck_assert_str_eq(result_custom, result_real);
  free(result_custom);
  free(result_real);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char *str = "";
  char *result_custom = (char *)s21_to_lower(str);
  char *result_real = malloc(strlen(str) + 1);
  if (result_real != S21_NULL) {
    strcpy(result_real, str);
  }
  for (s21_size_t i = 0; i < strlen(result_real); i++) {
    result_real[i] = (char)tolower(result_real[i]);
  }
  ck_assert_str_eq(result_custom, result_real);
  free(result_custom);
  free(result_real);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char *str = "123";
  char *result_custom = (char *)s21_to_lower(str);
  char *result_real = malloc(strlen(str) + 1);
  if (result_real != S21_NULL) {
    strcpy(result_real, str);
  }
  for (s21_size_t i = 0; i < strlen(result_real); i++) {
    result_real[i] = (char)tolower(result_real[i]);
  }
  ck_assert_str_eq(result_custom, result_real);
  free(result_custom);
  free(result_real);
}
END_TEST

START_TEST(test_s21_to_lower_5) {
  const char *str = "HELLO";
  char *result_custom = (char *)s21_to_lower(str);
  char *result_real = malloc(strlen(str) + 1);
  if (result_real != S21_NULL) {
    strcpy(result_real, str);
  }
  for (s21_size_t i = 0; i < strlen(result_real); i++) {
    result_real[i] = (char)tolower(result_real[i]);
  }
  ck_assert_str_eq(result_custom, result_real);
  free(result_custom);
  free(result_real);
}
END_TEST

Suite *s21_to_lower_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, test_s21_to_lower_1);
  tcase_add_test(tcase, test_s21_to_lower_2);
  tcase_add_test(tcase, test_s21_to_lower_3);
  tcase_add_test(tcase, test_s21_to_lower_4);
  tcase_add_test(tcase, test_s21_to_lower_5);

  suite_add_tcase(suite, tcase);
  return suite;
}
