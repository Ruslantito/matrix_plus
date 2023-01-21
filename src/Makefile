# PROJECT
# CPP MATRIX OOP

# GLOBAL
OS := $(shell uname)

# SOURCE, OBJECT AND TEST FILES / FOLDERS
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, obj/%.o, $(SRC))
TARGET = s21_matrix_oop.a
TARGET_H = s21_matrix_oop.h
TEST_FOLDER = tests
TEST_OUTPUT = test

# GCC SETTINGS
COMPILATOR = g++ -g
FLAGS_BASIC = -Wall -Wextra -Werror --std=c++17 -pedantic
FLAGS_EXTRA = $(FLAGS_BASIC) -fsanitize=address,undefined,leak
ifeq ($(OS),Linux)
	FLAGS_EXTRA = $(FLAGS_BASIC)
endif
FLAGS_CHECK = -lgtest -pthread -lgcov
FLAGS_COV = $(FLAGS_CHECK) -fprofile-arcs -ftest-coverage

# FILETYPES FOR CLEAN AND FCLEAN TARGETS
GCOV_INFO = gcov_report.info
GCOV_FOLDER = report
VALGRIND_LOG = _valgrind-out.txt
TMP_FILES = $(GCOV_INFO) *.gcda *.gcno *.gcda obj/*.gcno obj/*.gcda *.gcov *.out $(TEST_OUTPUT).dSYM
REST_FILES = $(TARGET) $(GCOV_FOLDER) ./$(TEST_OUTPUT) $(VALGRIND_LOG) obj/*.o


obj/%.o: %.cc
	$(COMPILATOR) $(FLAGS_EXTRA) $(FLAGS_COV) -c $< -o $@

$(TARGET): $(OBJ)
	ar rcs $(TARGET) $(OBJ)
	ranlib $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TMP_FILES)

.PHONY: fclean
fclean: clean
	rm -rf $(REST_FILES)

.PHONY: test
test: $(TARGET)
	$(COMPILATOR) $(TEST_FOLDER)/*.cc $(TARGET) -o $(TEST_OUTPUT) $(FLAGS_EXTRA) $(FLAGS_COV)
	./$(TEST_OUTPUT)

.PHONY: gcov_report
gcov_report: test
	lcov -t "gcov_report" -o $(GCOV_INFO) -c -d . --no-external && \
	genhtml -o $(GCOV_FOLDER) $(GCOV_INFO) && \
	$(MAKE) clean && \
	open $(GCOV_FOLDER)/index.html

.PHONY: lint
lint:
	clang-format -n $(SRC) $(TARGET_H) $(TEST_FOLDER)/*.cc
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=missingIncludeSystem --suppress=unusedFunction $(SRC) $(TARGET_H) $(TEST_FOLDER)/*.cc

.PHONY: format
format:
	clang-format -i $(SRC) $(TARGET_H) $(TEST_FOLDER)/*.cc

.PHONY: grind
grind: FLAGS_EXTRA = $(FLAGS_BASIC)
grind: fclean test
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --log-file=$(VALGRIND_LOG) ./$(TEST_OUTPUT)
	$(MAKE) clean
