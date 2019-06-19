//
//  array2d.cpp
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#include "array2d.h"


Position2D Position2D::operator+(const Position2D& obj) {
	Position2D sum(row + obj.row, col + obj.col);
	return sum;
}

template <class T>
Array2D<T>::Array2D(const int n_rows, const int n_cols, const T& value)
:n_rows(n_rows), n_cols(n_cols) {
	initArray(n_rows, n_cols, value);
}

template <class T>
Array2D<T>::Array2D(const Array2D<T>& array_2d) {
	n_rows = array_2d.n_rows;
	n_cols = array_2d.n_cols;
	initArray(n_rows, n_cols);
	for (int i = 0; i < n_rows + 2; i++) {
		for (int j = 0; j < n_cols + 2; j++) {
			array[i][j] = array_2d[i][j];
		}
	}
}

template <class T>
Array2D<T>::Array2D()
:n_rows(0), n_cols(0) {}

template <class T>
Array2D<T>::~Array2D() {
	for (int i = 0; i < n_rows + 2; i++) {
		delete array[i];
	}
	delete array;
}

template <class T>
void Array2D<T>::randomize(int density, T value) {
	for (int i = 1; i < n_rows + 1; i++) {
		for (int j = 1; j < n_cols + 1; j++) {
			if (static_cast<float> (static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) < density) {
				array[i][j] = value;
			}
		}
	}
}

template <class T>
void Array2D<T>::initArray(const int n_rows, const int n_cols, const T& value) {
	array = std::vector<std::vector<T> >(n_rows, std::vector<T>(n_cols, value));
	for (int i = 0; i < n_cols + 2; i++) {
		array[i] = new std::vector<T>();
	}
}

template <class T>
T* Array2D<T>::operator[](const int idx) {
	return array[idx];
}

template <class T>
const int Array2D<T>::get_nrows() const {
	return n_rows;
}

template <class T>
const int Array2D<T>::get_ncols() const {
	return n_cols;
}

template <class T>
std::ostream& operator<<(std::ostream& ost, Array2D<T>& array_2d) {
	for (int i = 1; i < array_2d.n_rows + 1; i++) {
		for (int j = 1; j < array_2d.n_cols + 1; j++) {
			ost << array_2d.array[i][j] << " ";
		}
		ost << std::endl;
	}
	return ost;
}
