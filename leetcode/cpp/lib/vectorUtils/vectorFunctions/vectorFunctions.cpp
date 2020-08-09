// Made by David Luna

#include <iostream>
#include <vector>

#include "./vectorFunctions.h"

template <typename T> void makeVectorT(std::vector<T> &vect, int size) {
	vect.clear();
	if (size <= 0) {
		std::cin >> size;
	}
	for (int i = 0; i < size; i++) {
		T temp;
		std::cin >> temp;
		vect.push_back(temp);
	}
}

template <typename T>
void makeMatrixT(std::vector<std::vector<T>> &matrix, int r, int c) {
	matrix.clear();
	if (r <= 0 || c <= 0) {
		std::cin >> r >> c;
	}
	for (int i = 0; i < r; i++) {
		std::vector<T> temp;
		makeVectorT(temp, c);
		matrix.push_back(temp);
	}
}