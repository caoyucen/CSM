//
//  list.cpp
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

# include "list.h"

// ListNode
template <class T>
ListNode<T>::ListNode()
:next(NULL), prev(NULL) {}

template <class T>
ListNode<T>::ListNode(const T& value, ListNode<T>* next, ListNode<T>* prev) 
:value(value), next(next), prev(prev){}

template <class T>
T& ListNode<T>::getValue() {
	return value;
}

// List
template <class T>
List<T>::List() {
	// Setinel nodes
	begin = new ListNode<T>();
	end = new ListNode<T>();
	begin -> next = end;
	end -> prev = begin;
}

// 1 -> 2 -> 3
template <class T>
List<T>::~List() {
	auto curr = begin;
	while (curr != NULL) {
		auto tmp = curr;
		curr -> next -> prev = NULL;
		curr = curr -> next;
		delete tmp;
	}
}

template <class T>
bool List<T>::empty() {
	return begin -> next == end;
}

template <class T>
void List<T>::push_back(const T& value) {
	auto tmp = new ListNode<T>(value, end, end -> prev);
	end -> prev = tmp;
	tmp -> prev -> next = tmp;
}

template <class T>
void List<T>::erase(ListNode<T>* position) {
	assert(!empty());
	auto tmp = position;
	tmp -> next -> prev = tmp -> prev;
	tmp -> prev -> next = tmp -> next;
	delete tmp;
}

template <class T>
void List<T>::pop_front() {
	erase(begin -> next);
}

template <class T>
void List<T>::pop_back() {
	erase(end -> prev);
}

template <class T>
const T& List<T>::front() const {
	assert(!empty());
	return begin -> next -> value;
}

template <class T>
const T& List<T>::back() const {
	assert(!empty());
	return end -> prev -> value;
}



