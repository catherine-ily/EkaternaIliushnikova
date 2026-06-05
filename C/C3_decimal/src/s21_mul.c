#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int code_error = OK;
  int sign_result = (s21_get_sign(&value_1) != s21_get_sign(&value_2));
  s21_init_decimal(result);
  s21_decimal null;
  s21_init_decimal(&null);

  if (!result) {
    code_error = FALSE;
  } else if (s21_get_scale(&value_1) > S21_MAX_SCALE ||
             s21_get_scale(&value_2) > S21_MAX_SCALE) {
    code_error = ERROR;
  } else {
    work_decimal ext_1 = s21_decimal_to_work_decimal(&value_1);
    work_decimal ext_2 = s21_decimal_to_work_decimal(&value_2);
    work_decimal res = s21_decimal_to_work_decimal(result);

    if (s21_is_equal(value_1, null) || s21_is_equal(value_2, null)) {
      sign_result = 0;
    } else {
      res.bits[0] = ext_1.bits[0] * ext_2.bits[0];
      s21_get_overflow(&res);
      res.bits[1] += ext_1.bits[0] * ext_2.bits[1];
      s21_get_overflow(&res);
      res.bits[1] += ext_1.bits[1] * ext_2.bits[0];
      s21_get_overflow(&res);

      res.bits[2] += ext_1.bits[0] * ext_2.bits[2];
      s21_get_overflow(&res);
      res.bits[2] += ext_1.bits[1] * ext_2.bits[1];
      s21_get_overflow(&res);
      res.bits[2] += ext_1.bits[2] * ext_2.bits[0];
      s21_get_overflow(&res);

      res.bits[3] += ext_1.bits[1] * ext_2.bits[2];
      s21_get_overflow(&res);
      res.bits[3] += ext_1.bits[2] * ext_2.bits[1];
      s21_get_overflow(&res);
      res.bits[4] += ext_1.bits[2] * ext_2.bits[2];

      res.scale = ext_1.scale + ext_2.scale;
      code_error = s21_get_overflow(&res);
    }

    if (!code_error) code_error = s21_normalization(&res);
    if (code_error) {
      if (sign_result) code_error = 2;
    } else {
      s21_convert_from_work_decimal(res, result);
      s21_set_sign(result, sign_result);
    }
  }

  return code_error;
}
