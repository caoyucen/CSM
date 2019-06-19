/**  Image Component Labeling
 *  Project 1
 *  < YUCEN CAO >
 *  < 02/24/2019 >
 **  The program maintains a 2-D grid (array) of objects, where each object
 keeps track of two values, the image component label (to be assigned by
 DFS or BFS), and the order in which the pixel was discovered, which depends
 on the search strategy (DFS or BFS). Accordingly, each pixel is represented
 by an object that encapsulates a label (component label: 2, 3, 4, ...) and
 (order of discovery: 1, 2, 3, ...).
 *  . . .
 *  . . .
 **/

#ifndef array2d_hpp
#define array2d_hpp

#include<iostream>
#include<vector>
	
class Position2D {
public:
	int row;
	int col;
	
	Position2D(int row = -1, int col = -1);
	
};

template <class T>
class Array2D {
private:
	std::vector<std::vector<T> > array;
	int n_cols;
	int n_rows;
	
	void initArray(const int n_rows, const int n_cols, const T& value = T());
	//	void deleteArray();
	
public:
	Array2D(const int n_rows, const int n_cols, const T& value);
	Array2D(Array2D<T>& array_2d);
	Array2D();
	
	void randomize(float density, const T& value); // move this outside
	bool inside(const Position2D& position);
	
	std::vector<T>& operator[](const int idx);
	const int get_nrows() const;
	const int get_ncols() const;
	
	// Overrider << for string serialization
	// friend ostream& operator<<(ostream& ost, Array2D<T>& array_2d);
	
	void printImage();
	
};

Position2D operator+(const Position2D& a, const Position2D& b);

Position2D::Position2D(int row, int col)
:row(row), col(col) {}

Position2D operator+(const Position2D& a, const Position2D& b) {
	Position2D sum(a.row + b.row, a.col + b.col);
	return sum;
}

template <class T>
Array2D<T>::Array2D(const int n_rows, const int n_cols, const T& value)
:n_rows(n_rows), n_cols(n_cols) {
	initArray(n_rows, n_cols, value);
}

template <class T>
Array2D<T>::Array2D(Array2D<T>& array_2d) {
	n_rows = array_2d.n_rows;
	n_cols = array_2d.n_cols;
	initArray(n_rows, n_cols, T());
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
void Array2D<T>::randomize(float density, const T& value) {
	for (int i = 1; i < n_rows + 1; i++) {
		for (int j = 1; j < n_cols + 1; j++) {
			if (static_cast<float> (static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) < density) {
				array[i][j] = value;
			}
		}
	}
}

template <class T>
bool Array2D<T>::inside(const Position2D& position) {
	return position.row < n_rows + 1 && position.row > 0 && position.col < n_cols + 1 && position.col > 0;
}

template <class T>
void Array2D<T>::initArray(const int n_rows, const int n_cols, const T& value) {
	array = std::vector<std::vector<T> >(n_rows + 2, std::vector<T>(n_cols + 2, value));
}

template <class T>
std::vector<T>& Array2D<T>::operator[](const int idx) {
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
void Array2D<T>::printImage() {
	for (int i = 1; i < n_rows + 1; i++) {
		for (int j = 1; j < n_cols + 1; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif /* array2d_hpp */
