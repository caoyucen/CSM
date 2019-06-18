/*
 
 YUCEN CAO
 12/3/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 16_ a16_2.cpp
 
 */

#include <iostream>
#include <cctype>
#include "Mystring.h"
using namespace std;
using namespace cs_mystring;





bool isAPalindrome(MyString str1, int leftBound, int highBound)
{
	int i = leftBound;
	int j = highBound - 1;
	
	while (i < j) {
		if (ispunct(str1[i]) || isspace(str1[i])) {
			i++;
		}
		else if (ispunct(str1[j]) || isspace(str1[j])) {
			j--;
		}
		else {
			if (toupper(str1[i]) == toupper(str1[j])) {
				i++;
				j--;
			}
			else {
				return false;
			}
		}
	}
	return true;
}






int main()
{

	
	MyString inputStr("");
	while (1) {
		cout << "Enter a string: ";
		inputStr. (cin, '\n'); 
		if (inputStr == "quit") {
			return 0;
		}
		cout << inputStr << " is " << ((isAPalindrome(inputStr, 0, inputStr.length()))?"": "not ") << "a palidrome" << endl;
	}
	return 0;
}






/*
 Enter a string: ab c, cc ba
 ab c, cc ba is a palidrome
 Enter a string: abcd,.     
 abcd,.      is not a palidrome
 Enter a string: quit
 Program ended with exit code: 0
 */
