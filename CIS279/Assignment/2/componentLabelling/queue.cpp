//
//  queue.cpp
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#include "queue.h"

template <class T>
bool Queue<T>::empty() {
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
