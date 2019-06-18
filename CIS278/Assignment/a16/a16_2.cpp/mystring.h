//
//  mystring3.hpp
//  a16_2.cpp
//
//  Created by baobao on 2018/12/4.
//  Copyright © 2018年 YUCEN CAO. All rights reserved.
//

#ifndef mystring_h
#define mystring_h

#include <stdio.h>
#include <iostream>
using namespace std;

namespace cs_mystring{
	class MyString {
	public:
		MyString(const char* inString);
		MyString();
		MyString(const MyString& copyMe);
		~MyString();
		friend std::ostream& operator<<(std::ostream& out, const MyString& printMe);
		friend std::istream& operator>>(std::istream& in, MyString& readMe);
		void read(std::istream& in, char delimeter);
		static const int MAX_INPUT_SIZE = 127;
		char operator[] (int index) const;
		char& operator[](int index);
		friend bool operator<(const MyString& left, const MyString& right);
		friend bool operator>(const MyString& left, const MyString& right);
		friend bool operator<=(const MyString& left, const MyString& right);
		friend bool operator>=(const MyString& left, const MyString& right);
		friend bool operator==(const MyString& left, const MyString& right);
		friend bool operator!=(const MyString& left, const MyString& right);
		MyString operator=(const MyString& right);
		friend MyString operator+(const MyString& left, const MyString& right);
		MyString operator+=(const MyString& right);
		int length() const;
	private:
		char *str;
	};
}

#endif /* mystring_h */
