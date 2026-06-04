#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int code_error = OK;
  work_decimal ext_1 = s21_decimal_to_work_decimal(&value_1);
  work_decimal ext_2 = s21_decimal_to_work_decimal(&value_2);
  int sign_1 = s21_get_sign(&value_1), sign_2 = s21_get_sign(&value_2);

  s21_alignment_scale(&ext_1, &ext_2);

  if (!result) {
    code_error = ERROR;
  } else if (s21_get_scale(&value_1) > S21_MAX_SCALE ||
             s21_get_scale(&value_2) > S21_MAX_SCALE) {
    code_error = ERROR;
  } else {
    s21_init_decimal(result);

    if (sign_1 != sign_2) {
      if (sign_1 == 1) {
        s21_set_sign(&value_1, 0);
        code_error = s21_add(value_1, value_2, result);
        if (code_error == 1)
          code_error = 2;
        else
          s21_set_sign(result, 1);
      }
      if (sign_2 == 1) {
        s21_set_sign(&value_2, 0);
        code_error = s21_add(value_1, value_2, result);
      }
    } else {
      if (sign_1 == 1) {
        s21_set_sign(&value_1, 0);
        s21_set_sign(&value_2, 0);
        s21_sub(value_2, value_1, result);
      } else {
        if (s21_is_less(value_1, value_2)) {
          s21_simple_sub(ext_2, ext_1, result);
          s21_set_sign(result, 1);
        } else {
          s21_simple_sub(ext_1, ext_2, result);
        }
      }
      s21_set_scale(result, ext_1.scale);
    }
  }

  return code_error;
}
