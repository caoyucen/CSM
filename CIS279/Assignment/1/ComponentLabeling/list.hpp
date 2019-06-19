/**  Image Component Labeling
 *  Project 1
 *  < YUCEN CAO >
 *  < 02/24/2019 >
 **  The program maintains a 2-D grid (array) of objects, where each object
 keeps track of two values, the image component label (to be assigned by
 DFS or BFS), and the order in which the pixel was discovered, which depends
 on the search strategy (DFS or BFS). Accordingly, each pixel is represented
 by an object that encapsulates a label (component label: 2, 3, 4, ...) and
 (order of discovery: 1, 2, 3, ...).
 *  . . .
 *  . . .
 **/

#ifndef list_hpp
#define list_hpp

#include <iostream>

template <class T>
class ListNode {
public:
	T value;
	ListNode* next;
	ListNode* prev;
	
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
	
	bool empty() const;
	
	void push_back(const T& value);
	void erase(ListNode<T>* position);
	void pop_front();
	void pop_back();
	
	const T& front() const;
	const T& back() const;	
};

template <class T>
ListNode<T>::ListNode()
:value(T()), next(NULL), prev(NULL) {}

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
		curr = tmp -> next;
		delete tmp;
	}
}

template <class T>
bool List<T>::empty() const {
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

#endif /* list_hpp */
