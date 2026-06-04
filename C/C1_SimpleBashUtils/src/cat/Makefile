CC= gcc
CFLAGS= -Wall -Werror -Wextra -std=c11

all: s21_cat

s21_cat: clean parse.o s21_cat.o
	$(CC) $(CFLAGS) s21_cat.o parse.o -o s21_cat

s21_cat.o: 
	$(CC) $(CFLAGS) -c s21_cat.c

parse.o: 
	$(CC) $(CFLAGS) -c parse.c

clean:
	rm -rf *.o
	rm -rf s21_cat

rebuild: clean all 
