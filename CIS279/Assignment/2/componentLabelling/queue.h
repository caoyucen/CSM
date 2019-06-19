//
//  queue.h
//  componentLabelling
//
//  Created by baobao on 2019/2/24.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include "list.h"

template <class T>
class Queue: public List<T> {
public:
	bool empty();
	
	void push_back(const T& value);
	void pop_front();
	
	const T& front() const;

};

#endif /* queue_h */
