/*
 
 YUCEN CAO
 10/22/2018
 CIS 278
 Assignment 10_fraction.cpp

 */



#include <iostream>
#include "fraction.h"
#include <cassert>
using namespace std;

/*
 Class Invariant: A fraction has two int data member : numerator and denominator. Internal
 operations always result in valid dates,that means that the denominator can not be 0.
 
 
 */






Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}





Fraction::Fraction(int inNumerator, int inDenominator)
{
	assert(inDenominator != 0);
	numerator = inNumerator;
	denominator = inDenominator;
	simplify();
}





void Fraction:: print() const
{
	cout << numerator << "/" << denominator;
}





// The public member function  get the fraction that multiplied by  otherFraction
Fraction Fraction:: multipliedBy(Fraction otherFraction) const
{
	int reNumerator;
	int reDenominator;
	
	reNumerator = numerator * otherFraction.numerator;
	reDenominator= denominator * otherFraction.denominator;
	Fraction result(reNumerator, reDenominator);
	
	return (result);
}





// The public member function  get the fraction that divided by  otherFraction
Fraction Fraction:: dividedBy(Fraction otherFraction) const
{
	int reNumerator;
	int reDenominator;
	
	reNumerator = numerator *otherFraction.denominator ;
	reDenominator= denominator * otherFraction.numerator;
	Fraction result(reNumerator, reDenominator);
	
	return (result);
}





// The public member function  get the fraction that added by  otherFraction
Fraction Fraction:: addedTo(Fraction otherFraction) const
{
	int reNumerator;
	int reDenominator;
	
	reDenominator = denominator * otherFraction.denominator;
	reNumerator= denominator * otherFraction.numerator + otherFraction.denominator * numerator;
	Fraction result(reNumerator, reDenominator);
	
	return (result);
}





// The public member function  get the fraction that subtract by  otherFraction
Fraction Fraction:: subtract(Fraction otherFraction) const
{
	int reNumerator;
	int reDenominator;
	
	reDenominator = denominator * otherFraction.denominator;
	reNumerator=  otherFraction.denominator * numerator - denominator * otherFraction.numerator;
	Fraction result(reNumerator, reDenominator);
	
	return (result);
}





//The public member function finds the two fractions are equal or not
bool Fraction:: isEqualTo(Fraction otherFraction) const
{
	if (!(otherFraction.denominator * numerator - denominator * otherFraction.numerator))
		return (1);
	else
		return (0);
	
}






// This private member function simplify the fraction by find the biggest number that denominator and  numerator both can be divisibled by the number.
void Fraction::simplify()
{
	int num;
	
	if (numerator >= denominator)
	{
		num = denominator;
	}
	else
	{
		num = numerator;
	}
	
	for ( int i = num; i > 0 ; i--)
	{
		if (((numerator % i ) + (denominator % i)) == 0)
		{
			numerator = numerator / i;
			denominator = denominator / i;
			break;
		}
	}
}
