/*
 
 YUCEN CAO
 10/22/2018
 CIS 278
 Assignment 10_fraction.h

 */


#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;


/* 
 
 The fraction class can be used to create fraction
 
 Fraction ();
 post: The calling object has been created and initialized to 0 and 1
 
 
 Fraction (int inNumerator, int inDenominator);
 post: The calling object has been created and initialized so that the numerator is inNumerator, the  denominator is inDenominator
 
 void print() const;
 post: The calling object has been printed  in the format numerator/denominator.
 
 Fraction multipliedBy(Fraction otherFraction) const;
 post: Returns the Fraction that multiplied by otherFraction.
 
 Fraction dividedBy(Fraction otherFraction) const;
 post: Returns the Fraction that divided by otherFraction.
 
 Fraction addedTo(Fraction otherFraction) const;
 post: Returns the Fraction that added by otherFraction.
 
 Fraction subtract(Fraction otherFraction) const;
 post: Returns the Fraction that subtract by otherFraction.
 
 bool isEqualTo(Fraction otherFraction) const;
 post: Returns ture if the two fraction are equal, return false if two fraction are not equal
 
 void simplify();
 post: simplify the fraction in format numerator/denominator.
 
 */     


class Fraction
{
public:
	Fraction ();
	Fraction (int inNumerator, int inDenominator);
	void print() const;
	Fraction multipliedBy(Fraction otherFraction) const;
	Fraction dividedBy(Fraction otherFraction) const;
	Fraction addedTo(Fraction otherFraction) const;
	Fraction subtract(Fraction otherFraction) const;
	bool isEqualTo(Fraction otherFraction) const;
	
private:
	void simplify();

private:
	int numerator;
	int denominator;
};

#endif 
