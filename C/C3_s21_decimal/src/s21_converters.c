#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  int result_function = 0;
  if (!dst || isnan(src) || isinf(src)) result_function = 1;
  if (fabs(src) > 79228162514264337593543950335.0) result_function = 1;
  if (fabs(src) < 1e-28 && fabs(src) != 0.0f) {
    memset(dst, 0, sizeof(s21_decimal));
    result_function = 1;
  }

  if (result_function == 0) {
    int sign = (src < 0);
    src = sign ? -src : src;

    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%.7g", src);

    int int_part = 0, frac_part = 0, frac_digits = 0;
    int point_pos = -1;
    int len = strlen(buffer);

    point_pos = s21_find_point_pos(len, buffer);
    int_part = s21_find_int_part(point_pos, len, buffer);
    frac_part = s21_find_frac_part(point_pos, len, buffer, &frac_digits);

    unsigned long long value = int_part;
    int scale = frac_digits;

    for (int i = 0; i < frac_digits; i++) {
      value *= 10;
    }
    value += frac_part;

    while (scale > 0 && value % 10 == 0) {
      value /= 10;
      scale--;
    }

    if (value > 0xFFFFFFFFFFFFFFFFULL) result_function = 1;

    if (result_function == 0) {
      s21_init_decimal(dst);
      dst->bits[0] = value & 0xFFFFFFFF;
      dst->bits[1] = (value >> 32) & 0xFFFFFFFF;
      dst->bits[2] = 0;
      dst->bits[3] = (sign << 31) | (scale << 16);
    }
  }
  return result_function;
}

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  int result_function = 0;
  if (dst == NULL) {
    result_function = 1;
  } else {
    int sign = s21_get_sign(&src);
    int scale = s21_get_scale(&src);
    if (scale > 28) {
      result_function = 1;
    }

    double int_value = 0.0;
    for (int i = 0; i < 96; i++) {
      if (s21_get_bit(&src, i)) {
        int_value += pow(2.0, i);
      }
    }

    float value = (float)(int_value / pow(10, scale));

    if (int_value > 0 && value < 1e-28f) {
      *dst = 0.0f;
      result_function = 1;
    }

    if (sign) {
      value = -value;
    }

    if (value > 79228162514264337593543950335.0 ||
        value < -79228162514264337593543950335.0) {
      result_function = 1;
    }

    if (result_function == 0) {
      *dst = value;
    }
  }
  return result_function;
}

int s21_from_int_to_decimal(int src, s21_decimal* dst) {
  int result_function = 0;
  if (dst == NULL) {
    result_function = 1;
  } else {
    s21_init_decimal(dst);
    int sign = (src < 0) ? 1 : 0;
    dst->bits[0] = (src == INT_MIN) ? (unsigned)INT_MAX + 1u : (int)abs(src);
    if (sign) {
      dst->bits[3] |= (1 << 31);
    }
  }

  return result_function;
}

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  int result_function = 0;
  int scale = s21_get_scale(&src);
  if (scale > 28 || dst == NULL) {
    result_function = 1;
  } else {
    int mantissa = src.bits[0];

    if (scale > 0) {
      int divisor = s21_power_of_ten(scale);
      mantissa /= divisor;
    }

    int sign = s21_get_sign(&src);

    if (sign) {
      if ((unsigned)mantissa > (unsigned)INT_MAX + 1u) {
        result_function = 1;
      }
    } else {
      if ((unsigned)mantissa > (unsigned)INT_MAX) {
        result_function = 1;
      }
    }
    if (!result_function) {
      *dst = sign ? -(int)mantissa : (int)mantissa;
    }
  }
  return result_function;
}
