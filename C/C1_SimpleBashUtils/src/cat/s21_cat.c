#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "parse.h"
#define MAX_STR 1024

void print_file(FILE *f);
void squeeze_blank(FILE *file);
void number(FILE *file);
void number_nonblank(FILE *file);
void func_e(FILE *file, flag flags);
void print_nonprinting(char ch);
void func_t(FILE *file, flag flags);
void print_e_flag(flag flags, char str[MAX_STR]);

int main(int argc, char **argv) {
  int error = 0;
  flag flags = {0};
  error = parse_par(argc, argv, &flags);

  while (optind < argc && !error) {
    FILE *f = fopen(argv[optind], "r");
    if (f != NULL) {
      if (flags.s)
        squeeze_blank(f);
      else if (flags.n)
        number(f);
      else if (flags.b)
        number_nonblank(f);
      else if (flags.e)
        func_e(f, flags);
      else if (flags.t)
        func_t(f, flags);
      else {
        for (int j = optind; j < argc; j++) {
          print_file(f);
        }
      }
      fclose(f);
    } else
      error = 1;
    optind++;
  }
  if (error) {
    printf("Error");
  }
  return 0;
}

void print_file(FILE *f) {
  if (f != NULL) {
    int c = 0;
    while ((c = fgetc(f)) != EOF) {
      putchar(c);
    }
  }
}

void squeeze_blank(FILE *file) {
  char str[MAX_STR] = {0};
  bool prev_str = false;
  while (fgets(str, sizeof(str), file)) {
    if (strlen(str) == 1) {
      if (!prev_str) {
        prev_str = true;
        printf("%s", str);
      }
    } else {
      prev_str = false;
      printf("%s", str);
    }
  }
}

void number(FILE *file) {
  char str[MAX_STR] = {0};
  int num = 1;
  while (fgets(str, sizeof(str), file)) {
    printf("%6d\t%s", num, str);
    num++;
  }
}

void number_nonblank(FILE *file) {
  char str[MAX_STR] = {0};
  int num = 1;
  while (fgets(str, sizeof(str), file)) {
    if (strlen(str) != 1) {
      printf("%6d\t%s", num, str);
      num++;
    } else
      printf("%s", str);
  }
}

void func_e(FILE *file, flag flags) {
  char str[MAX_STR] = {0};
  int str_num = 0;
  while (fgets(str, sizeof(str), file)) {
    print_e_flag(flags, str);
    str_num++;
  }
}

void print_e_flag(flag flags, char str[MAX_STR]) {
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == '\n') {
      printf("$\n");
    } else {
      if (flags.v) {
        print_nonprinting(str[i]);
      } else
        printf("%c", str[i]);
    }
  }
}

void func_t(FILE *file, flag flags) {
  char str[MAX_STR] = {0};
  while (fgets(str, sizeof(str), file)) {
    for (int i = 0; i < (int)strlen(str); i++) {
      if (str[i] == '\t')
        printf("^I");
      else if (flags.v) {
        print_nonprinting(str[i]);
      } else
        printf("%c", str[i]);
    }
  }
}

void print_nonprinting(char ch) {
  if (ch < -96) {
    printf("M-^%c", ch + 192);
  } else if (ch < 0) {
    printf("%c", ch);
  } else if (ch == 9 || ch == 10) {
    printf("%c", ch);
  } else if (ch < 32) {
    printf("^%c", ch + 64);
  } else if (ch < 127) {
    printf("%c", ch);
  } else {
    printf("^?");
  }
}
