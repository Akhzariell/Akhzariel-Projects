#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_src = NULL;

  if (src) {
    size_t len = strlen(src);
    const char *start = src;
    const char *end = src + len - 1;

    if (trim_chars) {
      while (*start && strchr(trim_chars, *start)) start++;
      while (end >= start && strchr(trim_chars, *end)) end--;
    } else {
      while (*start && isspace((unsigned char)*start)) start++;
      while (end >= start && isspace((unsigned char)*end)) end--;
    }

    size_t new_len = (start > end) ? 0 : (end - start + 1);
    new_src = malloc(new_len + 1);
    if (new_src) {
      memcpy(new_src, start, new_len);
      new_src[new_len] = '\0';
    }
  }

  return new_src;
}
