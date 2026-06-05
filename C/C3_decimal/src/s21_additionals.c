#include "s21_decimal.h"

int s21_get_sign(s21_decimal* value) {
  return (value->bits[3] & S21_SIGN_MASK) ? 1 : 0;
}

int s21_get_scale(s21_decimal* value) {
  return (S21_SCALE_MASK << 16 & value->bits[3]) >> 16;
}

int s21_get_bit_ext(work_decimal* value, int position) {
  return ((value->bits[position / 32] & ((1U << (position % 32)))) != 0);
}

int s21_get_bit(s21_decimal* value, int position) {
  return ((value->bits[position / 32] & ((1U << (position % 32)))) != 0);
}

void s21_set_sign(s21_decimal* value, int sign) {
  if (sign) {
    value->bits[3] |= S21_SIGN_MASK;
  } else {
    value->bits[3] &= ~S21_SIGN_MASK;
  }
}

void s21_set_scale(s21_decimal* value, int scale) {
  value->bits[3] =
      ((unsigned int)s21_get_bit(value, 127) << 31) | (scale << 16);
}

void s21_set_bit_ext(work_decimal* value, int position, int bit) {
  int array_index = position / 32;
  int bit_position = position % 32;

  if (bit) {
    value->bits[array_index] |= (1ULL << bit_position);
  } else {
    value->bits[array_index] &= ~(1ULL << bit_position);
  }
}

int s21_init_decimal(s21_decimal* dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
  return 0;
}

work_decimal s21_decimal_to_work_decimal(s21_decimal* src) {
  work_decimal result;

  for (int i = 0; i < 3; i++) {
    result.bits[i] = (uint64_t)src->bits[i];
  }

  for (int i = 3; i < 7; i++) {
    result.bits[i] = 0;
  }

  result.scale = s21_get_scale(src);

  return result;
}

void s21_convert_from_work_decimal(work_decimal value, s21_decimal* dst) {
  for (int i = 0; i < 3; i++) {
    dst->bits[i] = value.bits[i] & MAXBITS;
  }
  s21_set_scale(dst, value.scale);
}

int s21_comma_shift_right(work_decimal* value) {
  uint64_t carry = 0;

  for (int i = 6; i >= 0; i--) {
    uint64_t current = (carry << 32) | value->bits[i];
    value->bits[i] = current / 10;
    carry = current % 10;
  }
  value->scale--;

  return carry;
}

int s21_comma_shift_left(work_decimal* value) {
  work_decimal tmp = *value;
  int overflow = 0;

  for (int i = 0; i < 7 && !overflow; i++) {
    tmp.bits[i] *= 10;
  }
  if (s21_get_overflow(&tmp)) {
    overflow = ERROR;
  }
  tmp.scale++;

  if (!overflow) *value = tmp;

  return overflow;
}

int s21_get_overflow(work_decimal* value) {
  uint64_t overflow = 0;

  for (int i = 0; i < 7; i++) {
    value->bits[i] = value->bits[i] + overflow;
    overflow = value->bits[i] >> 32;
    value->bits[i] = value->bits[i] & MAXBITS;
  }

  return (overflow > 0);
}

int s21_normalization(work_decimal* value) {
  int code_error = OK, last_rest = 0, existanceOfRest = 0;

  for (int i = 3; i < 7; i++) {
    while (value->bits[i] != 0 && value->scale > 0) {
      if ((last_rest = s21_comma_shift_right(value))) existanceOfRest++;
    }
  }

  if (value->scale > S21_MAX_SCALE) {
    while (value->scale != S21_MAX_SCALE) {
      if ((last_rest = s21_comma_shift_right(value))) existanceOfRest++;
    }
  }

  if (last_rest > 5) {
    value->bits[0] += 1;
    s21_get_overflow(value);
  } else if (last_rest < 5 && last_rest != 0)
    ;
  else if (last_rest == 5 && existanceOfRest > 1) {
    value->bits[0] += 1;
    s21_get_overflow(value);
  } else if (last_rest == 5 && existanceOfRest == 1) {
    if ((value->bits[0] % 10) % 2 != 0) {
      value->bits[0] += 1;
      s21_get_overflow(value);
    }
  }

  if (value->scale == 0 && value->bits[3] != 0)
    code_error = 1;
  else if (value->scale == 28 && value->bits[0] == 0 && value->bits[1] == 0 &&
           value->bits[2] == 0)
    code_error = 2;

  return code_error;
}

void s21_alignment_scale(work_decimal* value1, work_decimal* value2) {
  int code_error = OK;
  int exit = 0;

  if (value1->scale < value2->scale) {
    while (value1->scale != value2->scale && exit == 0) {
      if ((code_error = s21_comma_shift_left(value1))) exit = 1;
    }
  } else if (value1->scale > value2->scale && exit == 0) {
    while (value2->scale != value1->scale)
      if ((code_error = s21_comma_shift_left(value2))) exit = 1;
  }

  s21_get_overflow(value1);
  s21_get_overflow(value2);
}

s21_decimal* s21_decrease_scale(s21_decimal* value, int shift) {
  for (int i = 0; i < shift; i++) {
    unsigned long long overflow = value->bits[2];
    for (int j = 2; j >= 0; j--) {
      value->bits[j] = overflow / 10;
      overflow =
          (overflow % 10) * (S21_UINT_MAX + 1) + value->bits[j ? j - 1 : j];
    }
  }
  s21_set_scale(value, (s21_get_scale(value) - shift));
  return value;
}

s21_decimal* s21_copy(s21_decimal* dest, s21_decimal src) {
  for (int i = 0; i < 4; i += 1) dest->bits[i] = src.bits[i];
  return dest;
}

int s21_find_point_pos(int len, char* buffer) {
  int point_pos = -1;
  for (int i = 0; i < len; i++) {
    if (buffer[i] == '.' && point_pos == -1) {
      point_pos = i;
    }
  }
  return point_pos;
}

int s21_find_int_part(int point_pos, int len, char* buffer) {
  int int_part = 0;
  for (int i = 0; i < (point_pos == -1 ? len : point_pos); i++) {
    if (isdigit(buffer[i])) {
      int_part = int_part * 10 + (buffer[i] - '0');
    }
  }
  return int_part;
}

int s21_find_frac_part(int point_pos, int len, char* buffer, int* frac_digits) {
  int frac_part = 0;
  if (point_pos != -1) {
    for (int i = point_pos + 1; i < len; i++) {
      if (isdigit(buffer[i])) {
        frac_part = frac_part * 10 + (buffer[i] - '0');
        (*frac_digits)++;
      }
    }
  }
  return frac_part;
}

int s21_power_of_ten(int n) {
  int result = 1;
  for (int i = 0; i < n; i++) {
    result *= 10;
  }
  return result;
}

void s21_simple_sub(work_decimal value_1, work_decimal value_2,
                    s21_decimal* result) {
  for (int i = 0; i < 3; i++) {
    if (value_1.bits[i] < value_2.bits[i] && i != 2) {
      if (value_1.bits[i + 1] == 0) {
        value_1.bits[i + 2] -= 1;
        value_1.bits[i + 1] -= 1;
      } else {
        value_1.bits[i + 1] -= 1;
      }
    }
    result->bits[i] = value_1.bits[i] - value_2.bits[i];
  }
}