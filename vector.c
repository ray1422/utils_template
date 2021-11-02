#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define vector(type) struct vector_##type
#define vector_register(type) \
                              \
    vector(type) {            \
        int cap;              \
        int len;              \
        type* arr;            \
    }
#define vector_init(type) \
    (vector(type)) { .cap = 0, .len = 0, .arr = NULL }
#define vector_destory(v) \
    do {                  \
        free((v).arr);    \
    } while (0)
#define vector_push(v, val)                                                     \
    do {                                                                        \
        if ((v).cap < (v).len + 2) {                                            \
            (v).arr = realloc((v).arr, sizeof(*((v).arr)) * 2 * ((v).cap + 1)); \
            assert((v).arr != NULL);                                            \
            (v).cap = 2 * ((v).cap + 1);                                        \
        }                                                                       \
        (v).arr[(v).len++] = (val);                                             \
    } while (0)
typedef struct node {
    struct node* parents;
    struct node* children;
} node;

struct vector_head {
    int cap;
    int val;
};
#ifndef VECTOR_INT
#define VECTOR_INT
vector_register(int);
#endif
int main() {
    vector(int) v = vector_init(int);
    vector_push(v, 1);
    vector_push(v, 1);
    vector_push(v, 1);
    vector_push(v, 1);
    vector_push(v, 1);
    vector_push(v, 199);
    vector_push(v, 10);
    printf("%d\n", v.arr[v.len - 2]);
    vector_destory(v);
}
