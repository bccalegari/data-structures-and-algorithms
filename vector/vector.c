#include "vector.h"

Vector* vector_create() {
    const auto vector = (Vector*) malloc(sizeof(Vector));
    vector->data = (int*) malloc(VECTOR_INICIAL_CAPACITY * sizeof(int));
    for (int i = 0; i < VECTOR_INICIAL_CAPACITY; i++) {
        vector->data[i] = (int)NULL;
    }
    vector->size = 0;
    vector->capacity = VECTOR_INICIAL_CAPACITY;
    return vector;
}

void vector_destroy(Vector* vector) {
    free(vector->data);
    vector->data = nullptr;
    vector->size = 0;
    vector->capacity = VECTOR_INICIAL_CAPACITY;
}

bool vector_is_empty(const Vector* vector) {
    return vector->size == 0 && (int*)vector->data[0] == NULL;
}

bool vector_is_full(const Vector* vector) {
    return vector->size == vector->capacity;
}

void vector_resize(Vector* vector) {
    vector->capacity *= 2;
    vector->data = (int*) realloc(vector->data, vector->capacity * sizeof(int));
}

void vector_resize_down(Vector* vector) {
    vector->capacity /= 2;
    vector->data = (int*) realloc(vector->data, vector->capacity * sizeof(int));
}

bool vector_is_loose(const Vector* vector) {
    return vector->size <= vector->capacity / 4;
}

void vector_push_back(Vector* vector, const int value) {
    if (vector_is_full(vector)) {
        vector_resize(vector);
    }
    vector->data[vector->size++] = value;
}

void vector_pop_back(Vector* vector) {
    if (vector_is_empty(vector)) {
        return;
    }
    vector->data[vector->size] = (int)NULL;
    vector->size--;
    if (vector_is_loose(vector)) {
        vector_resize_down(vector);
    }
}
