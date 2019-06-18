/*
 YUCEN CAO
 9/24/2018
 CIS 278
 Assignment 6_2
 
 This program let the user enter any size of  names and scores.
 And use Dynamic Memory Allocation to create the names and scores arrays
 Sort by scores in descending order, then print names and scores by the order.
 The data must be stored in two arrays: an array of strings named names, and an array of ints named scores. 
 */

#include <iostream>
#include <cstring>
using namespace std;







/*
 This function finds the max number in the array from array[begin] to the end.
 if the array have n numbers, the function will find the biggest number between array[begin] to array[n]
 
 pre:  none
 post: returns the biggest number
 */

int get_max(int *array, int begin, int size)
{
	int n = 0;
	int max = 0;
	
	for (int i = begin; i <size; i++)
	{
		if (array[i] > max)
		{
			n = i;
			max = array[i];
		}
	}
	return (n);
}






/*
 The function initializes the array by letting the user cin names and score.
 User will cin "size" names and scores.
 
 pre:  none
 post: The names array and scores array have been initialized.
 */

void initializeArrays(string names[], int scores[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i + 1 << ": ";
		cin >> names[i];
		cout << "Enter the score for score #" << i + 1 << ": ";
		cin >> scores[i];
	}
	cout << endl;
}






/*
 The function sorts both arrays in descending order by score. 
 Using selection sort, find the max number in the rest of the array, then put it to the front.
 In the same time, swap the names array.
 
 pre:  none
 post: Both arrays sorted in descending order by score.
 */
void sortData(string *names, int *scores, int size)
{
	int number_max = 0;
	
	for(int i = 0; i < size; i++)
	{
		number_max = get_max(scores, i, size);
		swap(scores[i], scores[number_max]);
		swap(names[i], names[number_max]);
	}
}

/*
 The function display the list of names and scores in descending order.
 
 pre:  none
 post: Display the scores and names array in descending order.
 */

void displayData(string *names, int *scores, int size)
{
	cout << "Top Scorers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << names[i] << ": " << scores[i] << endl;
	}
}




/*
 Main function. Declare the arrays, string names array and int scores array. Then invoke three functions above.
 */

int main(int argc, const char * argv[])
{
	int size;
	
	cout << "How many scores will you enter?: " ;
	cin >> size;
	
	string *names = new string[size];
	int *scores = new int[size];
	
	initializeArrays(names, scores, size);
	sortData(names, scores, size);
	displayData(names, scores, size);
	
	delete []names;
	delete []scores;
	
	return 0;
}


/*
 How many scores will you enter?: 5
 Enter the name for score #1: Linda
 Enter the score for score #1: 672
 Enter the name for score #2: Lucy
 Enter the score for score #2: 9940
 Enter the name for score #3: Jack
 Enter the score for score #3: 846
 Enter the name for score #4: Ben
 Enter the score for score #4: 98
 Enter the name for score #5: Chris
 Enter the score for score #5: 976
 
 Top Scorers:
 Lucy: 9940
 Chris: 976
 Jack: 846
 Linda: 672
 Ben: 98
 */

