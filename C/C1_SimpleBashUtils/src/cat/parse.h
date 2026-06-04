#ifndef PARSE_H
#define PARSE_H

#include <getopt.h>
#include <stdio.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flag;

int parse_par(int argc, char **argv, flag *flags);

#endif