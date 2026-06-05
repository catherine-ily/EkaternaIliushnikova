#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_sprintf.h"
#include "../s21_string.h"

Suite *s21_strlen_tests(void);
Suite *s21_memchr_tests(void);
Suite *s21_memset_tests(void);
Suite *s21_strncat_tests(void);
Suite *s21_memcmp_tests(void);
Suite *s21_strncpy_tests(void);
Suite *s21_strcspn_tests(void);
Suite *s21_strerror_tests(void);
Suite *s21_strpbrk_tests(void);
Suite *s21_strchr_tests(void);
Suite *s21_strncmp_tests(void);
Suite *s21_strrchr_tests(void);
Suite *s21_strstr_tests(void);
Suite *s21_strtok_tests(void);
Suite *s21_memcpy_tests(void);
Suite *s21_to_upper_tests(void);
Suite *s21_to_lower_tests(void);
Suite *s21_insert_tests(void);
Suite *s21_trim_tests(void);
Suite *test_sprintf_c(void);
Suite *test_sprintf_d(void);
Suite *test_sprintf_f(void);
Suite *test_sprintf_s(void);
Suite *test_sprintf_u(void);
Suite *test_sprintf_percent(void);

#endif
