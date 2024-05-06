#include "list.c"

mklist(string, char)

    int main() {
  string list = string_from("abcdef", 6);

  for (int i = 0; i < list.len; i++) {
    printf("%c", list.items[i]);
  }
  printf("\n");

  char ch = string_remove(&list, 2);
  printf("%c\n", ch);

  for (int i = 0; i < list.len; i++) {
    printf("%c", list.items[i]);
  }
  printf("\n");

  free(list.items);
}
