#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define cap_increase(x) (x * 2)

#define mklist(__list, __item)                                               \
    typedef struct __list {                                                  \
        __item *items;                                                       \
        unsigned int len;                                                    \
        unsigned int cap;                                                    \
    } __list;                                                                \
    __list __list##_new(unsigned int cap) {                                  \
        __list list = {                                                      \
            .len = 0,                                                        \
            .cap = cap,                                                      \
            .items = malloc(cap * sizeof(__item)),                           \
        };                                                                   \
        if (list.items == NULL) {                                            \
            perror("malloc failed.\n");                                      \
            exit(EXIT_FAILURE);                                              \
        }                                                                    \
        return list;                                                         \
    }                                                                        \
    __list __list##_from(__item *items, unsigned int len) {                  \
        __list list = {                                                      \
            .len = len,                                                      \
            .cap = len,                                                      \
            .items = malloc(len * sizeof(__item)),                           \
        };                                                                   \
        if (list.items == NULL) {                                            \
            perror("malloc failed.\n");                                      \
            exit(EXIT_FAILURE);                                              \
        }                                                                    \
        for (int i = 0; i < len; i++) {                                      \
            list.items[i] = items[i];                                        \
        }                                                                    \
        return list;                                                         \
    }                                                                        \
    __list *__list##_push(__list *list, __item item) {                       \
        if (list->len + 1 > list->cap) {                                     \
            list->cap = cap_increase(list->cap);                             \
            list->items = realloc(list->items, list->cap * sizeof(__item));  \
            if (list->items == NULL) {                                       \
                perror("realloc failed.\n");                                 \
                exit(EXIT_FAILURE);                                          \
            }                                                                \
        }                                                                    \
        list->items[list->len] = item;                                       \
        list->len++;                                                         \
        return list;                                                         \
    }                                                                        \
    __list *__list##_append(__list *list, __item *items, unsigned int len) { \
        if (list->len + len > list->cap) {                                   \
            list->cap = cap_increase(list->cap + len);                       \
            list->items = realloc(list->items, list->cap * sizeof(__item));  \
            if (list->items == NULL) {                                       \
                perror("realloc failed.\n");                                 \
                exit(EXIT_FAILURE);                                          \
            }                                                                \
        }                                                                    \
        for (int i = 0; i < len; i++) {                                      \
            list->items[list->len + i] = items[i];                           \
        }                                                                    \
        list->len += len;                                                    \
        return list;                                                         \
    }                                                                        \
    __item __list##_remove(__list *list, unsigned int index) {               \
        assert(index < list->len);                                           \
        __item item = list->items[index];                                    \
        for (int i = index; i < list->len - 1; i++) {                        \
            list->items[i] = list->items[i + 1];                             \
        }                                                                    \
        list->len--;                                                         \
        return item;                                                         \
    }
