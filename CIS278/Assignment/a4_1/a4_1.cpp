/*
 YUCEN CAO
 9/9/2018
 CIS 278
 Assignment 4
 
 This program is a card game, let user enter 5 cards, cards are from 2 to 9.
 
 Four of a kind: 4 same cards
 full house: 3 same cards and a pair
 Straight: 5 consecutive cards
 Three of a kind: 3 same cards, no pair
 Two Pair: Two different pairs
 pair : only one pair
 High Card: There are no matching cards, and the hand is not a straight
 
 The program should print out the appropriate hand type
 */


#include <iostream>
using namespace std;

const int card_number = 5; // if the card number change to 4 or 6, it still works, just change it here

int cardrepeattime(int hand[], int n)
{
	int time = 0;
	
	for (int i = 0; i < card_number; i++)
	{
		if (hand[i] == hand[n])
		{
			time++;
		}
	}
	
	return time;
}

int get_max(int array[]) // find the biggest number in a array
{
	int max = 0;
	
	for (int i = 0; i < card_number; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	
	return (max);
}

int number_of_element(int array[], int element)
{
	int n = 0;
	int i = 0;
	
	while (array[i])
	{
		if (array[i] == element)
		{
			n++;
		}
		i++;
	}
	
	return (n);
}

void repeattimearray(int hand[], int repeattime[])
{
	for (int i = 0; i < card_number; i++)
	{
		repeattime[i] = cardrepeattime(hand, i);
	}
}

int have_it_ornot(int array[], int target_number)
{
	for (int i = 0; i < card_number; i++)
	{
		if (array[i] == target_number)
		{
			return (1);
		}
	}
	return (0);
}

bool containsStraight(int hand[])
{
	int card;
	
	card = get_max(hand);
	for (int i = 0; i < card_number; i++)
	{
		if (have_it_ornot(hand, card) == 0)
		{
			return (0);
		}
		card--;
	}
	
	return (1);	
}

bool containsFourOfaKind(int hand[])
{
	int repeattime[card_number];
	int maxtime;
	
	repeattimearray(hand, repeattime);
	maxtime = get_max(repeattime);
	if (maxtime == 4) // when maxtime == 4  means there are 4 cards are same
	{
		return (1);
	}
	return (0);
}

bool containsFullHouse(int hand[])
{
	int repeattime[card_number];
	int maxtime;
	
	repeattimearray(hand, repeattime);
	maxtime = get_max(repeattime);
	if (maxtime == 3)
	{
		for (int i = 0; i < card_number; i++)
		{
			if (repeattime[i] == 2) // if repeattime[i] == 2, means there is a pair.
				return (1);
		}
	}
	return (0);
}

bool containsThreeOfaKind(int hand[])
{
	int repeattime[card_number];
	int count; //count how many three of a kind cards
	
	repeattimearray(hand, repeattime);
	count = number_of_element(repeattime, 3);
	if (count >= 3)
	{
		return (1);
	}
	return (0);
}

bool containsTwoPair(int hand[])
{
	int repeattime[card_number];
	int count;
	
	repeattimearray(hand, repeattime);
	count = number_of_element(repeattime, 2);
	
	if (count >= 4)
	{
		return (1);
	}
	
	return (0);
}

bool containsPair(int hand[])
{
	int repeattime[card_number];
	int count;
	
	repeattimearray(hand, repeattime);
	count = number_of_element(repeattime, 2);
	if (count >= 2)
	{
		return (1);
	}
	
	return (0);
}


void get_handtype(int hand[]) //get the appropriate hand type,a part of main function
{
	if ( containsStraight (hand))
	{
		cout << "Straight!" << endl;
	}
	
	else if ( containsFourOfaKind(hand))
	{
		cout << "Four of a kind!" << endl;
	}
	else if ( containsPair(hand))
	{
		if (containsFullHouse(hand))
		{
			cout << "Full House!" << endl;
		}
		else if (containsTwoPair(hand))
		{
			cout << "Two Pair!" << endl;
		}
		else
		{
			cout << "Pair!" << endl;
		}
	}
	else if ( containsThreeOfaKind(hand))
	{
		if (!containsFullHouse(hand))
		{
			cout << "Three of a kind!" << endl;
		}
		else if (containsFullHouse(hand))
		{
			cout << "Full House!" << endl;
		}
	}
	else 
	{
		cout << "High Card!" << endl;
	}
}

int main()
{
	int hand[card_number];
	
	cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
	for (int i = 0; i < card_number; i++)
	{
		cout << "Card " << i + 1 << ": ";
		cin >> hand[i];
	}
	get_handtype(hand);
	
	return (0);
}




/*
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 7
 Two Pair!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 4
 Card 4: 6
 Card 5: 5
 Straight!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 9
 Card 2: 2
 Card 3: 3
 Card 4: 4
 Card 5: 5
 High Card!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 3
 Card 2: 3
 Card 3: 3
 Card 4: 3
 Card 5: 4
 Four of a kind!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 4
 Card 2: 7
 Card 3: 7
 Card 4: 4
 Card 5: 4
 Full House!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 6
 Card 2: 4
 Card 3: 8
 Card 4: 6
 Card 5: 6
 Three of a kind!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 2
 Card 2: 4
 Card 3: 5
 Card 4: 7
 Card 5: 2
 Pair!
 
 */

