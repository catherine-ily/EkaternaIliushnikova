#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int code_error = OK;
  int overbit = FALSE;

  int sign_1 = s21_get_sign(&value_1), sign_2 = s21_get_sign(&value_2);
  work_decimal ext_1 = s21_decimal_to_work_decimal(&value_1);
  work_decimal ext_2 = s21_decimal_to_work_decimal(&value_2);

  if (!result) {
    code_error = ERROR;
  } else if (s21_get_scale(&value_1) > S21_MAX_SCALE ||
             s21_get_scale(&value_2) > S21_MAX_SCALE) {
    code_error = ERROR;
  } else {
    s21_init_decimal(result);
    work_decimal result_ext = s21_decimal_to_work_decimal(result);
    s21_alignment_scale(&ext_1, &ext_2);

    if (sign_1 == sign_2) {
      for (int i = 0; i < 224; i++) {
        int bit_1 = s21_get_bit_ext(&ext_1, i);
        int bit_2 = s21_get_bit_ext(&ext_2, i);

        s21_set_bit_ext(&result_ext, i, (bit_1 + bit_2 + overbit) % 2);
        overbit = (bit_1 && bit_2) || (bit_1 && overbit) || (bit_2 && overbit);
      }

      result_ext.scale = ext_1.scale;
      code_error = s21_normalization(&result_ext);
      s21_convert_from_work_decimal(result_ext, result);

      if (sign_1 == sign_2 && sign_1 == 1) {
        s21_set_sign(result, 1);
        code_error = code_error == 1 ? 2 : code_error;
      }
    } else {
      if (sign_1 > sign_2) {
        s21_set_sign(&value_1, 0);
        code_error = s21_sub(value_2, value_1, result);
      } else {
        s21_set_sign(&value_2, 0);
        code_error = s21_sub(value_1, value_2, result);
      }
    }
  }

  return code_error;
}
