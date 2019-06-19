//
//  array2d.h
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef array2d_h
#define array2d_h

#include <iostream>
#include <iomanip>
#include <vector>

class Position2D {
public:
	int row;
	int col;
	
	Position2D(const int row, const int col);
	
	Position2D operator+(const Position2D& position);
};

template <class T>
class Array2D {
private:
	std::vector<std::vector<T> > array;
	int n_cols;
	int n_rows;
	
	void initArray(const int n_rows, const int n_cols, const T& value);
	void deleteArray();
	
public:
	Array2D(const int n_rows, const int n_cols, const T& value);
	Array2D(const Array2D<T>& array_2d);
	Array2D();
	~Array2D();
	
	void randomize(int density, T value); // move this outside

	T* operator[](const int idx);
	const int get_nrows() const;
	const int get_ncols() const;
	
	// Overrider << for string serialization
	friend std::ostream& operator<<(std::ostream& ost, Array2D& array_2d);
	
};
#endif /* array2d_h */
