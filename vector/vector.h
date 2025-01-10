#pragma once

#include <stddef.h>
#include <stdlib.h>

#ifndef VECTOR_H
#define VECTOR_H
#endif

#ifndef VECTOR_INICIAL_CAPACITY
#define VECTOR_INICIAL_CAPACITY 8
#endif

typedef struct Vector {
    int* data;
    int size;
    int capacity;
} Vector;

Vector* vector_create();
void vector_destroy(Vector* vector);
bool vector_is_empty(const Vector* vector);
bool vector_is_full(const Vector* vector);
void vector_resize(Vector* vector);
void vector_resize_down(Vector* vector);
bool vector_is_loose(const Vector* vector);
void vector_push_back(Vector* vector, int value);
void vector_pop_back(Vector* vector);
