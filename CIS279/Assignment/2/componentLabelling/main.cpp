//
//  main.cpp
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//


/*
 * Image Component Labeling
 * Project 1
 * Yucen Cao
 * 2019/02/24
 *
 * Purpose and usage of this application
 *   . . .
 *   . . .
 *
 */


// . . .
// . . .
// . . .


// global variables

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "queue.h"
#include "stack.h"
#include "array2d.h"
using namespace std;


class PixelObject {
public:
	int label;
	char order;
	
	PixelObject(int label, char order)
	:label(label), order(order) {}
	
	friend ostream& operator<<(ostream& ost, const PixelObject& obj) {
		ost << "(" << setw(2) << obj.label << "," << setw(2) << obj.order << ")";
		return ost;
	}
	
	friend istream& operator>>(istream& i, PixelObject& obj) {
		i >> obj.label;
		i >> obj.order;
		return i;
	}
};

Array2D<PixelObject> arrayBFS;
Array2D<PixelObject> arrayDFS;
int size;      // number of rows and columns in the image

// initialize offsets
vector<Position2D> offset;

offset.push_back(Position2D(0, 1));
offset.push_back(Position2D(1, 0)); 
offset.push_back(Position2D(0, -1)); 
offset.push_back(Position2D(-1, 0));

// functions
void welcome()
{
	// Optional code goes here 
}

void make2dArray(Array2D<PixelObject> pixel, int n_rows, int n_cols) {
	arrayDFS = Array2D<PixelObject>(n_rows, n_cols, PixelObject(0, 0));
}

void inputImage()
{// Input the image.
	cout << "Enter image size" << endl;
	cin >> size;
	
	// create and input the pixel array
	make2dArray(arrayDFS, size + 2, size + 2);
	
	float density = 0.0;
	cout << "Do you want to input image label manually, or let the system randomly create one?" << endl << "Press -1 to manually enter, otherwise please input a float number between 0 - 1 as density factor:" << endl;
	
	cin >> density;
	if (density < -0.5) {
		cout << "Please input the array from top left to bottom right (only labels, 1 or 0):" << endl;
		for (int i = 1; i < arrayDFS.get_nrows(); i++) {
			for (int j = 1; j < arrayDFS.get_ncols(); j++) {
				// TODO: verify if this works
				int label;
				cin >> label;
				arrayDFS[i][j].label = label;
			}
		}
	}
	else {
		cout << "Randomizing pixel arrays" << endl;
		arrayDFS.randomize(density, PixelObject(1, 'x'));
	}
	// Copy arrayDFS to arrayBFS
	arrayBFS = Array2D<PixelObject>(arrayDFS);
}

void labelComponentsDFS() {
	
}

void labelComponentsBFS()
{// Label the components.
		
	// scan all pixels labeling components
	Queue<Position2D> q;
	
	int id = 0;  // component id
	int currentOrder = 0;
	for (int r = 1; r <= size; r++) {
		for (int c = 1; c <= size; c++) {
			if (arrayBFS[r][c].order == 'x' && arrayBFS[r][c].label == 1) {
				Position2D current(r, c);
				q.push_back(current);
				id++;
				currentOrder = 0;
				while (!q.empty()) {
					Position2D current = q.front();
					arrayBFS[current.row][current.col].label = id;
					arrayBFS[current.row][current.col].order = '0' + (++currentOrder);
					for (int i = 0; i < offset.size(); i++) {
						Position2D child(current + offset[i]);
						q.push_back(child);
					}
					q.pop_front();
				}
			} // end of if, for c, and for r
		}
	}
}

void outputImage()
{// Output labeled image.
	
	cout << "Labeled Image After BFS: " << endl;
	cout << arrayBFS << endl;
	
	cout << "Labeled Image After DFS:" << endl;
	cout << arrayDFS << endl;
}

int main()
{
	welcome();
	inputImage();
	labelComponentsBFS();
	outputImage();
	return 0;
}
