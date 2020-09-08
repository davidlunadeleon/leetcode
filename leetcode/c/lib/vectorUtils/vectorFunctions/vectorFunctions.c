// Made by David Luna

#include "./vectorFunctions.h"
#include "../vector/vector.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

void resize_up(vector **vect) {
	(*vect)->size *= 2;
	(*vect)->array =
		(int *)realloc((*vect)->array, (*vect)->size * sizeof(int));
}

void resize_down(vector **vect) {
	(*vect)->size /= 2;
	(*vect)->array =
		(int *)realloc((*vect)->array, (*vect)->size * sizeof(int));
}

// General information

int vector_get_size(vector *vect) { return vect->lastIndex + 1; }
int vector_get_last_index(vector *vect) { return vect->lastIndex; }
int *vector_get_array(vector *vect) { return vect->array; }
bool vector_empty(vector *vect) { return vect->lastIndex == -1; }

// Insertion / deletion

void vector_push_back(vector **vect, int num) {
	if ((*vect)->lastIndex == (*vect)->size - 1) {
		resize_up(vect);
	}
	(*vect)->array[++(*vect)->lastIndex] = num;
}

int vector_pop_back(vector **vect) {
	int back;

	back = (*vect)->array[(*vect)->lastIndex--];

	if ((*vect)->lastIndex < (*vect)->size / 2 &&
		(*vect)->size > INIT_VECTOR_SIZE) {
		resize_down(vect);
	}

	return back;
}

// Content access

int vector_back(vector *vect) { return vect->array[vect->lastIndex]; }

int vector_front(vector *vect) { return vect->array[0]; }

int vector_at(vector *vect, int position) { return vect->array[position]; }