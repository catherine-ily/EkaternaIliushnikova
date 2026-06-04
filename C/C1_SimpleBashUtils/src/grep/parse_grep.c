#include "parse_grep.h"

void take_arg(char *optarg, int *error, char (*arguments)[MAX_STR],
              int *flags_num);

int parse_par(int argc, char **argv, char *flag, char (*arguments)[MAX_STR],
              int *flags_num) {
  int error = 0;
  int getopt_res = 0;

  while ((getopt_res = getopt(argc, argv, "e:i:v:c:l:n:h:f:o:s:")) != -1) {
    if (*flag != getopt_res && *flag != 0) {
      error = 1;
    }
    switch (getopt_res) {
      case 'e':
      case 'i':
      case 'v':
      case 'c':
      case 'l':
      case 'n':
      case 'h':
      case 'o':
      case 's':
        if (optarg == NULL) {
          error = 1;
        }
        *flag = getopt_res;
        strcpy(arguments[*flags_num], optarg);
        (*flags_num)++;
        break;
      case 'f':
        if (optarg == NULL) {
          error = 1;
        } else {
          take_arg(optarg, &error, arguments, flags_num);
        }
        *flag = getopt_res;
        break;
      case '?':
        error = 1;
        break;
      default:
        error = 1;
        break;
    }
  }

  return error;
}

void take_arg(char *optarg, int *error, char (*arguments)[MAX_STR],
              int *flags_num) {
  FILE *file = fopen(optarg, "r");
  if (!file) {
    *error = 1;
  } else {
    char line[MAX_STR] = {0};
    int i = 0;
    while (fgets(line, sizeof(line), file) && i < MAX_STR) {
      strcpy(arguments[i], line);
      i++;
    }
    (*flags_num) = i;
  }
}