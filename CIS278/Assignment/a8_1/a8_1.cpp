/*
 
 YUCEN CAO
 10/8/2018
 CIS 278
 Assignment 8_1
 
 This program let the user enter any size of  names and scores.
 Using struct to store the scores and names
 Sort by scores in descending order, then print names and scores by the order.
 */





#include <iostream>
#include <cstring>
using namespace std;





//Structure declaration
struct highscore
{
	char name[24];
	int score;
};





//Function prototypes
void initializeData(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);
int get_max(highscore scores[], int begin, int size); //To find the highest score



/*
 This function finds the max score in higscore from scores[begin] to the end.
 */

int get_max(highscore scores[], int begin, int size)
{
	int n = 0;
	int max = 0;
	
	for (int i = begin; i <size; i++)
	{
		if (scores[i].score > max)
		{
			n = i;
			max = scores[i].score;
		}
	}
	return (n);
}






/*
 The function initializes the highscore by letting the user cin names and score.
 */

void initializeData(highscore scores[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i + 1 << ": ";
		cin >> scores[i].name;
		cout << "Enter the score for score #" << i + 1 << ": ";
		cin >> scores[i].score;
	}
	cout << endl;
}





/*
 The function sorts  highscore.score in descending order. 
 Using selection sort, find the max number in the rest, then put it to the front.
 In the same time, swap the highscore.
 */
void sortData(highscore scores[], int size)
{
	int number_max = 0;
	
	for(int i = 0; i < size; i++)
	{
		number_max = get_max(scores, i, size);
		swap(scores[i], scores[number_max]);
	}
}





/*
 The function display the highscore.name and highscore.score in descending order.
 */

void displayData(const highscore scores[], int size)
{
	cout << "Top Scorers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << scores[i].name << ": " << scores[i].score << endl;
	}
}







int main(int argc, const char * argv[])
{
	int size;
	
	cout << "How many scores will you enter?: " ;
	cin >> size;
	
	highscore *scores = new highscore[size];
	
	
	initializeData(scores, size);
	sortData(scores, size);
	displayData(scores, size);

	
	delete []scores;
	
	return 0;
}



/*
How many scores will you enter?: 8
Enter the name for score #1: aaa
Enter the score for score #1: 1234
Enter the name for score #2: bbb
Enter the score for score #2: 2345
Enter the name for score #3: ccc
Enter the score for score #3: 4567
Enter the name for score #4: ddd
Enter the score for score #4: 55555
Enter the name for score #5: e
Enter the score for score #5: 888888
Enter the name for score #6: f
Enter the score for score #6: 999999
Enter the name for score #7: g
Enter the score for score #7: 1000000
Enter the name for score #8: h
Enter the score for score #8: 45454545

Top Scorers:
h: 45454545
g: 1000000
f: 999999
e: 888888
ddd: 55555
ccc: 4567
bbb: 2345
aaa: 1234
*/


/*
 How many scores will you enter?: 3
 Enter the name for score #1: aaaaabbbbbcccccdddddeeeeefffff
 Enter the score for score #1: 12
 Enter the name for score #2: as
 Enter the score for score #2: 23
 Enter the name for score #3: ff
 Enter the score for score #3: 45
 
 Top Scorers:
 ff: 45
 as: 23
 aaaaabbbbbcccccdddddeeee: 12

 */
