//
//  priority_queue.h
//  discrete_event_driven_simulation
//
//  Created by baobao on 2019/3/10.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef priority_queue_h
#define priority_queue_h

#include <vector>
#include <functional>
#include "heap_algorithm.h"

template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type> >
class PriorityQueue {
protected:
	Container c;
	Compare comp;
		
public:
	// Constructors & Destructors
	PriorityQueue(Container);  // Default contructor, intialize empty container and use default std::less for key compare
	PriorityQueue(Container&& c = Container(), Compare&& compare = Compare()); 

	// Element access
	const T& top() const;

	// Capacity
	bool empty() const;
	size_t size() const;
	
	// Modifiers
	void push(T&& v);
	void pop();
	//PriorityQueue& operator=(PriorityQueue&& other); // Return *this
		
};

template <class T, class Container, class Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue(Container&& c, Compare&& comp)
:c(c), comp(comp) {}

template <class T, class Container, class Compare>
const T& PriorityQueue<T, Container, Compare>::top() const {
	assert(!c.empty());
	return c.front();
}

template <class T, class Container, class Compare>
bool PriorityQueue<T, Container, Compare>::empty() const {
	return c.empty();
}

template <class T, class Container, class Compare>
size_t PriorityQueue<T, Container, Compare>::size() const {
	return c.size();
}

template <class T, class Container, class Compare>
void PriorityQueue<T, Container, Compare>::push(T&& v) {
//	std::cout << "pushing " << v << std::endl; 
	c.push_back(v);
	heap_algorithm::push_heap(c.begin(), c.end(), comp);
}

template <class T, class Container, class Compare>
void PriorityQueue<T, Container, Compare>::pop() {
	heap_algorithm::pop_heap(c.begin(), c.end(), comp);
	c.pop_back();
}

#endif /* priority_queue_h */
