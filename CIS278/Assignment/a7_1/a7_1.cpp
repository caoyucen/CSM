/*
 YUCEN CAO
 10/1/2018
 CIS 278
 Assignment 7_1
 */




#include <iostream>
#include <ctype.h>
using namespace std;



//function prototypes
int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);





//This function finds the last index where the target char can be found in the string. it returns -1 if the target char does not appear in the string.
int lastIndexOf(const char* inString, char target)
{
	int index = -1;
	int i = 0;
	
	while (inString[i])
	{
		if (inString[i] == target)
		{
			index = i;
		}
		i++;
	}
	
	return (index);
}





//This function alters any string that is passed in.
void reverse(char* inString)
{
	int n;
	n = int(strlen(inString)) - 1;
	
	for (int i = 0; i <= (n/2); i++)
	{
		swap(inString[i], inString[n - i]);
	}
}





//This function finds all instances of the char 'target' in the string and replace them with 'replacementChar'.
int replace(char* inString, char target, char replacementChar)
{
	int n = 0;
	int i = 0;
	
	while (inString[i])
	{
		if (inString[i] == target)
		{
			inString[i] = replacementChar;
			n++;
		}
		i++;
	}
	return n;
}





//This function returns true if the argument string is a palindrome.
bool isPalindrome(const char* inString)
{
	int n;
	n = int(strlen(inString)) - 1;
	
	for (int i = 0; i <= n/2; i++)
	{
		if (inString[i] != inString[n - i])
		{
			if (!isalpha(inString[i]))
			{
				return (0);
			}
			else if (inString[i] != toupper(inString[n - i]) && inString[i] != tolower(inString[n - i]))
			{
				return (0);
			}
		}
	}
	
	return (1);
}





//This function converts the c-string parameter to all uppercase.
void toupper(char* inString)
{
	int i = 0;
	
	while (inString[i])
	{
		inString[i] = toupper(inString[i]);
		i++;
	}
}





//This function returns the number of letters in the c-string.
int numLetters(const char* inString)
{
	int i = 0;
	int n = 0;
	
	while (inString[i])
	{
		if(isalpha(inString[i]))
		{
			n++;
		}
		i++;
	}
	
	return (n);
}




int main()
{
	//test 1: int lastIndexOf(const char* inString, char target)
	cout << "test 1:" << endl;
	char str1[] = "Hello World";
	cout << lastIndexOf(str1, 'o') << endl;
	cout << lastIndexOf(str1, 'n') << endl << endl;
	
	
	
	//test 2: void reverse(char* inString)
	cout << "test 2:" << endl;
	char str2[] = "flower is red";
	reverse(str2);
	cout << str2 << endl << endl;
	
	
	
	//test 3: int replace(char* inString, char target, char replacementChar)
	cout << "test 3:" << endl;
	char str3[] = "pan and pan apple";
	char target = 'a';
	char replacementChar = 'e';
	cout << replace(str3, target, replacementChar) << " " << str3 <<endl;
	char str3_1[] = "bcde";
	cout <<replace(str3_1, target, replacementChar) << endl << endl;
	
	
	
	//test 4: bool isPalindrome(const char* inString)
	cout << "test 4:" << endl;
	char str4_0[] = "abca Acba";
	cout << isPalindrome(str4_0) << endl ;
	char str4_1[] = "abcab";
	cout << isPalindrome(str4_1) << endl ;
	char str4_2[] = "abc *cba";
	cout << isPalindrome(str4_2) << endl ;
	char str4_3[] = "abc ba";
	cout << isPalindrome(str4_3) << endl << endl;
	
	
	
	//test 5: void toupper(char* inString)
	cout << "test 5:" << endl;
	char str5[] = "My name is Yucen Cao, 1111";
	toupper(str5);
	cout << str5 << endl << endl;
	
	//test 6: int numLetters(const char* inString)
	cout << "test 6:" << endl;
	char str6[] = "abcdef12345678$%^   &*";
	cout << numLetters(str6) << endl << endl;
	
	return 0;
}

/*
test 1:
7
-1

test 2:
der si rewolf

test 3:
4 pen end pen epple
0

test 4:
1
0
0
0

test 5:
MY NAME IS YUCEN CAO, 1111

test 6:
6
*/

