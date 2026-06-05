#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 1;
  for (int i = 0; i < 4 && result == 1; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      result = 0;
    }
  }
  return result;
}

int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int result = 0, exit = 0;
  int sign1 = s21_get_sign(&value1);
  int sign2 = s21_get_sign(&value2);

  if (sign1 != sign2) {
    (sign1 && !sign2) ? result = 1 : 0;
    exit = 1;
  }

  if (!exit) {
    work_decimal ext1, ext2;
    ext1 = s21_decimal_to_work_decimal(&value1);
    ext2 = s21_decimal_to_work_decimal(&value2);

    s21_alignment_scale(&ext1, &ext2);

    if (sign1) {
      for (int i = 6; i >= 0 && !exit; i--) {
        if (ext1.bits[i] > ext2.bits[i]) {
          result = 1;
          exit = 1;
        } else if (ext1.bits[i] < ext2.bits[i]) {
          result = 0;
          exit = 1;
        }
      }
    } else {
      for (int i = 6; i >= 0 && !exit; i--) {
        if (ext1.bits[i] < ext2.bits[i]) {
          result = 1;
          exit = 1;
        } else if (ext1.bits[i] > ext2.bits[i]) {
          result = 0;
          exit = 1;
        }
      }
    }
  }

  return result;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_less(value_1, value_2) && !s21_is_equal(value_1, value_2);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_greater(value_1, value_2) || s21_is_equal(value_1, value_2);
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_1, value_2) || s21_is_equal(value_1, value_2);
}