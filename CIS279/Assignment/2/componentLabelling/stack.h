//
//  stack.h
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include "list.h"

template <class T>
class Stack: public List<T> {	
public:
	bool empty();
	
	void push(const T& value);
	void pop();
	
	const T& top() const;
};

#endif /* stack_h */
