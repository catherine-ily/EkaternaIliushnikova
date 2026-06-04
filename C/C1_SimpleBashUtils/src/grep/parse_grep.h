#ifndef PARSE_H
#define PARSE_H

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR 1024
#define MAX_NUM_OF_STR 50

int parse_par(int argc, char **argv, char *flag, char (*arguments)[MAX_STR],
              int *flags_num);

#endif