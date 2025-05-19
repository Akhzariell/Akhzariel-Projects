CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -c -fprofile-arcs -ftest-coverage

AR = ar
ARFLAGS = rcs

FUNC_DIR = func/
DEPS_DIR = deps/
OBJ_DIR = obj/

SOURCES = func/s21_insert.c func/s21_to_lower.c func/s21_to_upper.c func/s21_trim.c

OBJECTS = $(addprefix $(OBJ_DIR),$(SOURCES:$(FUNC_DIR)%.c=%.o))
DEPS = $(addprefix $(DEPS_DIR),$(SOURCES:$(FUNC_DIR)%.c=%.d))

UNIT = unit.check
TEST = $(UNIT:.check=.c)

TARGET = libs21_string.a

all: $(TARGET)

-include $(DEPS)

$(TARGET): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET) unit.c test *.gcda *.gcno  *info *Identifier
	rm -rf out obj deps

test: $(TEST) $(TARGET)
	$(CC) $< -Ifunc -L. -ls21_string -lcheck -lsubunit -lrt -lm -lpthread -fprofile-arcs -ftest-coverage -o $@
	valgrind -q ./$@
#

gcov: test
	lcov --directory . --capture --output-file coverage.info
	genhtml coverage.info --ignore-errors unmapped,unmapped --output-directory out
	cd out
	python3 -m http.server 8000

	
$(TEST): $(UNIT)
	checkmk $< > $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

$(OBJ_DIR)%.o: $(FUNC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(DEPS_DIR)%.d: $(FUNC_DIR)%.c | $(DEPS_DIR)
	$(CC) -M $< > $@
