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

#include <iomanip>
#include "stack.hpp"
#include "queue.hpp"
#include "array2d.hpp"
// main 

class PixelObject {
public:
	int label;
	std::string order;
	
	PixelObject()
	:label(0), order("x") {}
	
	PixelObject(int label, std::string order)
	:label(label), order(order) {}
		
	friend std::ostream& operator<<(std::ostream& ost, const PixelObject& obj) {
		ost << "(" << std::setw(2) << obj.label << "," << std::setw(2) << obj.order << ")";
		return ost;
	}
	
	friend std::istream& operator>>(std::istream& i, PixelObject& obj) {
		i >> obj.label;
		i >> obj.order;
		return i;
	}
};


// Explicit Instantiation
template class Queue<Position2D>;
template class Stack<Position2D>;
template class List<Position2D>;
template class Array2D<PixelObject>;


Array2D<PixelObject> arrayBFS;
Array2D<PixelObject> arrayDFS;
int size;    // number of rows and columns in the image

// initialize offsets
Position2D offset[4] = {Position2D(0, 1), Position2D(1, 0), Position2D(0, -1), Position2D(-1, 0)};

// functions
void welcome()
{
	// Optional code goes here 
	std::cout << "Welcome to the game!" << std::endl << std::endl;
}

void make2dArray(Array2D<PixelObject>& pixel, int n_rows, int n_cols) {
	
	Array2D<PixelObject> tmp(n_rows, n_cols, PixelObject(0, "x"));
	pixel = tmp;
}

void inputImage()
{// Input the image.
	std::cout << "Enter image size" << std::endl;
	std::cin >> size;
	
	
	// create and input the pixel array
	make2dArray(arrayDFS, size, size);
	
	float density = 0.0;
	std::cout 
	<< "Enter image density (please input a float number between 0 - 1 as density factor):"
	<< std::endl;
	
	std::cin >> density;
	if (density <= 1 && density >= 0) {
		std::cout << "Randomizing pixel arrays" << std::endl;
		arrayDFS.randomize(density, PixelObject(1, "x"));
	}
	// Copy arrayDFS to arrayBFS
	arrayBFS = Array2D<PixelObject>(arrayDFS);
}

void labelComponentsDFS() {
	Stack<Position2D> s;
	std::vector<std::vector<bool> > visited(arrayDFS.get_nrows() + 2, std::vector<bool>(arrayDFS.get_ncols() + 2, false));
	int id = 0;  // component id
	int current_order = 0;
	
	for (int r = 1; r <= size; r++) {
		for (int c = 1; c <= size; c++) {
			if (!visited[r][c] && arrayDFS[r][c].label == 1) {
				Position2D current(r, c);
				id++;
				current_order = 0;
				s.push(current);

				while (!s.empty()) {
					Position2D current = s.top();
					s.pop();

					if (!visited[current.row][current.col]) {
						visited[current.row][current.col] = true;
						arrayDFS[current.row][current.col].label = id;
						arrayDFS[current.row][current.col].order = std::to_string(++current_order);
					}
					for (int i = 3; i >= 0; i--) {
						// Visit current node.
						Position2D next = current + offset[i];
						if (arrayDFS.inside(next)
							&& !visited[next.row][next.col] 
							&& arrayDFS[next.row][next.col].label == 1) {
							s.push(next);
						}
					}
				}
			}
		}
	}
}

void labelComponentsBFS()
{// Label the components.
	
	// scan all pixels labeling components
	// Auxilary queue and visited matrix to help with BFS
	Queue<Position2D> q;
	std::vector<std::vector<bool> > visited(arrayBFS.get_nrows() + 2, std::vector<bool>(arrayBFS.get_ncols() + 2, false));
	int id = 0;  // component id
	int current_order = 0;
	
	for (int r = 1; r <= size; r++) {
		for (int c = 1; c <= size; c++) {
			if (!visited[r][c] && arrayBFS[r][c].label == 1) {
				Position2D current(r, c);
				id++;
				current_order = 0;
				q.push_back(current);
				visited[current.row][current.col] = true;
				
				while (!q.empty()) {
					Position2D current = q.front();
					q.pop_front();
					visited[current.row][current.col] = true;
					arrayBFS[current.row][current.col].label = id;
					arrayBFS[current.row][current.col].order = std::to_string(++current_order);
					

					for (int i = 0; i < 4; i++) {
						Position2D child(current + offset[i]);
						if (arrayBFS.inside(child) 
							&& !visited[child.row][child.col]
							&& arrayBFS[child.row][child.col].label == 1) {
							if (!visited[child.row][child.col]) {
								visited[child.row][child.col] = true;
								// push unvisited/inbound child into queue
								q.push_back(child);
							}
						}
					}
				}
			} // end of if, for c, and for r
		}
	}
}

void outputImage()
{// Output labeled image.
	
	std::cout << "Labeled Image After DFS: " << std::endl;
	arrayDFS.printImage();
	
	std::cout << "Labeled Image After BFS:" << std::endl;
	arrayBFS.printImage();
}

int main()
{
	welcome();
	inputImage();
	arrayDFS.printImage();
	labelComponentsDFS();
	labelComponentsBFS();
	outputImage();
	return 0;
}
