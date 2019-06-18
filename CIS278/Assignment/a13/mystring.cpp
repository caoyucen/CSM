/*
 
 YUCEN CAO
 11/12/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 13_ mystring.cpp
 
 */


#include <iostream>
#include <cassert>
#include "mystring.h"
using namespace std;

namespace cs_mystring {
	
	
	
	//default constructor
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
	size_t MyString::length() const
	{
		size_t size;
		
		size = strlen(strs);
		return size;
	}
	
	
	
	
	MyString MyString::operator=(const MyString& right)    
	{
		if (this != &right){
			delete [] strs;
			strs = new char[strlen(right.strs) + 1];
			strcpy(strs, right.strs);
		}
		return *this;
	}
	
	
	

	
	ostream& operator<<(ostream& out, const MyString& source)    
	{
		out << source.strs;
		return out;
	}
	
	
	
	
	
//	istream& operator>>(istream& in, MyString& target)
//	//istream& operator>>(istream& in, InventoryItem& target)
//	{
//		while (isspace(in.peek())){
//			in.ignore();
//		}
//		
//		char temp[MyString::MAX_INPUT_SIZE + 1];
//		in.getline(temp, MyString::MAX_INPUT_SIZE, ' ');
//		delete [] target.strs;
//		target.strs = new char[strlen(temp) + 1];
//		strcpy(target.strs, temp);
//		//in >> target.units;
//		
//		return in;
//	}
	
	
	
	char MyString::operator[](int index) const
	{
		assert(index >= 0 && index < strlen(strs));
		return strs[index];
	}
	
	
	
	
	
	char& MyString::operator[](int index) 
	{
		assert(index >= 0 && index < strlen(strs));
		return strs[index];
	}
	
	
	
	
	
	// compare operations
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
		
	
	
	
}

