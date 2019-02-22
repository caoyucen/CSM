/*
 
 YUCEN CAO
 11/19/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 14_ mystring.cpp
 
 */


#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"
using namespace std;


/*
 Class Invariant: A MyString has one int char* member :strs.
A Mystring can do some Operator like get the length, also have some overloaded Operator
 */


namespace cs_mystring {
	
	
	//constructor
	MyString::MyString()
	{
		strs = new char[1];    
		strcpy(strs, "");
	}
	
	
	MyString::MyString(const char *inStrs)
	{
		strs = new char[strlen(inStrs) + 1];    
		strcpy(strs, inStrs);
	}
	
	
	MyString::MyString(const MyString& right)
	{
		strs = new char[strlen(right.strs) + 1];    
		strcpy(strs, right.strs);
	}
	
	
	
	
	//destructor
	MyString::~MyString()    
	{
		delete [] strs;
	}
	
	
	
	
	
	//attributes
	int MyString::length() const
	{
		int size;
		
		size = int(strlen(strs));
		return size;
	}
	
	
	
	//Overload operations
	MyString MyString::operator=(const MyString& right)    
	{
		if (this != &right){
			delete [] strs;
			strs = new char[strlen(right.strs) + 1];
			strcpy(strs, right.strs);
		}
		return *this;
	}
	
	
	
	
	//should simply print out its characters
	ostream& operator<<(ostream& out, const MyString& source)    
	{
		out << source.strs;
		return out;
	}
	
	
	
	
	//The funcion should skip any leading spaces and then read characters into the string up to the first whitespace character.
	istream& operator>>(istream& in, MyString& target)
	{
		while (isspace(in.peek())){
			in.ignore();
		}
		char temp[MyString::MAX_INPUT_SIZE + 1];
		in.getline(temp, MyString::MAX_INPUT_SIZE, ' '); //???
		delete [] target.strs;
		target.strs = new char[strlen(temp) + 1];
		strcpy(target.strs, temp);
		
		return in;
	}
	
	
	
	
	//The read() function will allow the client programmer to specify the delimiting character 
	void MyString::read(istream& in, char c)
	{
		char temp[MyString::MAX_INPUT_SIZE + 1];
		
		in.getline(temp, MyString::MAX_INPUT_SIZE, c); //???
		delete [] strs;
		strs = new char[strlen(temp) + 1];
		strcpy(strs, temp);
	}
	
	
	
	
	
	//MyString object should overload the square brackets [ ] operator to allow direct access to the individual characters of the string. This operation should range-check and assert if the index is out of bounds.
	char MyString::operator[](int index) const
	{
		assert(index >= 0 && index < strlen(strs));
		return strs[index];
	}
	
	
	
	
	//overload the square brackets [ ] operator, a non-const version that returns the client a reference to the char so they can change the value.
	char& MyString::operator[](int index) 
	{
		assert(index >= 0 && index < strlen(strs));
		return strs[index];
	}
	
	
	
	
	
	// compare operations: All six of the relational operators (<, <=, >, >=, ==, !=). They should be able to compare MyString objects to other MyStrings as well as MyStrings to c-strings. 
	bool operator==(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)==0?true:false;
	}
	bool operator!=(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)!=0?true:false;
	}
	bool operator<(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)<0?true:false;
	}
	bool operator<=(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)<=0?true:false;
	}
	bool operator>(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)>0?true:false;
	}
	bool operator>=(const MyString& left,const MyString& right)
	{
		return strcmp(left.strs,right.strs)>=0?true:false;
	}
	
	
	
	
	
	// + and += operations
	//Overload the + operator to do MyString concatenation. The two operator must be able to handle either MyString objects or C-strings on either side of the operator.
	MyString operator+(const MyString& left, const MyString& right)
	{
		MyString answer;
		
		delete [] answer.strs;
		answer.strs = new char[strlen(left.strs) + strlen(right.strs) + 1];
		strcpy(answer.strs, left.strs);
		strcat(answer.strs, right.strs);
		
		return (answer);
		
	}
	
	
	MyString operator+(const MyString& left, const char *v)
	{
		MyString answer;
		
		delete [] answer.strs;
		answer.strs = new char[strlen(left.strs) + strlen(v) + 1];
		strcpy(answer.strs, left.strs);
		strcat(answer.strs, v);
		
		return (answer);
		
	}
	
	
	
	//The two operator overload the shorthand += to combine concatenation and assignment. Only MyStrings can be on the left-hand side of a += operation, but either MyStrings or C-strings may appear on the right side.
	MyString MyString::operator+=(const MyString& right)
	{
		strs = strcat(strs, right.strs);
		
		return *this;
	}
	
	
	MyString MyString::operator+=(const char *v)
	{
		MyString answer;
		
		delete [] answer.strs;
		answer.strs = new char[strlen(strs) + strlen(v) + 1];
		strcpy(answer.strs, strs);
		strcat(answer.strs, v);
		
		return (answer);
	}
	
}


