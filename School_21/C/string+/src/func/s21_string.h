#ifndef INSERT
#define INSERT

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);

#endif