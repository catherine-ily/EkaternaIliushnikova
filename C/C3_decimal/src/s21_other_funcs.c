#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  s21_init_decimal(result);
  int exit = 0;
  if (!s21_truncate(value, result) && s21_get_sign(&value) &&
      s21_is_not_equal(*result, value)) {
    s21_decimal one = {{1, 0, 0, 0}};
    if (s21_sub(*result, one, result)) exit = 1;
  }
  return exit;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int exit = 0;
  if (!s21_truncate(value, result) && s21_is_not_equal(value, *result)) {
    s21_decimal half = {{5, 0, 0, 65536}};
    if (s21_get_sign(&value)) {
      if (s21_sub(value, half, &value)) exit = 1;
    } else {
      if (s21_add(value, half, &value)) exit = 1;
    }
    s21_truncate(value, result);
  }
  return exit;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  s21_init_decimal(result);
  int scale = 0;
  scale = s21_get_scale(&value);
  if (scale) {
    s21_decrease_scale(&value, scale);
  }
  s21_copy(result, value);
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  int result_function = 0;

  if (result == NULL) {
    result_function = 1;
  } else {
    s21_copy(result, value);
    result->bits[3] = (value.bits[3] ^ (1 << 31));
  }

  return result_function;
}