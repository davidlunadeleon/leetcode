// Made By David Luna

#pragma once

#ifndef _VECTOR_FUNCTIONS
#define _VECTOR_FUNCTIONS

#include <vector>

template <typename T> void makeVectorT(std::vector<T> &vect, int size = 0);
template <typename T>
void makeMatrixT(std::vector<std::vector<T>> &matrix, int r = 0, int c = 0);

#endif