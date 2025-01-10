#include <stdio.h>

#include "vector.h"

#define ASSERT(condition) \
    if (!(condition)) { \
        printf("Assertion failed: %s\n", #condition); \
        exit(1); \
    }

void test_vector_init() {
    const Vector* vector = vector_create();
    ASSERT(vector != nullptr);
    ASSERT(vector->data != nullptr);
    ASSERT(vector->size == 0);
    ASSERT(vector->capacity == VECTOR_INICIAL_CAPACITY);
    printf("Vector init test passed!\n");
}

void test_vector_destroy() {
    Vector* vector = vector_create();
    vector_destroy(vector);
    ASSERT(vector->data == nullptr);
    ASSERT(vector->size == 0);
    ASSERT(vector->capacity == VECTOR_INICIAL_CAPACITY);
    printf("Vector destroy test passed!\n");
}

void test_vector_is_empty() {
    Vector* vector = vector_create();
    ASSERT(vector_is_empty(vector));
    vector_push_back(vector, 1);
    ASSERT(!vector_is_empty(vector));
    vector_destroy(vector);
    printf("Vector is empty test passed!\n");
}

void test_vector_is_full() {
    Vector* vector = vector_create();
    for (int i = 0; i < VECTOR_INICIAL_CAPACITY; i++) {
        vector_push_back(vector, i);
    }
    ASSERT(vector_is_full(vector));
    vector_destroy(vector);
    printf("Vector is full test passed!\n");
}

void test_vector_resize() {
    Vector* vector = vector_create();
    for (int i = 0; i < VECTOR_INICIAL_CAPACITY + 1; i++) {
        vector_push_back(vector, i);
    }
    ASSERT(vector->capacity == VECTOR_INICIAL_CAPACITY * 2);
    vector_destroy(vector);
    printf("Vector resize test passed!\n");
}

void test_vector_resize_down() {
    Vector* vector = vector_create();
    for (int i = 0; i < VECTOR_INICIAL_CAPACITY + 1; i++) {
        vector_push_back(vector, i);
    }
    for (int i = 0; i < 5; i++) {
        vector_pop_back(vector);
    }
    ASSERT(vector->capacity == VECTOR_INICIAL_CAPACITY);
    vector_destroy(vector);
    printf("Vector resize down test passed!\n");
}

void test_vector_is_loose() {
    Vector* vector = vector_create();
    for (int i = 0; i < VECTOR_INICIAL_CAPACITY + 1; i++) {
        vector_push_back(vector, i);
    }
    for (int i = 0; i < 4; i++) {
        vector_pop_back(vector);
    }
    vector->data[vector->size] = (int)NULL;
    vector->size--;
    ASSERT(vector_is_loose(vector));
    vector_destroy(vector);
    printf("Vector is loose test passed!\n");
}

void test_vector_push_back() {
    Vector* vector = vector_create();
    vector_push_back(vector, 1);
    ASSERT(vector->data[0] == 1);
    vector_push_back(vector, 2);
    ASSERT(vector->data[1] == 2);
    vector_destroy(vector);
    printf("Vector push back test passed!\n");
}

void test_vector_pop_back() {
    Vector* vector = vector_create();
    vector_push_back(vector, 1);
    vector_push_back(vector, 2);
    vector_pop_back(vector);
    ASSERT(vector->size == 1);
    vector_pop_back(vector);
    ASSERT(vector->size == 0);
    vector_destroy(vector);
    printf("Vector pop back test passed!\n");
}

int main () {
    printf("Running tests for vector...\n");
    test_vector_init();
    test_vector_destroy();
    test_vector_is_empty();
    test_vector_is_full();
    test_vector_resize();
    test_vector_resize_down();
    test_vector_is_loose();
    test_vector_push_back();
    test_vector_pop_back();
    printf("All tests passed!\n");
    return 0;
}
