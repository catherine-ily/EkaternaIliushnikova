#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list args;
  va_start(args, format);
  int len_buffer = (int)s21_strlen(format);
  char *buffer = malloc((2 * len_buffer + 1) * sizeof(char));
  char specifier[] = "cdieEfgGosuxXpn";
  int curr = 0;
  int isPerc = 0;
  char *sub_format = malloc(s21_strlen(format) + 1);
  int len_sub_format = 0;
  char sym[2];
  sym[1] = '\0';
  int skip_percent = 0;
  while (curr < len_buffer) {
    if (isPerc == 0) {
      if (format[curr] == '%') {
        sub_format[len_sub_format++] = format[curr];
        isPerc = 1;
      } else {
        sym[0] = format[curr];
        s21_strncat(str, sym, 1);
      }
    } else {
      if (format[curr] == '%') {
        skip_percent = 1;
        sym[0] = format[curr];
        s21_strncat(str, sym, 1);
        isPerc = 0;
      }
      if (skip_percent == 0) sub_format[len_sub_format++] = format[curr];
      if (s21_strchr(specifier, format[curr]) != S21_NULL &&
          skip_percent == 0) {
        sub_format[len_sub_format] = '\0';
        get_sub_format(buffer, &args, sub_format, len_sub_format);
        s21_strncat(str, buffer, (int)s21_strlen(buffer));
        len_sub_format = 0;
        sub_format[0] = '\0';
        buffer[0] = '\0';
        isPerc = 0;
      }
    }
    skip_percent = 0;
    curr++;
  }
  free(sub_format);
  free(buffer);
  va_end(args);
  return (int)s21_strlen(str);
}

int get_sub_format(char *str, va_list *args, char *sub_format,
                   int len_sub_format) {
  char accuracy[30], width[30], flag[2], length[2], sym = 0, *s = 0;
  unsigned int num_u = 0;
  get_accuracy(sub_format, accuracy);
  get_flag(sub_format, flag);
  get_length(sub_format, length);
  get_width(sub_format, width);
  switch (sub_format[len_sub_format - 1]) {
    case 'c':
      sym = va_arg(*args, int);
      str[0] = sym;
      str[1] = '\0';
      break;
    case 'd':
      if (length[0] == 'h') {
        short num_short = va_arg(*args, int);
        convert_int_to_str(str, num_short);
      } else if (length[0] == 'l') {
        long num_long = va_arg(*args, long);
        convert_int_to_str(str, num_long);
      } else {
        int num_int = va_arg(*args, int);
        convert_int_to_str(str, num_int);
      }
      break;
    case 'f':
      if (length[0] == 'l') {
        double num_double = va_arg(*args, double);
        convert_float_to_str(str, num_double, accuracy);
      } else {
        float num_float = va_arg(*args, double);
        convert_float_to_str(str, num_float, accuracy);
      }
      break;
    case 's':
      s = va_arg(*args, char *);
      s21_strncpy(str, s, s21_strlen(s));
      str[s21_strlen(s)] = '\0';
      if (length[0] == 'l') str[0] = '\0';
      break;
    case 'u':
      num_u = va_arg(*args, unsigned int);
      convert_int_to_str(str, num_u);
      break;
  }
  change_accuracy(str, sub_format[len_sub_format - 1], accuracy);
  if (sub_format[len_sub_format - 1] == 'd' ||
      sub_format[len_sub_format - 1] == 'f')
    change_sign_flag(str, flag);
  if (s21_strlen(width) != 0) change_width_and_flag_minus(str, width, flag);
  return 0;
}

int convert_int_to_str(char *str, long long int num_int) {
  int len = 0;
  if (num_int < 0) {
    num_int *= -1;
    len++;
    str[0] = '-';
  }
  long long int num_int_copy = num_int;
  while (num_int_copy >= 1) {
    len++;
    num_int_copy = num_int_copy / 10;
  }
  if (num_int == 0) {
    str[0] = '0';
    str[1] = '\0';
  } else {
    int curr = 0;
    while (num_int >= 1) {
      str[len - curr - 1] = (num_int % 10) + 48;
      num_int = num_int / 10;
      curr++;
    }
    str[len] = '\0';
  }
  return 0;
}

int change_accuracy(char *str, char spec, char *accuracy) {
  int accuracy_int = convert_str_to_int(accuracy);
  int len_str = (int)s21_strlen(str);
  char str_zero[512] = "";
  char str_minus[2] = "";
  char str_new[512] = "";
  if (spec == 'd' || spec == 'u') {
    if (accuracy_int > len_str) {
      if (str[0] == '-') {
        str_minus[0] = '-';
        str_minus[1] = '\0';
        s21_memset(str_zero, '0', accuracy_int - len_str + 1);
        str_zero[accuracy_int - len_str + 1] = '\0';
      } else {
        s21_memset(str_zero, '0', accuracy_int - len_str);
        str_zero[accuracy_int - len_str] = '\0';
      }
      s21_strncat(str_new, str_minus, s21_strlen(str_minus));
      s21_strncat(str_new, str_zero, s21_strlen(str_zero));
      int length = (int)s21_strlen(str_new);
      for (int i = 0; i <= (int)s21_strlen(str); i++) {
        if (str[i] != '-') {
          str_new[length++] = str[i];
        }
      }
      s21_strncpy(str, str_new, s21_strlen(str_new));
      str[s21_strlen(str_new)] = '\0';
    }
    if (accuracy_int == 0 && s21_strncmp(str, "0", 2) == 0 &&
        s21_strlen(accuracy) > 0) {
      str[accuracy_int] = '\0';
    }
  } else if (spec == 's') {
    if (accuracy_int < len_str && (int)s21_strlen(accuracy) != 0) {
      str[accuracy_int] = '\0';
    }
  }
  return 0;
}

int convert_float_to_str(char *str, double num_double, char *accuracy) {
  str[0] = '\0';
  int accuracy_int = 0;
  if (s21_strlen(accuracy) == 0) {
    accuracy_int = 6;
  } else {
    accuracy_int = convert_str_to_int(accuracy);
  }
  char str_left[100];
  char str_right[100];
  long long int num_int = num_double;
  long long int num_point = 0;
  long long int ymn = 10;
  double num_double_new = num_double - (double)num_int + 1;
  long long int curr_num = 0;
  int cnt_zero = 0;
  for (int i = 0; i <= accuracy_int; i++) {
    curr_num = fabs(ymn * num_double_new - ymn);
    num_point = num_point * 10 + curr_num % 10;
    ymn *= 10;
    if (num_point == 0 && curr_num == 0) {
      cnt_zero++;
    }
  }
  if ((num_point % 10) >= 5 && accuracy_int != 0) {
    num_point = num_point / 10 + 1;
  } else if (accuracy_int != 0) {
    num_point = num_point / 10;
  }
  if (accuracy_int == 0 && num_point >= 5) {
    if (num_double < 0) num_int--;
    if (num_double > 0) num_int++;
  }
  char str_zero[256];
  s21_memset(str_zero, '0', cnt_zero);
  str_zero[cnt_zero] = '\0';
  convert_int_to_str(str_left, num_int);
  convert_int_to_str(str_right, num_point);
  char str_point[2];
  str_point[0] = '.';
  str_point[1] = '\0';
  if (accuracy_int == 0) {
    str_right[0] = '\0';
    str_point[0] = '\0';
  }
  s21_strncat(str, str_left, s21_strlen(str_left));
  s21_strncat(str, str_point, s21_strlen(str_point));
  s21_strncat(str, str_zero, s21_strlen(str_zero));
  s21_strncat(str, str_right, s21_strlen(str_right));
  return 0;
}

int convert_str_to_int(char *str) {
  int len_str = (int)s21_strlen(str);
  int num = 0;
  int ymn = 1;
  for (int i = (len_str - 1); i >= 0; i--) {
    num += (str[i] - '0') * ymn;
    ymn *= 10;
  }
  return num;
}

int get_accuracy(char *sub_format, char *accuracy) {
  char target[] = "cdieEfgGosuxXpnhl";
  int curr = 1;
  int go = 0;
  int len_accuracy = 0;
  while (s21_strchr(target, sub_format[curr]) == S21_NULL) {
    if (go == 1) {
      accuracy[len_accuracy++] = sub_format[curr];
    }
    if (sub_format[curr] == '.') {
      go = 1;
    }
    curr++;
  }
  if (go == 1 && len_accuracy == 0) {
    accuracy[len_accuracy++] = '0';
  }
  accuracy[len_accuracy] = '\0';
  return len_accuracy;
}

int get_flag(char *sub_format, char *flag) {
  int len = 1;
  flag[1] = '\0';
  if (sub_format[1] == '-') {
    flag[0] = '-';
  } else if (sub_format[1] == '+') {
    flag[0] = '+';
  } else if (sub_format[1] == ' ') {
    flag[0] = ' ';
  } else if (sub_format[1] == '#') {
    flag[0] = '#';
  } else if (sub_format[1] == '0') {
    flag[0] = '0';
  } else {
    flag[0] = '\0';
    len = 0;
  }

  return len;
}

int get_width(char *sub_format, char *width) {
  char target[] = "hlL.cdieEfgGosuxXpn";
  int curr = 1;
  int len_width = 0;
  if (s21_strchr("-+ #0", sub_format[1]) != S21_NULL) {
    curr++;
  }
  while (s21_strchr(target, sub_format[curr]) == S21_NULL) {
    width[len_width++] = sub_format[curr];
    curr++;
  }
  width[len_width] = '\0';
  return len_width;
}

int get_length(char *sub_format, char *length) {
  int len = 1;
  length[1] = '\0';
  if (s21_strchr(sub_format, 'h') != S21_NULL) {
    length[0] = 'h';
  } else if (s21_strchr(sub_format, 'l') != S21_NULL) {
    length[0] = 'l';
  } else if (s21_strchr(sub_format, 'L') != S21_NULL) {
    length[0] = 'L';
  } else {
    length[0] = '\0';
    len = 0;
  }
  return len;
}

int change_sign_flag(char *str, const char *flag) {
  char str_new[256];
  int start = 0;
  if (flag[0] == '+') {
    if (str[0] != '-') {
      str_new[0] = '+';
      start = 1;
    }
  } else if (flag[0] == ' ') {
    if (str[0] != '-') {
      str_new[0] = ' ';
      start = 1;
    }
  }
  str_new[(int)s21_strlen(str) + start] = '\0';
  s21_strncpy(str_new + start, str, (int)s21_strlen(str));
  s21_strncpy(str, str_new, (int)s21_strlen(str_new));
  str[s21_strlen(str_new)] = '\0';

  return 0;
}

int change_width_and_flag_minus(char *str, char *width, char *flag) {
  int width_int = convert_str_to_int(width);
  int len_str = (int)s21_strlen(str);
  if (width_int > len_str) {
    char sym = ' ';
    char str_add[256];
    for (int i = 0; i < (width_int - len_str); i++) {
      str_add[i] = sym;
    }
    str_add[width_int - len_str] = '\0';
    if (flag[0] == '-') {
      s21_strncat(str, str_add, s21_strlen(str_add));
    } else {
      s21_strncat(str_add, str, s21_strlen(str));
      s21_strncpy(str, str_add, s21_strlen(str_add));
      str[s21_strlen(str_add)] = '\0';
    }
  }
  return 0;
}
