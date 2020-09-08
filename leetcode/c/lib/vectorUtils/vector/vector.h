// Made by David Luna

#pragma once

#ifndef _VECTOR
#define _VECTOR

#define INIT_VECTOR_SIZE 10 // minimum size of vector

// Struct definition

typedef struct {
	int *array;
	long size;
	long lastIndex;
} vector;

// Creation / destruction management

vector *vector_init_empty();
vector *vector_init_from_array(int *array, int size);
void vector_destructor(vector *vect);

#endif