FLAGS = -Wall -Werror -Wextra -std=c11
SRCS = $(wildcard s21*.c)
TESTS_SRC_FILES = $(wildcard test/*.c)

UNAME := $(shell uname -s)

ifeq ($(UNAME),Linux)
    TEST_FLAGS = -lcheck_pic -pthread -lrt -lm -lsubunit
    OPEN_CMD = xdg-open
    LEAKS_CMD = valgrind --leak-check=full ./test_runner
else
    TEST_FLAGS =  -lcheck -lm
    OPEN_CMD = open
    LEAKS_CMD = leaks -atExit -- ./test_runner | grep LEAK:
endif

all: s21_matrix.a

clean:
	rm -f *.o *.a coverage.info
	rm -f *.gcno *.gcda test_runner
	rm -rf gcov_report report

s21_matrix.a: $(SRCS)
	gcc $(FLAGS) -c $(SRCS)
	ar rcs s21_matrix.a *.o
	rm *.o

test: $(TESTS_SRC_FILES) s21_matrix.a
	gcc $(FLAGS) $(TESTS_SRC_FILES) s21_matrix.a -o test_runner $(TEST_FLAGS)
	./test_runner

gcov_report: clean
	gcc $(FLAGS) --coverage  $(TESTS_SRC_FILES) $(SRCS) -o test_runner $(TEST_FLAGS)
	-./test_runner
	lcov -o coverage.info -c -d . --include "*/s21_*.c" 
	genhtml -o report coverage.info 
	$(OPEN_CMD) report/index.html 
	
leaks: test
	$(LEAKS_CMD)

clang:
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -n *.c *.h test/*.c test/*.h
	clang-format -i *.c *.h test/*.c test/*.h
	rm -f .clang-format 

rebuild: clean all


	
