/*
 
 YUCEN CAO
 10/15/2018
 CIS 278
 Assignment 9_1
 
 Write a Fraction class whose objects will represent Fractions.
 like +, _, *, / 
 */



#include <iostream>
using namespace std;



class Fraction
{
	public:
	void set(int inNumerator, int inDenominator);
	void print();
	Fraction multipliedBy(Fraction otherFraction);
	Fraction dividedBy(Fraction otherFraction);
	Fraction addedTo(Fraction otherFraction);
	Fraction subtract(Fraction otherFraction);
	bool isEqualTo(Fraction otherFraction);
	
	
	private:
	int numerator;
	int denominator;
};





void Fraction::set(int inNumerator, int inDenominator)
{
	numerator = inNumerator;
	denominator = inDenominator;
}




void Fraction:: print()
{
	cout << numerator << "/" << denominator;
}




Fraction Fraction:: multipliedBy(Fraction otherFraction)
{
	Fraction result;
	int reNumerator;
	int reDenominator;
	
	reNumerator = numerator * otherFraction.numerator;
	reDenominator= denominator * otherFraction.denominator;
	result.set(reNumerator, reDenominator);
	
	return (result);
}




Fraction Fraction:: dividedBy(Fraction otherFraction)
{
	Fraction result;
	int reNumerator;
	int reDenominator;
	
	reNumerator = numerator *otherFraction.denominator ;
	reDenominator= denominator * otherFraction.numerator;
	result.set(reNumerator, reDenominator);
	
	return (result);
}




Fraction Fraction:: addedTo(Fraction otherFraction)
{
	Fraction result;
	int reNumerator;
	int reDenominator;
	
	reDenominator = denominator * otherFraction.denominator;
	reNumerator= denominator * otherFraction.numerator + otherFraction.denominator * numerator;
	result.set(reNumerator, reDenominator);
	
	return (result);
}




Fraction Fraction:: subtract(Fraction otherFraction)
{
	Fraction result;
	int reNumerator;
	int reDenominator;
	
	reDenominator = denominator * otherFraction.denominator;
	reNumerator=  otherFraction.denominator * numerator - denominator * otherFraction.numerator;
	result.set(reNumerator, reDenominator);
	
	return (result);
}




bool Fraction:: isEqualTo(Fraction otherFraction)
{
	if (!(otherFraction.denominator * numerator - denominator * otherFraction.numerator))
		return (1);
	else
		return (0);
	
}



int main()
{
	Fraction f1;
	Fraction f2;
	Fraction result;
	
	f1.set(9, 8);
	f2.set(2, 3);
	
	cout << "The product of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.multipliedBy(f2);
	result.print();
	cout << endl;
	
	cout << "The quotient of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.dividedBy(f2);
	result.print();
	cout << endl;
	
	cout << "The sum of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.addedTo(f2);
	result.print();
	cout << endl;
	
	cout << "The difference of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.subtract(f2);
	result.print();
	cout << endl;
	
	if (f1.isEqualTo(f2)){
		cout << "The two Fractions are equal." << endl;
	} else {
		cout << "The two Fractions are not equal." << endl;
	}
}

