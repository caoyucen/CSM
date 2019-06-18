/*
 
 YUCEN CAO
 12/3/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 16_ a16_1.cpp
 
 */

#include <iostream>
#include <cstring>
using namespace std;




//The function should reverse the order of those entries in the array whose indices are between the two bounds 
void reverseWithinBounds(char *array, int bound1, int bound2)
{
	int i = 0;
	char temp;
	
	while (i <= ((bound2 - bound1) /2))
	{
		temp = array[bound1 + i];
		array[bound1 + i] = array[bound2 - i];
		array[bound2 - i] = temp;
		i++;
	}   
}






//reverseCstring that takes a single argument that is a C string and modifies the argument so that it is reversed.
void reverseCstring(char *array)
{
	int i = int(strlen(array));
	reverseWithinBounds(array, 0, (i-1));
}







int main()
{
	char array1[8] = "abcdefg";
	cout << "The array is:  " << array1 << endl;
	reverseWithinBounds(array1, 1, 6);
	cout << "After reverseWithinBounds:  " << array1 << endl << endl;;
	
	char array2[8] = "abcdefg";
	cout << "The array is:  " << array2 << endl;
	reverseCstring(array2);
	cout << "After reverseCstring:  " << array2 << endl;
	
}



/*
 The array is:  abcdefg
 After reverseWithinBounds:  agfedcb
 
 The array is:  abcdefg
 After reverseCstring:  gfedcba
 */
