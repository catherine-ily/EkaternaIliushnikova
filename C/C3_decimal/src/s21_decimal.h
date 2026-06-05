#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h> 
#include <stdlib.h> 

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef struct {
    uint64_t bits[7];
    short scale;
} work_decimal;

enum state { FALSE = 0, TRUE = 1};
enum errors { OK = 0, ERROR = 1};

#define S21_SIGN_MASK 0x80000000
#define S21_SCALE_MASK 0b11111111
#define MAXBITS 0xffffffff
#define S21_MAX_SCALE 28
#define S21_UINT_MAX 4294967295


// Арифметика
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Сравнение
int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);

// Преобразователи
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// Другие функции
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_floor(s21_decimal value, s21_decimal *result);

// Вспомогательные функции
int s21_get_sign(s21_decimal *value);
int s21_get_scale(s21_decimal *value);
int s21_get_bit_ext(work_decimal *value, int position);
int s21_get_bit(s21_decimal *value, int position);
void s21_set_sign(s21_decimal *value, int sign);
void s21_set_scale(s21_decimal *value, int scale);
void s21_set_bit_ext(work_decimal *value, int position, int bit);
int s21_init_decimal(s21_decimal *dst);
work_decimal s21_decimal_to_work_decimal(s21_decimal *src);
void s21_convert_from_work_decimal(work_decimal value, s21_decimal *dst);

int s21_comma_shift_right(work_decimal *value);
int s21_comma_shift_left(work_decimal *value);
int s21_get_overflow(work_decimal *value);
void s21_alignment_scale(work_decimal *value1, work_decimal *value2);
int s21_normalization(work_decimal *value);

void s21_simple_sub(work_decimal value_1, work_decimal value_2, s21_decimal *result);

//Вспомогательные для других функций
s21_decimal *s21_decrease_scale(s21_decimal *value, int shift);
s21_decimal* s21_copy(s21_decimal* dest, s21_decimal src);

// Вспомогательные для преобразователей
int s21_find_point_pos(int len, char *buffer);
int s21_find_int_part(int point_pos, int len, char *buffer);
int s21_find_frac_part(int point_pos, int len, char *buffer, int *frac_digits);
int s21_power_of_ten(int n);




#endif 
