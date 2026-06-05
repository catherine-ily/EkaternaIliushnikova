#include "s21_string.h"

#include <stdio.h>

#include "s21_sprintf.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  const unsigned char *ptr = (const unsigned char *)str;
  unsigned char ch = (unsigned char)c;

  for (s21_size_t i = 0; i < n && result == S21_NULL; i++) {
    if (ptr[i] == ch) {
      result = (void *)(ptr + i);
    }
  }
  return result;
}

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  const unsigned char *a = (const unsigned char *)s1;
  const unsigned char *b = (const unsigned char *)s2;

  for (s21_size_t i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      return a[i] - b[i];
    }
  }

  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *d = dest;
  while (*d != '\0') {
    d++;
  }

  s21_size_t i = 0;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    *d = src[i];
    d++;
  }
  *d = '\0';

  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  int end = 0;
  while (*str != '\0' && end != 1) {
    if (*str == (char)c) {
      result = (char *)str;
      end = 1;
    }
    str++;
  }
  if ((char)c == '\0') result = (char *)str;
  return result;
}

int s21_strncmp(const char *s1, const char *s2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;
  int flag = 0;

  while (i < n && !flag) {
    unsigned char str1 = (unsigned char)s1[i];
    unsigned char str2 = (unsigned char)s2[i];

    if (str1 == '\0' && str2 == '\0') {
      flag = 1;
    } else if (str1 != str2) {
      result = (str1 > str2) ? 1 : -1;
      flag = 1;
    } else {
      i++;
    }
  }

  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  while (i < n) {
    dest[i] = '\0';
    i++;
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t length = 0;
  const char *p = 0;
  int stop = 0;

  while (str1[length] != '\0' && !stop) {
    for (p = str2; *p != '\0'; p++) {
      if (str1[length] == *p) {
        stop = 1;
      }
    }
    if (!stop) length++;
  }

  return length;
}

#ifdef __APPLE__
char *s21_strerror(int errnum) {
  static const char *strerr[] = s21_error;
  static char s21_undef[BUFF_SIZE] = {'\0'};
  const char *res = 0;

  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
    s21_sprintf(s21_undef, "Unknown error: %d", errnum);
    res = s21_undef;
  } else if (errnum == 0) {
    res = "Undefined error: 0";
  } else {
    res = strerr[errnum];
  }

  return (char *)res;
}

#else
char *s21_strerror(int errnum) {
  static const char *strerr[] = s21_error;
  static char s21_undef[BUFF_SIZE] = {'\0'};
  const char *res = 0;
  if (errnum < 0 || errnum >= S21_ERRLIST_SIZE) {
    s21_sprintf(s21_undef, "Unknown error %d", errnum);
    res = s21_undef;

  } else
    res = strerr[errnum];
  return (char *)res;
}
#endif

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int stop = 0;
  char *result = S21_NULL;
  while (*str1 != '\0') {
    const char *s = str2;
    while (*s != '\0' && !stop) {
      if (*str1 == *s) {
        result = (char *)str1;
        stop = 1;
      }
      s++;
    }
    str1++;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *answer = S21_NULL;

  while (*str != '\0') {
    if (*str == (char)c) {
      answer = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    answer = (char *)str;
  }

  return answer;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int found = 0;

  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    for (const char *h = haystack; *h != '\0' && !found; h++) {
      const char *current_haystack = h;
      const char *current_needle = needle;

      while (*current_haystack != '\0' && *current_needle != '\0' &&
             *current_haystack == *current_needle) {
        current_haystack++;
        current_needle++;
      }

      if (*current_needle == '\0') {
        result = (char *)h;
        found = 1;
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = S21_NULL;
  char *token_start = S21_NULL;

  if (str == S21_NULL) {
    str = ptr;
  }

  while (str && *str && s21_strchr(delim, *str)) {
    str++;
  }

  if (str == S21_NULL || *str == '\0') {
    ptr = S21_NULL;
    token_start = S21_NULL;
  } else {
    token_start = str;

    while (*str && !s21_strchr(delim, *str)) {
      str++;
    }

    if (*str) {
      *str = '\0';
      ptr = str + 1;
    } else {
      ptr = S21_NULL;
    }
  }

  return token_start;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  s21_size_t length = s21_strlen(str);
  char *result = (char *)malloc((length + 1) * sizeof(char));

  if (result == S21_NULL) return S21_NULL;

  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - ('a' - 'A');
    } else {
      result[i] = str[i];
    }
  }

  result[length] = '\0';
  return (void *)result;
}

void *s21_to_lower(const char *str) {
  char *arr_cpy = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);
    arr_cpy = (char *)malloc(length + 1);

    if (arr_cpy != S21_NULL) {
      for (s21_size_t i = 0; i < length; i++) {
        arr_cpy[i] =
            (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
      }
      arr_cpy[length] = '\0';
    }
  }
  return (void *)arr_cpy;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    s21_size_t len_result = len_src + len_str + 1;

    if (start_index <= len_src) {
      result = malloc(len_result * sizeof(char));

      if (result) {
        s21_memcpy(result, src, start_index);
        s21_memcpy(result + start_index, str, len_str);
        s21_memcpy(result + start_index + len_str, src + start_index,
                   len_src - start_index);
        result[len_result - 1] = '\0';
      }
    }
  }

  return (void *)result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL) {
    return S21_NULL;
  }
  if (trim_chars == S21_NULL) {
    trim_chars = " \n\t";
  }

  unsigned long end_idx = s21_strlen(src);
  unsigned long start_idx = 0;

  while (start_idx < end_idx && s21_strchr(trim_chars, (int)src[start_idx])) {
    start_idx++;
  }

  while (end_idx > start_idx && s21_strchr(trim_chars, (int)src[end_idx])) {
    end_idx--;
  }

  unsigned long result_length = end_idx - start_idx + 1;

  if (result_length > 0) {
    char *result = calloc(result_length + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src + start_idx, result_length);
      result[result_length] = '\0';
      return result;
    }
  } else {
    return calloc(1, sizeof(char));
  }

  return S21_NULL;
}
