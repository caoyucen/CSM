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

#ifndef stack_hpp
#define stack_hpp

#include "list.hpp"


template <class T>
class Stack: public List<T> {	
public:
	bool empty() const;
	
	void push(const T& value);
	void pop();
	
	const T& top() const;
};

template <class T>
bool Stack<T>::empty() const {
	return List<T>::empty();
}

template <class T>
void Stack<T>::push(const T& value) {
	List<T>::push_back(value);
}

template <class T>
void Stack<T>::pop() {
	List<T>::pop_back();
}

template <class T>
const T& Stack<T>::top() const {
	return List<T>::back();
}


	
#endif /* stack_hpp */
