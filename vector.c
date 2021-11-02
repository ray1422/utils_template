#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
/**************** BEGIN VECTOR ****************/
#ifndef VECTOR
#define VECTOR
#define vector(identifier) struct vector_##typename
#define vector_register(type, identifier) \
    vector(identifier) {                  \
        int cap;                          \
        int len;                          \
        type* arr;                        \
    }
#define vector_init(type, identifier) \
    (vector(identifier)) { .cap = 0, .len = 0, .arr = NULL }
#define vector_destory(v, callback)                             \
    do {                                                        \
        for (int i = 0; i < v.len; i++) (callback)((v).arr[i]); \
        free((v).arr);                                          \
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

#endif
/***************** END VECTOR *****************/

#ifndef VECTOR_INT
#define VECTOR_INT
vector_register(int*, INT_PTR);
#endif
int main() {
    vector(int*) v = vector_init(int, INT_PTR);
    vector_push(v, malloc(4));
    vector_push(v, malloc(4));
    vector_push(v, malloc(4));
    vector_push(v, malloc(4));
    *v.arr[v.len - 2] = 19;
    printf("%d\n", *v.arr[v.len - 2]);
    vector_destory(v, free);
}
