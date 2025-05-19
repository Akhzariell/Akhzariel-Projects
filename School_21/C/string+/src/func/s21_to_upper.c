#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *new_str = NULL;

  if (str != NULL) {
    int size = strlen(str);
    // размер выделяемой памяти

    new_str = malloc((size + 1) * sizeof(char));
    // Выделение памяти с учётом '\0'
    if (new_str != NULL) {
      strncpy(new_str, str, size);
      new_str[size] = '\0';
      // Гарантируем завершающий нулевой символ

      // Преобразуем символы в верхний регистр
      for (int i = 0; new_str[i] != '\0'; i++) {
        if (new_str[i] >= 'a' && new_str[i] <= 'z') {
          new_str[i] -= 32;
          // Преобразование в верхний регистр
        }
      }
    }
  }

  return new_str;
}