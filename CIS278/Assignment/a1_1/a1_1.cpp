//
//  a1_1
//
//  Created by YUCEN CAO o on 2018/8/27.
//  Student ID is G01076381

#include <iostream>
#include <cstring>

using namespace std;

int main()
{	
	int n = 0;
	int num_month = 0;
	int num_day = 0;
	int num_year = 0;
	int tem = 0;
	int mark = 0;
	
	string str;
	cout << "enter a date: ";
	cin >> str;
	while(str[n])
	{
		if (str[n] == '/')
		{
			if (mark == 1)
			{
				num_day = tem;
				tem = 0;
				mark++;
			}
			if (mark == 0)
			{
				num_month = tem;
				tem = 0;
				mark++;
			}
			n++;
		}
		else
		{
			tem = 10 * tem + (str[n] - '0');
			n++;
		}
	}
	if (mark == 2)
	{
		num_year = tem;
		if (num_day * num_month == num_year)
		{
			cout << "the date is magic" << endl;
		}
		if (num_day * num_month != num_year)
		{
			cout << "the date is not magic" << endl;
		}
	}
	
    return 0;
}


// enter a date: 6/10/60
// the date is magic

//enter a date: 06/11/60
//the date is not magic

//enter a date: 6/04/25
//the date is not magic


