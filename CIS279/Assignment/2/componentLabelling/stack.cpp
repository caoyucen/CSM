//
//  stack.cpp
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#include "stack.h"

template <class T>
bool Stack<T>::empty() {
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
