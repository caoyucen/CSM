/*
 
 YUCEN CAO
 11/5/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 12_ fraction.h
 
 
 */


#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

/* 
 
 The fraction class can be used to create a fraction and do some simple operator.
 
 Fraction (int inNumerator = 0, int inDenominator = 1);
 	pre: the inDenominator can not be 0
 	post: The calling object has been created and initialized so that the numerator is inNumerator, the  denominator is inDenominator
 
 friend std::ostream& operator<<(std::ostream& out,const Fraction& right);
 	pre: None
 	post: Print fraction in three ways. Whole numbers should print without a denominator (e.g. not 3/1 but just 3). Improper Fractions should be printed as a mixed number with a + sign between the two parts (2+1/2). Negative Fractions should be printed with a leading minus sign.
 
 friend std::istream& operator>>(std::istream& in, Fraction& right);
 	pre: None
	post: Operator must read exactly one fraction value from input(mixed number, negative number, whole numbers, etc). 
 
 friend Fraction operator+(const Fraction& left, const Fraction& right);
 	pre: None
	 post: Returns the Fraction that added by Fraction right.
 
 friend Fraction operator-(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns the Fraction that subtract by Fraction right.
 
 friend Fraction operator*(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns the Fraction that multiplied by Fraction right
 
 friend Fraction operator/(const Fraction& left, const Fraction& right);
	 pre: const Fraction& right can not be 0
	 post: Returns the Fraction that divided by Fraction right.
 
 Fraction operator+=(const Fraction& right);
	 pre:None
	 post: Return the Fraction that add left(this fraction) equals to right 
 
 Fraction operator-=(const Fraction& right);
	 pre:None
	 post: Return the Fraction that be subtracted by left(this fraction)  equals to right.
 
 Fraction operator*=(const Fraction& right);
	 pre: if the  Numerator is 0, the Fraction right has to be 0
	 post: Return the Fraction that multiplied left(this fraction) equals to right
 
 Fraction operator/=(const Fraction& right);
	 pre: if the  Numerator is 0, the Fraction right has to be 0
	 post: Return the Fraction that be divided by left(this fraction)  equals to right.
 
 friend bool operator==(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if the two fraction are equal, return false if two fraction are not equal
 
 friend bool operator<=(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if the two fraction are equal or left < right, else return false
 
 friend bool operator<(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if left < right, else return false
 
 friend bool operator>=(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if the two fraction are equal or left > right, else return false
 
 friend bool operator>(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if left > right, else return false
 
 friend bool operator!=(const Fraction& left, const Fraction& right);
	 pre: None
	 post: Returns ture if the two fraction are not equal, return false if two fraction are equal
 
 Fraction operator++();
	 pre: None
	 post: Return this fraction, then add 1
 
 Fraction operator++(int);
	 pre: None
	 post: Add 1, then return the fraction
 
 Fraction operator--();
	 pre: None
	 post: Return this fraction, then subtract 1
 
 Fraction operator--(int);
	 pre: None
	 post: Subtract 1, then return the fraction
 
 
 void simplify();
	 pre: The Denominator can not be 0
	 post:  Fractions will return the fraction which still be improper Fractions.
 
 
 */     



namespace cs_fraction {
	
	class Fraction
	{
	public:
		Fraction (int inNumerator = 0, int inDenominator = 1);
		friend std::ostream& operator<<(std::ostream& out,const Fraction& right);
		friend std::istream& operator>>(std::istream& in, Fraction& right);
		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);
		Fraction operator+=(const Fraction& right);
		Fraction operator-=(const Fraction& right);
		Fraction operator*=(const Fraction& right);
		Fraction operator/=(const Fraction& right);
		friend bool operator==(const Fraction& left, const Fraction& right);
		friend bool operator<=(const Fraction& left, const Fraction& right);
		friend bool operator<(const Fraction& left, const Fraction& right);
		friend bool operator>=(const Fraction& left, const Fraction& right);
		friend bool operator>(const Fraction& left, const Fraction& right);
		friend bool operator!=(const Fraction& left, const Fraction& right);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);
		
		
	private:
		int numerator;
		int denominator;
		
		void simplify();
	};
	
}
#endif 


