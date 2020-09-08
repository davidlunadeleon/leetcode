// Made by David Luna

#pragma once

#ifndef _VECTOR_FUNCTIONS
#define _VECTOR_FUNCTIONS

#include "../vector/vector.h"

#include <stdbool.h>

// General information

int vector_get_size(vector *vect);
int vector_get_last_index(vector *vect);
int *vector_get_array(vector *vect);

// Insertion / deletion

void vector_push_back(vector **vect, int num);
int vector_pop_back(vector **vect);
bool vector_empty(vector *vect);

// Content access

int vector_back(vector *vect);
int vector_front(vector *vect);
int vector_at(vector *vect, int position);

#endif