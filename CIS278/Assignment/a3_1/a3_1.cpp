/*
 YUCEN CAO
 9/3/2018
 CIS 278
 Assignment 3
 
 This program that plays a number guessing game with a Human user. 
 The Human user will think of a number between 1 and 100, inclusive. 
 The program will make guesses and the user will tell the program to guess higher or lower.
 The Human user will respond by "h/l/c" (higher/lower/correct)
 The program need to guess the correct number
 */

#include <iostream>
using namespace std;

int getMidpoint(int low, int high)
{
	int mid = 0;
	
	mid = (high - low)/2 + low;
	
	return (mid);
}

void getUserResponseToGuess(int guess, char& result)
{
	char c = 0;
	
	cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
	cin >> c;
	result = c;
}

void playOneGame()
{
	int a = 1;
	int b = 100;
	int guess = 0; 
	char result = 0; 
	int mark = 1;
	
	cout << "Think of a number between 1 and 100." << endl;
	while (mark)
	{
		guess = getMidpoint(a,b);
		getUserResponseToGuess(guess, result);
		if (result == 'l')
		{
			b = guess - 1;
		}
		if (result == 'h')
		{
			a = guess + 1;
		}
		if (result == 'c')
		{
			mark = 0;
		}
	}
}


int main() {
	char response;
	
	cout << "Ready to play (y/n)? ";
	cin >> response;
	while (response == 'y') {
		playOneGame();
		cout << "Great! Do you want to play again (y/n)? ";
		cin >> response;
	}
	
}





//Ready to play (y/n)? y
//Think of a number between 1 and 100.
//My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 88. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
//Great! Do you want to play again (y/n)? y
//Think of a number between 1 and 100.
//My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 12. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 18. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 21. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 23. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
//Great! Do you want to play again (y/n)? y
//Think of a number between 1 and 100.
//My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l
//My guess is 62. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 68. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 71. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 73. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h
//My guess is 74. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c
//Great! Do you want to play again (y/n)? n

