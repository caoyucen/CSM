/*
 
 YUCEN CAO
 8/27/2018
 CIS 278
 Assignment 2
 
 This program is a game like "blackjack" which is a card game. 
 The goal is to get as close as possible to a total 21 without going over.
 
 The program shold generate a random number between 1 and 10 each time the player gets a card. 
 Ask the user if he/she want to add another card.
 If the total number is 21 exactly, the program should print "Congratulations!"
 Or the number exceeds 21, the program should print "Bust" 
 
 Then ask if the player wants to play again. 
*/


#include <iostream>
using namespace std;

int main()
{	
	char card = '\0'; //another card or not
	char again = '\0'; // play again or not
	
	int fc1 = 0; //First card 1
	int fc2 = 0; //First card 2
	int n = 0; //total number
	int ac = 0; // number of another card
	int mark1 = 0; //mark first card
	int mark2 = 0; //mark play again;
	
	while (1)
	{ 
		if (n < 21 && mark1 == 1)
		{
			cout << "Total: " << n << endl ;
			cout<< "Do you want another card? (y/n): ";
			cin >> card;
			if (card == 'y')
			{	
				ac  = rand()%10 + 1;
				cout << "Card: " << ac << endl;
				n = n + ac;
			}
			if (card == 'n')
			{
				mark2 = 1;
			}
		}
		if (n >= 21)
		{
			cout << "Total: " << n << endl ;
			if (n > 21)
			{
				cout << "Bust." << endl;
			}
			if (n == 21)
			{
				cout << "Congratulations!" << endl;
			}
			mark2 = 1;
		}
		if (mark2 == 1)
		{
			cout << "Would you like to play again? (y/n): ";
			cin >> again;
			if (again == 'n')
			{
				return (0);
			}
			if (again == 'y')
			{
				fc1 = 0; 
				fc2 = 0;
				mark1 = 0;
				mark2 = 0;
				n = 0;
			}
		}
		if ( mark1 == 0)
		{
			fc1 = rand()%10 + 1;
			fc2 = rand()%10 + 1;
			cout << "First cards: " << fc1 << ", " << fc2 << endl;
			n = fc1 + fc2;
			mark1 = 1;
		}
		
	}
	
	
	return 0;
}


//First cards: 8, 10
//Total: 18
//Do you want another card? (y/n): y
//Card: 4
//Total: 22
//Bust.
//Would you like to play again? (y/n): y
//First cards: 9, 1
//Total: 10
//Do you want another card? (y/n): y
//Card: 3
//Total: 13
//Do you want another card? (y/n): y
//Card: 5
//Total: 18
//Do you want another card? (y/n): y
//Card: 9
//Total: 27
//Bust.
//Would you like to play again? (y/n): y
//First cards: 4, 10
//Total: 14
//Do you want another card? (y/n): y
//Card: 1
//Total: 15
//Do you want another card? (y/n): n
//Would you like to play again? (y/n): y
//First cards: 6, 3
//Total: 9
//Do you want another card? (y/n): y
//Card: 3
//Total: 12
//Do you want another card? (y/n): y
//Card: 8
//Total: 20
//Do you want another card? (y/n): y
//Card: 4
//Total: 24
//Bust.
//Would you like to play again? (y/n): n
//
