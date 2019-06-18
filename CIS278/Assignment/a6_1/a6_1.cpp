/*
 YUCEN CAO
 9/24/2018
 CIS 278
 Assignment 6_1
 */

#include <iostream>
using namespace std;

void noNegatives(int *a)     //11
{
	if (*a < 0)
	{
		*a = 0;
	}
}

void swap(int* a, int* b)    //21
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main() 
{
	int x;
	int y;        //1
	int* p1;      //2
	
	p1 = &x;      //3
	*p1 = 99;     //4
	cout << "The value of x: " << x << endl;     //5
	cout << "The value of x: " << *p1 << endl;   //6
	
	p1 = &y;      //7
	*p1 = -300;   //8
	int temp;
	int* p2;
	p2 = &x;      //9
	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;   //10
	
	noNegatives(&x);
	noNegatives(&y);      //12
	
	cout << "x is: " << *p2 << endl;
	p2 = &y;  // Use p2 to display the values in x and y, this is the way to use p2 display y
	cout << "y is: " << *p2 << endl;     //13
	
	int a[2];
	p2 = &a[0];    //14
	*p2 = x;       //15
	p2[1] = y;     //16
	cout << "The address of the first element: " << p2  <<  endl;    //17
	cout << "The address of the second element: " <<&p2[1] << endl;  //18
	
	p1 = &a[0];
	p2 = &a[1];
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;            //19
	cout << "The first element: " << a[0] << " ,the second element: " << a[1] << endl;    //20
	
	swap(&x, &y);
	cout << "The first element: " << x << " ,the second element: " << y << endl;          //22
	
	swap(&a[0], &a[1]);
	cout << "The first element: " << a[0] << " ,the second element: " << a[1] << endl;    //23
	
	return 0;
}
