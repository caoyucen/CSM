//
//  mystring3.cpp
//  a16_2.cpp
//
//  Created by baobao on 2018/12/4.
//  Copyright © 2018年 YUCEN CAO. All rights reserved.
//

#include "mystring.h"
#include "mystring.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

namespace cs_mystring{
	MyString::MyString(const char* inString)
	{
		str = new char[strlen(inString) + 1];
		strcpy(str, inString);
	}
	
	
	
	
	
	
	
	
	MyString::MyString()
	{
		str = new char[1];
		strcpy(str, "");
	}
	
	
	
	
	
	
	
	MyString::MyString(const MyString& copyMe)
	{
		str = new char[strlen(copyMe.str) + 1];
		strcpy(str, copyMe.str);
	}
	
	
	
	
	
	
	MyString::~MyString()
	{
		delete [] str;
	}
	
	
	
	
	
	
	
	ostream& operator<<(ostream& out, const MyString& printMe)
	{
		out << printMe.str;
		return out;
	}
	
	
	
	
	
	
	
	istream& operator>>(istream& in, MyString& readMe)
	{
		delete [] readMe.str;
		char tempStr[MyString::MAX_INPUT_SIZE + 1];
		in >> tempStr;
		readMe.str = new char[strlen(tempStr) + 1];
		strcpy(readMe.str, tempStr);
		return in;
	}
	
	
	
	
	
	
	
	void MyString::read(istream& in, char delimiter)
	{
		char tempStr[MyString::MAX_INPUT_SIZE + 1];
		
		in.getline(tempStr, MyString::MAX_INPUT_SIZE + 1, delimiter);
		delete [] str;
		str = new char[strlen(tempStr) + 1];
		strcpy(str, tempStr);
	}
	
	
	
	
	
	
	
	char MyString::operator[](int index) const
	{
		assert (index >= 0 && index < strlen(str));
		return str[index];
	}
	
	
	
	
	
	
	
	char& MyString::operator[](int index)
	{
		assert (index >= 0 && index < strlen(str));
		return str[index];
	}
	
	
	
	
	
	
	
	bool operator<(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) < 0;
	}
	
	
	
	
	
	bool operator>(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) > 0;
	}
	
	
	
	
	
	bool operator<=(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) <= 0;
	}
	
	
	
	
	
	bool operator>=(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) >= 0;
	}
	
	
	
	
	
	bool operator==(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) == 0;
	}
	
	
	
	
	
	bool operator!=(const MyString& left, const MyString& right)
	{
		return strcmp(left.str, right.str) != 0;
	}
	
	
	
	
	
	
	
	MyString MyString::operator=(const MyString& right)
	{
		if (this !=& right){
			delete [] str;
			str = new char[strlen(right.str) + 1];
			strcpy(str, right.str);
		}
		
		return *this;
	}
	
	
	
	
	
	
	
	MyString operator+(const MyString& left, const MyString& right)
	{
		MyString tempStr;
		delete [] tempStr.str;
		tempStr.str = new char[strlen(left.str) + strlen(right.str) + 1];
		strcpy(tempStr.str, left.str);
		strcat(tempStr.str, right.str);
		return tempStr;
	}
	
	
	
	
	
	
	
	MyString MyString::operator+=(const MyString& right)
	{
		*this = *this + right;
		return *this;
	}
	
	
	
	
	
	
	
	int MyString::length() const
	{
		return strlen(str);
	}
}
