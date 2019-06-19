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

#ifndef queue_hpp
#define queue_hpp

#include "list.hpp"

template <class T>
class Queue: public List<T> {
public:
	bool empty() const;
	
	void push_back(const T& value);
	void pop_front();
	
	const T& front() const;
};

template <class T>
bool Queue<T>::empty() const {
	return List<T>::empty();
}

template <class T>
void Queue<T>:: push_back(const T &value) {
	List<T>::push_back(value);
}

template <class T>
void Queue<T>::pop_front() {
	List<T>::pop_front();
}

template <class T>
const T& Queue<T>::front() const {
	return List<T>::front();
}

#endif /* queue_hpp */
