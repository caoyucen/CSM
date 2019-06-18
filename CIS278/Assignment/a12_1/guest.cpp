#include <iostream>
#include "fraction.h"
#include <fstream>
#include <cassert>
#include <string>
using namespace std;
using namespace cs_fraction;

void BasicTest();
void RelationTest();
void BinaryMathTest();
void MathAssignTest();
bool eof(ifstream& in);
string boolString(bool convertMe);


int main()
{
	BasicTest();
	RelationTest();
	BinaryMathTest();
	MathAssignTest();
}





void BasicTest()
{
	cout << "\n----- Testing basic Fraction creation & printing\n";
	cout << "(Fractions should be in reduced form, and as mixed numbers.)\n";
	
	const Fraction fr[] = {Fraction(4, 8), Fraction(-15,21), 
		Fraction(10), Fraction(12, -3),
		Fraction(), Fraction(28, 6), Fraction(0, 12)};
	
	for (int i = 0; i < 7; i++){
		cout << "Fraction [" << i <<"] = " << fr[i] << endl;
	}
	
	
	cout << "\n----- Now reading Fractions from file\n";
	ifstream in("Fraction.txt");
	assert(in);
	while (!eof(in)) {
		Fraction f;     
		if (in.peek() == '#') {   
			in.ignore(128, '\n');                       //skip this line, it's a comment
		} else {
			in >> f;
			cout << "Read Fraction = " << f << endl;
		}
	}
}


bool eof(ifstream& in)
{
	char ch;
	in >> ch;
	in.putback(ch);
	return !in;
}





string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	} else {
		return "false";
	}
}


void RelationTest()
{
	cout << "\n----- Testing relational operators between Fractions\n";
	
	const Fraction fr[] =  {Fraction(3, 6), Fraction(1,2), Fraction(-15,30), 
		Fraction(1,10), Fraction(0,1), Fraction(0,2)};
	
	for (int i = 0; i < 5; i++) {
		cout << "Comparing " << fr[i] << " to " << fr[i+1] << endl;
		cout << "\tIs left < right? " << boolString(fr[i] < fr[i+1]) << endl;
		cout << "\tIs left <= right? " << boolString(fr[i] <= fr[i+1]) << endl;
		cout << "\tIs left > right? " << boolString(fr[i] > fr[i+1]) << endl;
		cout << "\tIs left >= right? " << boolString(fr[i] >= fr[i+1]) << endl;
		cout << "\tDoes left == right? " << boolString(fr[i] == fr[i+1]) << endl;
		cout << "\tDoes left != right ? " << boolString(fr[i] != fr[i+1]) << endl;
	}
	
	cout << "\n----- Testing relations between Fractions and integers\n";
	Fraction f(-3,6);
	int num = 2;
	cout << "Comparing " << f << " to " << num << endl;
	cout << "\tIs left < right? " << boolString(f < num) << endl;
	cout << "\tIs left <= right? " << boolString(f <= num) << endl;
	cout << "\tIs left > right? " << boolString(f > num) << endl;
	cout << "\tIs left >= right? " << boolString(f >= num) << endl;
	cout << "\tDoes left == right? " << boolString(f == num) << endl;
	cout << "\tDoes left != right ? " << boolString(f != num) << endl;
	
	Fraction g(1,4);
	num = -3;
	cout << "Comparing " << num << " to " << g << endl;
	cout << "\tIs left < right? " << boolString(num < g) << endl;
	cout << "\tIs left <= right? " << boolString(num <= g) << endl;
	cout << "\tIs left > right? " << boolString(num > g) << endl;
	cout << "\tIs left >= right? " << boolString(num >= g) << endl;
	cout << "\tDoes left == right? " << boolString(num == g) << endl;
	cout << "\tDoes left != right ? " << boolString(num != g) << endl;  
}





void BinaryMathTest()
{    
	cout << "\n----- Testing binary arithmetic between Fractions\n";
	
	const Fraction fr[] = {Fraction(1, 6), Fraction(1,3), 
		Fraction(-2,3), Fraction(5), Fraction(-4,3)};
	
	for (int i = 0; i < 4; i++) {
		cout << fr[i] << " + " << fr[i+1] << " = " << fr[i] + fr[i+1] << endl;
		cout << fr[i] << " - " << fr[i+1] << " = " << fr[i] - fr[i+1] << endl;
		cout << fr[i] << " * " << fr[i+1] << " = " << fr[i] * fr[i+1] << endl;
		cout << fr[i] << " / " << fr[i+1] << " = " << fr[i] / fr[i+1] << endl;
	}
	
	cout << "\n----- Testing arithmetic between Fractions and integers\n";
	Fraction f(-1, 2);
	int num = 4;
	cout << f << " + " << num << " = " << f + num << endl;
	cout << f << " - " << num << " = " << f - num << endl;
	cout << f << " * " << num << " = " << f * num << endl;
	cout << f << " / " << num << " = " << f / num << endl;
	
	Fraction g(-1, 2);
	num = 3;
	cout << num << " + " << g << " = " << num + g << endl;
	cout << num << " - " << g << " = " << num - g << endl;
	cout << num << " * " << g << " = " << num * g << endl;
	cout << num << " / " << g << " = " << num / g << endl;
}






void MathAssignTest()
{    
	cout << "\n----- Testing shorthand arithmetic assignment on Fractions\n";
	
	Fraction fr[] = {Fraction(1, 6), Fraction(4), 
		Fraction(-1,2), Fraction(5)};
	
	for (int i = 0; i < 3; i++) {
		cout << fr[i] << " += " << fr[i+1] << " = ";
		cout << (fr[i] += fr[i+1]) << endl;
		cout << fr[i] << " -= " << fr[i+1] << " = ";
		cout << (fr[i] -= fr[i+1]) << endl;
		cout << fr[i] << " *= " << fr[i+1] << " = ";
		cout << (fr[i] *= fr[i+1]) << endl;
		cout << fr[i] << " /= " << fr[i+1] << " = ";
		cout << (fr[i] /= fr[i+1]) << endl;
	}
	
	cout << "\n----- Testing shorthand arithmetic assignment using integers\n";
	Fraction f(-1, 3);
	int num = 3;
	cout << f << " += " << num << " = ";
	cout << (f += num) << endl;
	cout << f << " -= " << num << " = ";
	cout << (f -= num) << endl;
	cout << f << " *= " << num << " = ";
	cout << (f *= num) << endl;
	cout << f << " /= " << num << " = ";
	cout << (f /= num) << endl;
	
	cout << "\n----- Testing increment/decrement prefix and postfix\n";
	Fraction g(-1, 3);
	cout << "Now g = " << g << endl;
	cout << "g++ = " << g++ << endl;
	cout << "Now g = " << g << endl;
	cout << "++g = " << ++g << endl;
	cout << "Now g = " << g << endl;
	cout << "g-- = " << g-- << endl;
	cout << "Now g = " << g << endl;
	cout << "--g = " << --g << endl;
	cout << "Now g = " << g << endl;
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
 
 
 */

