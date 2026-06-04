CC= gcc
CFLAGS= -Wall -Werror -Wextra -std=c11

all: s21_grep

s21_grep: clean parse_grep.o s21_grep.o
	$(CC) $(CFLAGS) s21_grep.o parse_grep.o -o s21_grep

s21_grep.o:
	$(CC) $(CFLAGS) -c s21_grep.c

parse_grep.o:
	$(CC) $(CFLAGS) -c parse_grep.c

clean:
	rm -rf *.o
	rm -rf s21_grep

rebuild: clean all 
