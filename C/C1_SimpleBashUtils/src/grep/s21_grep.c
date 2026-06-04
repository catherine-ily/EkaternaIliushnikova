#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_grep.h"

void grep(const char *pattern, const char *file, int *error,
          char (*output)[MAX_STR], int *num_line, char flag, int not_one_file,
          int *num_all_lines, int *repeat_str);
void print_line(char *line);
void print_file_name(const char *file, int *file_repeat);
void compare_str(const int *num_line, char (*output)[MAX_STR],
                 char line[MAX_STR], int *repeat_str, int *continue_check);
void flag_v_print(int not_one_file, int *file_repeat, const char *file,
                  char line[MAX_STR]);

int main(int argc, char **argv) {
  int error = 0;
  char flag = 0;
  char arguments[MAX_NUM_OF_STR][MAX_STR] = {0};
  int flags_num = 0;

  char output[MAX_NUM_OF_STR][MAX_STR] = {0};
  int num_line = 0;
  int not_one_file = 0;
  int num_all_lines = 0;
  int repeat_str = 0;

  error = parse_par(argc, argv, &flag, arguments, &flags_num);
  if (optind != argc - 1) not_one_file = 1;

  if (argc < 3 || (flags_num > 1 && flag != 'e' && flag != 'f')) {
    error = 1;
  }
  if (!error && flag == 0) {
    for (int j = 2; j < argc; j++) {
      grep(argv[1], argv[j], &error, output, &num_line, flag, not_one_file,
           &num_all_lines, &repeat_str);
    }
  }
  if (!error && flag != 0) {
    for (int j = optind; j < argc; j++) {
      for (int i = 0; i < flags_num; i++) {
        grep(arguments[i], argv[j], &error, output, &num_line, flag,
             not_one_file, &num_all_lines, &repeat_str);
      }

      if (flag == 'c') {
        printf("%d\n", num_line);
      }
      num_line = 0;
      num_all_lines = 0;
      repeat_str = 0;
    }
  }
  if (error) {
    printf("Error\n");
  }
  return 0;
}

void grep(const char *pattern, const char *file, int *error,
          char (*output)[MAX_STR], int *num_line, char flag, int not_one_file,
          int *num_all_lines, int *repeat_str) {
  FILE *f = fopen(file, "r");

  if (f) {
    int continue_check = 0;
    int file_repeat = 0;
    char line[MAX_STR] = {0};
    regex_t regex = {0};

    if (flag == 'i') {
      regcomp(&regex, pattern, REG_ICASE | REG_EXTENDED);
    } else {
      regcomp(&regex, pattern, REG_EXTENDED);
    }

    while (fgets(line, sizeof(line), f)) {
      int match = regexec(&regex, line, 0, NULL, 0);
      compare_str(num_line, output, line, repeat_str, &continue_check);
      continue_check = 0;

      if (match == 0 && !(*repeat_str) && flag != 'v') {
        if (not_one_file == 1 && flag != 'l' && !file_repeat && flag != 'h')
          print_file_name(file, &file_repeat);
        if (flag == 'n') printf("%d:", (*num_all_lines) + 1);
        if (flag != 'c' && flag != 'l' && flag != 'o') print_line(line);
        if (flag == 'l' && !file_repeat) {
          printf("%s\n", file);
          file_repeat = 1;
        }
        if (flag == 'o') {
          char temp[MAX_STR] = {0};
          strcpy(temp, pattern);
          print_line(temp);
        }
        strcpy(output[*num_line], line);
        (*num_line)++;
      }

      if (match != 0 && flag == 'v')
        flag_v_print(not_one_file, &file_repeat, file, line);
      (*num_all_lines)++;
      if (flag != 'c' && flag != 'l') file_repeat = 0;
    }
    regfree(&regex);
    fclose(f);
  } else if (flag != 's') {
    *error = 1;
  }
}

void flag_v_print(int not_one_file, int *file_repeat, const char *file,
                  char line[MAX_STR]) {
  if (not_one_file == 1 && !(*file_repeat)) {
    print_file_name(file, file_repeat);
  }
  print_line(line);
}

void print_line(char *line) {
  int i = 0;
  for (i = 0; line[i] != '\0'; i++) {
    printf("%c", line[i]);
  }
  if (line[i - 1] != '\n' && line[i - 2] != '\n') {
    printf("\n");
  }
}

void print_file_name(const char *file, int *file_repeat) {
  printf("%s:", file);
  *file_repeat = 1;
}

void compare_str(const int *num_line, char (*output)[MAX_STR],
                 char line[MAX_STR], int *repeat_str, int *continue_check) {
  for (int i = 0; i < *num_line; i++) {
    if (strcmp(output[i], line) == 0) {
      *repeat_str = 1;
      *continue_check = 1;
    } else if (*continue_check == 0) {
      *repeat_str = 0;
    }
  }
}