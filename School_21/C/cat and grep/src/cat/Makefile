CC=gcc
OS = $(shell)

CFLAGS= -Wall -Wextra -Werror -std=c11 -g


all: check s21_cat 

s21_cat: s21_cat.o
	clang-format -i *.c
	clang-format -i *.h
	$(CC) $(CFLAGS) s21_cat.o -o s21_cat

check:
	clang-format -n *.c
	clang-format -n *.h

test: all
	bash ./TESTS/test.sh

rebuild: clean all

clean:
	rm -rf *.o s21_cat 
