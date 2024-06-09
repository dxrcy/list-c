#include "list.c"

typedef struct string {
    char* items;
    int len;
    int cap;
} string;

string string_new(int cap) {
    string list = {.len = 0, .cap = cap, .items = malloc(cap * sizeof(char))};
    if (list.items == NULL) {
        perror("malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return list;
}

/* void string_push(string* list, char item) { */
/*     // */
/* } */
/*  */
int main() {
    char* a = malloc(sizeof(char) * 20);

    char** b = &a;

    /* *a = 123; */
    printf("%c\n", a[2]);
}
