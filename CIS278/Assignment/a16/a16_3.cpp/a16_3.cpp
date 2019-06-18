/*
 
 YUCEN CAO
 12/3/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 16_ a16_3.cpp
 
 */




#include <iostream>
using namespace std;





//find the smallest index in the rest array
int find_smallest_index(int *array, int length, int left) {
	int smallest = array[left];
	int smallest_index = left;
	for (int i = left; i < length; i++) {
		if (array[i] <= smallest) {
			smallest = array[i];
			smallest_index = i;
		}
	}
	return smallest_index;
}





//swap two element
void swap(int* array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}





//sort int array in ascending order
void recursive_sort(int *array, int length, int left) {
	if (left >= length) {
		return;
	}
	swap(array, left, find_smallest_index(array, length, left));
	recursive_sort(array, length, left + 1);
}

int main()
{

	int a[10] = {6,2,4,6,-1,7, 5,206, -58, 0};
	recursive_sort(a, 10, 0);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ", ";
	}
	cout << endl;
	return 0;
}


/*
 -58, -1, 0, 2, 4, 5, 6, 6, 7, 206, 
 */
