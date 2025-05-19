#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {

  char *new = NULL;

  if (str && src && start_index <= strlen(src)) {

    int new_length = strlen(src) + strlen(str) + 1; // -1 лишний символ '\0'
    new = malloc(sizeof(char) *
                 new_length); // создается буфер длинной в 2 строки и 1 '\0'

    size_t i = 0;

    for (; i < start_index; i++) { // до индекса (ориг строка)
      new[i] = src[i];
    }

    for (size_t j = 0; j < strlen(str); j++) { // строка вставки
      new[i++] = str[j];
    }

    for (size_t j = start_index; j < strlen(src);
         j++) { // строка оригинала с индекса
      new[i++] = src[j];
    }

    new[new_length - 1] = '\0';
  }

  return new;
}
