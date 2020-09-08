// Made by David Luna

#include "./vector.h"

#include <stddef.h>
#include <stdlib.h>

vector *vector_init_empty() { return vector_init_from_array(NULL, 0); }

vector *vector_init_from_array(int *arr, int size) {
	vector *vect;
	int i;

	vect = malloc(sizeof(vector));
	vect->array = malloc((INIT_VECTOR_SIZE > size ? INIT_VECTOR_SIZE : size) *
						 sizeof(int));
	vect->lastIndex = size - 1;
	vect->size = (INIT_VECTOR_SIZE > size ? INIT_VECTOR_SIZE : size);
	for (i = 0; i < size; ++i) {
		vect->array[i] = arr[i];
	}

	return vect;
}

void vector_destructor(vector *vect) {
	free(vect->array);
	free(vect);
}