//
//  list.h
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef list_h
#define list_h

#include <iostream>
using namespace std;

template <class T>
class ListNode {
private:
	T value;
	ListNode* next;
	ListNode* prev;

public:
	ListNode();
	ListNode(const T& value, ListNode<T>* next = NULL, ListNode<T>* prev = NULL);
	
	T& getValue();
};


template <class T>
class List {
private:
	ListNode<T>* begin;
	ListNode<T>* end;
	
public:
	List();
	~List();
	
	bool empty();
		
	void push_back(const T& value);
	void erase(ListNode<T>* position);
	void pop_front();
	void pop_back();
	
	const T& front() const;
	const T& back() const;
	 
	
};

#endif /* list_h */
