/*
 
 YUCEN CAO
 11/19/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 14_ mystring.h
 
 */



/* 
 
 The Mystring class can be used to create a string and do some operator.
 A Mystring can do some Operator like get the length, also have some overloaded Operator

 
 // attributes
 int length() const;
 pre: None
 post:  Return the size of strs in the class
 
 //Overload operations
 MyString operator=(const MyString& right);
 pre:None
 post: Return this class, and the strs in the class equals to right,strs
 
 friend std::ostream& operator<<(std::ostream& out, const MyString& source);
 pre: None
 post:Print mystring, print the strs in the class
 
 friend std::istream& operator>>(std::istream& in, MyString& target);
 pre:None
 post:The >> operator should skip any leading spaces and then read characters into the string up to the first whitespace character.
 
 void read(std::istream& in, char c);
 pre:None
 post: It should not skip leading spaces, get the string line by line
 
 char operator[](int index) const;
 pre:None
 post:Allows read access to the chars, Return the chars
 
 char& operator[](int index);
 pre:None
 post: Return the client a reference to the char so they can change the value.
 
 
 // compare operations
 friend bool operator==(const MyString& left,const MyString& right);	
 pre:None
 post:Returns ture if the two MyString are equal, return false if two MyString are not equal
 
 friend bool operator!=(const MyString& left,const MyString& right);
 pre:None
 post:Returns false if the two MyString are equal, return ture if two MyString are not equal
 
 friend bool operator<(const MyString& left,const MyString& right);	
 pre:None
 post:Returns ture if left < right, else return false
 
 friend bool operator<=(const MyString& left,const MyString& right);		
 pre:None
 post:Returns ture if the two MyString are equal or left < right, else return false
 
 friend bool operator>(const MyString& left,const MyString& right);
 pre:None
 post:Returns ture if left > right, else return false
 
 friend bool operator>=(const MyString& left,const MyString& right);
 pre:None
 post:Returns ture if the two MyString are equal or left > right, else return false
 
 // + and += operations
 friend MyString operator+(const MyString& left, const MyString& right);
 pre:The operator must be able to handle either MyString objects or C-strings on either side of the operator
 post:Add MyString& left and MyString& right
 
 friend MyString operator+(const MyString& left, const char *v);
 pre:The operator must be able to handle either MyString objects or C-strings on either side of the operator
 post:Add MyString& left with char *v
 
 MyString operator+=(const MyString& right);
 pre:Only MyStrings can be on the left-hand side
 post:Return the Mystring add the MyString& right
 
 MyString operator+=(const char *v);
 pre:Only MyStrings can be on the left-hand side
 post:Return the Mystring with char*v
 
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
		int length() const;
		
		//Overload operations
		MyString operator=(const MyString& right);
		friend std::ostream& operator<<(std::ostream& out, const MyString& source);
		friend std::istream& operator>>(std::istream& in, MyString& target);
		void read(std::istream& in, char c);
		char operator[](int index) const;
		char& operator[](int index);
		
		// compare operations
		friend bool operator==(const MyString& left,const MyString& right);	
		friend bool operator!=(const MyString& left,const MyString& right);
		friend bool operator<(const MyString& left,const MyString& right);	
		friend bool operator<=(const MyString& left,const MyString& right);		
		friend bool operator>(const MyString& left,const MyString& right);
		friend bool operator>=(const MyString& left,const MyString& right);
		
		// + and += operations
		friend MyString operator+(const MyString& left, const MyString& right);
		friend MyString operator+(const MyString& left, const char *v);
		MyString operator+=(const MyString& right);
		MyString operator+=(const char *v);
		
		
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
 
 ----- Now reading MyStrings from file
 
 ----- first, word by word
 Read string = The
 Read string = first
 Read string = time
 Read string = we
 Read string = will
 Read string = read
 Read string = individual
 Read string = words,
 Read string = next
 Read string = we
 Read string = read
 Read string = whole
 Read string = lines
 
 ----- now, line by line
 Read string = The  first  time  we  will 
 Read string =    read individual words, next    
 Read string = we read whole lines
 
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
 
 ----- Testing concatentation on MyStrings
 outrageous + milk = outrageousmilk
 milk +  = milk
 + cow = cow
 cow + bell = cowbell
 
 ----- Testing concatentation between MyString and char *
 abcde + XYZ = abcdeXYZ
 XYZ + abcde = XYZabcde
 
 ----- Testing shorthand concat/assign on MyStrings
 who += what = whowhatandwhowhat
 what += WHEN = whatWHENandwhatWHEN
 WHEN += Where = WHENWhereandWHENWhere
 Where += why = WherewhyandWherewhy
 
 ----- Testing shorthand concat/assign using char *
 I love  += programming = I love programming
 
 ----- Testing copy constructor and operator= on MyStrings
 original is cake, copy is fake
 original is cake, copy is fake
 after self assignment, copy is Copy Cat
 Testing pass & return MyStrings by value and ref
 after calling Append, sum is BinkyBoo
 val is winky
 after assign,  val is BinkyBoo
 Program ended with exit code: 0
 */



