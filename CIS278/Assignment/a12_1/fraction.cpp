/*
 
 YUCEN CAO
 11/5/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 12_ fraction.cpp
 
 */



#include <iostream>
#include "fraction.h"
#include <cassert>
using namespace std;


/*
 Class Invariant: A fraction has two int data member : numerator and denominator.
 A fraction can also be an integer and a fraction, like 3 and 1/3
 Internaloperations always result in valid dates,that means that the denominator can not be 0. 
 */

namespace cs_fraction {
	
	
	Fraction::Fraction(int inNumerator, int inDenominator)
	{
		assert(inDenominator != 0);
		numerator = inNumerator;
		denominator = inDenominator;
		simplify();
	}
	
	
	
	// The public member function printing to a stream with an overloaded << operator.  If it is an integer, just print it. If the denominator for the fraction is 0, print 0. If the fraction is bigger than 1, print mixed numbe (inter + fraction). 
	ostream& operator<<(ostream& out, const Fraction& right)
	{
		int i;  // integer
		int rest_numerator;
		int negative = 1;
		int temp_numerator;
		
		if (right.numerator == 0)
		{
			cout << 0;
			return out;
		}
		else if (right.numerator % right.denominator == 0)
		{
			cout << (right.numerator / right.denominator);
			return out;
		}
		else
		{	
			temp_numerator = right.numerator;
			if (right.numerator < 0)
			{
				negative = -1;
				temp_numerator = right.numerator * (-1); 
			}			
			i = temp_numerator / right.denominator;
			if (i >= 1)
			{
				rest_numerator = temp_numerator - (i * right.denominator);
				cout <<(i * negative) << "+" << rest_numerator << "/" << right.denominator;
			}
			else
			{
				cout << right.numerator << "/" << right.denominator ;   
			}
			return out;
		}
	}
	
	//The public member function  with an overloaded >> operator.  The input can be integer, fraction and mixed numbe (integer + fraction)
	istream& operator>>(istream& in, Fraction& right)
	{
		int temp;
		int temp_numerator;
		in >> temp;
		if (in.peek() == '+')
		{
			in.ignore() >> temp_numerator;
			in.ignore() >> right.denominator;
			if (temp > 0)
			{
				right.numerator = temp * right.denominator + temp_numerator;
			}
			else
			{
				right.numerator = temp * right.denominator - temp_numerator;
			}
		}
		else if (in.peek() == '/')
		{
			in.ignore() >> right.denominator;
			right.numerator = temp;
		} 
		else 
		{
			right.numerator = temp;
			right.denominator = 1;
		}
		right.simplify();
		
		return in;
		}
	
	
	
	
	
	// This private member function simplify the fraction by find the biggest number that denominator and  numerator both can be divisibled by the number. The denominator is never negative. If the denominator is negative, fix this by multiplying numerator and denominator by -1. Also, if the numerator is 0, the denominator should be set to 1.
	void Fraction::simplify()
	{
		int num;
		int negative = 1;
		
		if(numerator * denominator < 0)
		{
			negative = -1;
			if (numerator < 0)
				numerator = numerator * (-1);
			else
				denominator = denominator * (-1);
		}
		
		if (denominator == 0)
			numerator = 1;
		else
		{
			if (numerator >= denominator)
				num = denominator;
			else
				num = numerator;
			for ( int i = num; i > 0 ; i--)
			{
				if (((numerator % i ) + (denominator % i)) == 0)
				{
					numerator = numerator / i;
					denominator = denominator / i;
					break;
				}
			}
			numerator = numerator * negative;
		}
	}
	
	
	
	Fraction operator+(const Fraction& left, const Fraction& right) 
	{
		Fraction answer;
		
		answer.numerator = left.numerator * right.denominator + left.denominator * right.numerator  ;
		answer.denominator= left.denominator * right.denominator;
		answer.simplify();
		
		return (answer);
		
	}
	
	
	
	
	
	
	Fraction Fraction::operator+=(const Fraction& right) 
	{
		
		Fraction left(numerator, denominator);
		
		numerator = left.numerator * right.denominator + left.denominator * right.numerator  ;
		denominator= left.denominator * right.denominator;
		simplify();
		
		return *this;
	}
	
	
	
	
	
	
	Fraction  operator-(const Fraction& left, const Fraction& right) 
	{
		Fraction answer;
		
		answer.denominator = left.denominator * right.denominator;
		answer.numerator=  right.denominator * left.numerator - left.denominator * right.numerator;
		answer.simplify();
		
		return (answer);
	}
	
	
	
	
	
	
	Fraction Fraction::operator-=(const Fraction& right) 
	{
		Fraction left(numerator, denominator);
		
		denominator = left.denominator * right.denominator;
		numerator=  right.denominator * left.numerator - left.denominator * right.numerator;
		simplify();
		
		return *this;
	}
	
	
	
	
	
	
	Fraction  operator*(const Fraction& left, const Fraction& right) 
	{
		Fraction answer;
		
		answer.numerator = left.numerator *right.numerator ;
		answer.denominator= left.denominator * right.denominator;
		answer.simplify();
		
		return (answer);
	}
	
	
	
	
	
	Fraction  Fraction::operator*=(const Fraction& right) 
	{
		Fraction left(numerator,denominator);
		
		numerator = left.numerator *right.numerator ;
		denominator= left.denominator * right.denominator;
		simplify();
		
		return *this;
	}
	
	
	
	
	
	Fraction  operator/(const Fraction& left, const Fraction& right) 
	{
		Fraction answer;
		
		answer.numerator = left.numerator *right.denominator ;
		answer.denominator= left.denominator * right.numerator;
		answer.simplify();
		
		return (answer);
	}
	
	
	
	
	
	
	Fraction Fraction::operator/=(const Fraction& right) 
	{
		Fraction left(numerator,denominator);
		
		numerator = left.numerator *right.denominator ;
		denominator= left.denominator * right.numerator;
		simplify();
		
		return *this;
	}
	
	
	
	
	
	bool operator==(const Fraction& left, const Fraction& right)
	{
		if (!(right.denominator * left.numerator - left.denominator * right.numerator))
			return (1);
		else
			return (0);
		
	}
	
	
	
	
	
	bool operator!=(const Fraction& left, const Fraction& right)
	{
		if (!(right.denominator * left.numerator - left.denominator * right.numerator))
			return (0);
		else
			return (1);
		
	}
	
	
	
	
	
	bool operator>(const Fraction& left, const Fraction& right)
	{
		if ((right.denominator * left.numerator)  > (left.denominator * right.numerator) )
			return (1);
		else 
			return (0);
	}
	
	
	
	
	bool operator>=(const Fraction& left, const Fraction& right)
	{
		if ((right.denominator * left.numerator)  >= (left.denominator * right.numerator) )
			return (1);
		else 
			return (0);
	}
	
	
	
	
	
	bool operator<(const Fraction& left, const Fraction& right)
	{
		if ((right.denominator * left.numerator)  < (left.denominator * right.numerator) )
			return (1);
		else 
			return (0);
	}
	
	
	
	
	
	bool operator<=(const Fraction& left, const Fraction& right)
	{
		if ((right.denominator * left.numerator)  <= (left.denominator * right.numerator) )
			return (1);
		else 
			return (0);
	}
	
	
	
	
	//The increment operators  supported in  prefix  form for Fractions.
	Fraction Fraction::operator++()
	{
		numerator = numerator + denominator;
		return *this;
	}
	
	
	
	
	//The increment operators  supported in  postfix form for Fractions.
	Fraction Fraction::operator++(int)
	{
		Fraction temp(numerator, denominator);
		numerator = numerator + denominator;
		return temp;
	}
	
	
	
	
	
	Fraction Fraction::operator--()
	{
		numerator = numerator - denominator;
		return *this;
	}
	
	
	
	
	
	Fraction Fraction::operator--(int)
	{
		Fraction temp(numerator, denominator);
		numerator = numerator - denominator;
		return temp;
	}

	
}





/*
 
 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10
 Fraction [3] = -4
 Fraction [4] = 0
 Fraction [5] = 4+2/3
 Fraction [6] = 0
 
 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6
 Read Fraction = 5
 Read Fraction = -8
 Read Fraction = 1+2/5
 Read Fraction = -16+2/3
 Read Fraction = 1+1/4
 Read Fraction = 2
 Read Fraction = -4+1/4
 Read Fraction = -10+5/6
 
 ----- Testing relational operators between Fractions
 Comparing 1/2 to 1/2
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 Comparing 1/2 to -1/2
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing -1/2 to 1/10
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing 1/10 to 0
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing 0 to 0
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 
 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing -3 to 1/4
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 
 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = -1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = 1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5 = 4+1/3
 -2/3 - 5 = -5+2/3
 -2/3 * 5 = -3+1/3
 -2/3 / 5 = -2/15
 5 + -1+1/3 = 3+2/3
 5 - -1+1/3 = 6+1/3
 5 * -1+1/3 = -6+2/3
 5 / -1+1/3 = -3+3/4
 
 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = -4+1/2
 -1/2 * 4 = -2
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = 3+1/2
 3 * -1/2 = -1+1/2
 3 / -1/2 = -6
 
 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4 = 4+1/6
 4+1/6 -= 4 = 1/6
 1/6 *= 4 = 2/3
 2/3 /= 4 = 1/6
 4 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4
 4 *= -1/2 = -2
 -2 /= -1/2 = 4
 -1/2 += 5 = 4+1/2
 4+1/2 -= 5 = -1/2
 -1/2 *= 5 = -2+1/2
 -2+1/2 /= 5 = -1/2
 
 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1
 -1 /= 3 = -1/3
 
 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = 2/3
 ++g = 1+2/3
 Now g = 1+2/3
 g-- = 1+2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0
 */
