.PHONY: all test s21_string.a clang clean cppcheck rebuild valgrind gcov_report
CFLAGS = -Wall -Wextra -Werror -std=c11
TFLAGS = -fprofile-arcs -ftest-coverage -pedantic
OS = $(shell uname -s)
LINUX = -lsubunit -lrt
LIBS = -lcheck -lm

ifeq ($(OS), Linux)
	OPEN = xdg-open
else
	OPEN = open
endif

all: s21_string.a

test: clean_test s21_string.a
ifeq ($(OS), Darwin)
	gcc $(CFLAGS) $(TFLAGS) -g s21_string.c s21_sprintf.c tests/*.c s21_string.a -o unit_test $(LIBS) 
else
	gcc $(CFLAGS) $(TFLAGS) -g s21_string.c s21_sprintf.c tests/*.c s21_string.a -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test

gcov_report: clean_test s21_string.a
ifeq ($(OS), Darwin)
	gcc $(CFLAGS) $(TFLAGS) -g s21_string.c s21_sprintf.c tests/*.c s21_string.a -o unit_test $(LIBS) 
else
	gcc  $(CFLAGS) $(TFLAGS) -g s21_string.c s21_sprintf.c tests/*.c s21_string.a -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test
	lcov -t "unit_test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN) report/index.html

s21_string.a:
	gcc -c s21_string.c s21_sprintf.c
	ar rcs s21_string.a s21_*.o
	ranlib s21_string.a

clang:
	clang-format -n *.c tests/*.c 
	clang-format -n *.h tests/*.h

valgrind: 
	valgrind --log-file=log.txt --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./unit_test
	grep errors log.txt -n

leaks:
	leaks -atExit -- ./unit_test

clean_obj:
	rm -rf *.o

clean_lib:
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.dSYM

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test
	rm -rf log.txt

rebuild: clean all