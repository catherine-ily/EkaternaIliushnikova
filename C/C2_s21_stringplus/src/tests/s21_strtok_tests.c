#include "s21_tests.h"

START_TEST(s21_strtok_1) {
  char str1[] = "AB!CD";
  char str2[] = "AB!CD";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_2) {
  char str1[] = "AB!CD";
  char str2[] = "AB!CD";
  const char delims[] = "+_ =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_3) {
  char str1[] = "A+B    !C!D";
  char str2[] = "A+B    !C!D";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_4) {
  char str1[] = "A+B _=    !C!D";
  char str2[] = "A+B _=    !C!D";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_5) {
  char str1[] = "";
  char str2[] = "";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_eq(got, expected);
  if (got && expected) {
    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_pstr_eq(got, expected);
  }
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    ck_assert_ptr_eq(got, expected);
    if (got && expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_6) {
  char str1[] = "+_! =";
  char str2[] = "+_! =";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_ptr_eq(got, expected);
  if (got && expected) {
    ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    ck_assert_pstr_eq(got, expected);
  }
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    ck_assert_ptr_eq(got, expected);
    if (got && expected) {
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
      ck_assert_pstr_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_7) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(S21_NULL, delims);
    expected = strtok(S21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}

START_TEST(s21_strtok_8) {
  char s1[] = "\nAhahahahahahahFF";
  char s2[] = "\nAhahahahahahahFF";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_9) {
  char s1[] = "\0Hello, school 21";
  char s2[] = "\0Hello, school 21";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_10) {
  char s1[] = "\0Hello, school 21";
  char s2[] = "\0Hello, school 21";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_11) {
  char *s1 = "";
  char *s2 = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_12) {
  char s1[] = "fjf fjf = fjf";
  char s2[] = "fjf fjf = fjf";
  char s3[] = "fjf = fjf";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(s21_strtok_13) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "e";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(s21_strtok_14) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(s21_strtok_15) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
}
END_TEST

START_TEST(s21_strtok_16) {
  char s1[] = "RIM AMD ROM!!";
  char s2[] = "RIM AMD ROM!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(S21_NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(S21_NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(s21_strtok_17) {
  char s1[] = "ASFERIKA";
  char s2[] = "ASFERIKA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(S21_NULL, s3);
  strtok(S21_NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(S21_NULL, s3);
  s21_strtok(S21_NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(s21_strtok_18) {
  char s1[] = "hdfg wejhfjkweh eje";
  char s2[] = "hdfg wejhfjkweh eje";
  char s3[] = "hdfg wejhfjkweh";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(S21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(S21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(s21_strtok_19) {
  char s1[] = "gggGGGHJAAJAAAJHJH";
  char s2[] = "gggGGGHJAAJAAAJHJH";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(S21_NULL, s2);
  strtok(S21_NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(S21_NULL, s3);
  s21_strtok(S21_NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *s21_strtok_tests(void) {
  Suite *suite = suite_create("String Tests");
  TCase *tcase = tcase_create("Core");

  tcase_add_test(tcase, s21_strtok_1);
  tcase_add_test(tcase, s21_strtok_2);
  tcase_add_test(tcase, s21_strtok_3);
  tcase_add_test(tcase, s21_strtok_4);
  tcase_add_test(tcase, s21_strtok_5);
  tcase_add_test(tcase, s21_strtok_6);
  tcase_add_test(tcase, s21_strtok_7);
  tcase_add_test(tcase, s21_strtok_8);
  tcase_add_test(tcase, s21_strtok_9);
  tcase_add_test(tcase, s21_strtok_10);
  tcase_add_test(tcase, s21_strtok_11);
  tcase_add_test(tcase, s21_strtok_12);
  tcase_add_test(tcase, s21_strtok_13);
  tcase_add_test(tcase, s21_strtok_14);
  tcase_add_test(tcase, s21_strtok_15);
  tcase_add_test(tcase, s21_strtok_16);
  tcase_add_test(tcase, s21_strtok_17);
  tcase_add_test(tcase, s21_strtok_18);
  tcase_add_test(tcase, s21_strtok_19);

  suite_add_tcase(suite, tcase);
  return suite;
}
