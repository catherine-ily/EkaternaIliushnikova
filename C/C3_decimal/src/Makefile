CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck -lm -lpthread -lsubunit
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

SRC_DIR = .
BUILD_DIR = build
LIB_NAME = s21_decimal

LIB_SRC = $(SRC_DIR)/$(LIB_NAME).a   
LIB_BUILD = $(BUILD_DIR)/$(LIB_NAME).a

TEST_DIR = tests
TEST_EXEC = $(BUILD_DIR)/test_$(LIB_NAME)
GCOV_EXEC = $(BUILD_DIR)/gcov_$(LIB_NAME)
GCOV_REPORT = $(BUILD_DIR)/coverage_report

SRC = $(wildcard $(SRC_DIR)/s21_*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
GCOV_OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/gcov_%.o,$(SRC))

TEST_CHECK = $(TEST_DIR)/test_$(LIB_NAME).check
TEST_GEN_C = $(BUILD_DIR)/test_$(LIB_NAME).c

.PHONY: all test gcov_report clean

all: clean $(LIB_SRC) test gcov_report 

$(LIB_SRC): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	ar rcs $(LIB_BUILD) $^
	ranlib $(LIB_BUILD)
	cp $(LIB_BUILD) $(LIB_SRC)
	@echo "Библиотека $(LIB_SRC) успешно создана в src/"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_GEN_C): $(TEST_CHECK)
	@mkdir -p $(BUILD_DIR)
	checkmk clean_mode=1 $< > $@

test: $(LIB_SRC) $(TEST_GEN_C)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $(TEST_GEN_C) $(LIB_SRC) $(TEST_FLAGS) -o $(TEST_EXEC)
	$(TEST_EXEC)

$(BUILD_DIR)/gcov_%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

$(GCOV_EXEC): $(GCOV_OBJ) $(TEST_GEN_C)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -I$(SRC_DIR) $(GCOV_OBJ) $(TEST_GEN_C) $(TEST_FLAGS) -o $@

gcov_report: $(GCOV_EXEC)
	@echo "Запуск тестов для сбора покрытия..."
	$(GCOV_EXEC)
	@echo "Сбор данных покрытия..."
	lcov --capture \
	     --directory $(BUILD_DIR) \
	     --output-file $(BUILD_DIR)/coverage.info \
	     --exclude "include/*" \
	     --exclude "*/include/*" \
	     --exclude "/usr/include/*" \
	     
	genhtml $(BUILD_DIR)/coverage.info \
	        --output-directory $(GCOV_REPORT) \
	        --title "Coverage Report" \
	        --ignore-errors source
	@echo "Отчет о покрытии: file://$(shell pwd)/$(GCOV_REPORT)/index.html"
	open $(GCOV_REPORT)/index.html

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(SRC_DIR)/*.gcda $(SRC_DIR)/*.gcno $(SRC_DIR)/*.gcov
	rm -f $(LIB_SRC) 

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.c
	rm -f .clang-format
