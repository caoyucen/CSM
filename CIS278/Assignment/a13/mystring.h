/*
 
 YUCEN CAO
 11/12/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 13_ mystring.h
 
 
 */

#ifndef mystring_h
#define mystring_h
#include <iostream>
using namespace std;
#pragma warning(disable:4996)


namespace cs_mystring {
	class MyString
	{
	public:
			static const int MAX_INPUT_SIZE = 127;
		// constructor
		MyString();
		MyString(const char *inStrs);
		MyString(const MyString& right);
		
		// destructor
		~MyString();
		
		// attributes
		size_t length() const;
		MyString operator=(const MyString& right);
		friend std::ostream& operator<<(std::ostream& out, const MyString& source);
		//friend std::istream& operator>>(std::istream& in, MyString& target);
		char operator[](int index) const;
		char& operator[](int index);
		
		// compare operations
		friend bool operator==(const MyString& left,const MyString& right);	
		friend bool operator!=(const MyString& lhs,const MyString& rhs);
		friend bool operator<(const MyString& lhs,const MyString& rhs);	
		friend bool operator<=(const MyString& lhs,const MyString& rhs);		
		friend bool operator>(const MyString& lhs,const MyString& rhs);
		friend bool operator>=(const MyString& lhs,const MyString& rhs);
	
	public:
		char* strs;
		
	};
}


#endif 






/*
 ----- Testing basic String creation & printing
 string [0] = Wow
 string [1] = C++ is neat!
 string [2] = 
 string [3] = a-z
 
 ----- Testing access to characters (using const)
 Whole string is abcdefghijklmnopqsrtuvwxyz
 now char by char: abcdefghijklmnopqsrtuvwxyz
 ----- Testing access to characters (using non-const)
 Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ
 
 ----- Testing relational operators between MyStrings
 Comparing app to apple
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing apple to 
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 Comparing  to Banana
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing Banana to Banana
 Is left < right? false
 Is left <= right? true
 Is left > right? false
 Is left >= right? true
 Does left == right? true
 Does left != right ? false
 
 ----- Testing relations between MyStrings and char *
 Comparing he to hello
 Is left < right? true
 Is left <= right? true
 Is left > right? false
 Is left >= right? false
 Does left == right? false
 Does left != right ? true
 Comparing why to wackity
 Is left < right? false
 Is left <= right? false
 Is left > right? true
 Is left >= right? true
 Does left == right? false
 Does left != right ? true
 
 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is Binky
 val is winky
 after assign,  val is Binky
 */
