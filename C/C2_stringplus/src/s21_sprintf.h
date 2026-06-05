#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...);
int get_sub_format(char *str, va_list *args, char *sub_format,
                   int len_sub_format);
int convert_int_to_str(char *str, long long int num_int);
int convert_float_to_str(char *str, double num_double, char *accuracy);
int convert_str_to_int(char *str);
int get_accuracy(char *sub_format, char *accuracy);
int get_flag(char *sub_format, char *flag);
int get_width(char *sub_format, char *width);
int get_length(char *sub_format, char *length);
int change_sign_flag(char *str, const char *flag);
int change_width_and_flag_minus(char *str, char *width, char *flag);
int change_accuracy(char *str, char spec, char *accuracy);
