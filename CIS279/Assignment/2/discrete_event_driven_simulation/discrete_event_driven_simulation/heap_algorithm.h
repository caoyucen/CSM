//
//  heap_algorithm.h
//  discrete_event_driven_simulation
//
//  Created by baobao on 2019/3/10.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#ifndef heap_algorithm_h
#define heap_algorithm_h

#include <iterator>
#include <algorithm>
#include <iostream>

namespace heap_algorithm {
	
	template <class RandIterator>
	bool is_leaf(RandIterator first, RandIterator last, RandIterator current) {
		return current > first + (last - first - 2) / 2;
	}

	template <class RandIterator, class Compare>
	void sift_up(RandIterator first, RandIterator last, Compare comp) {
		if (last - first > 1) {
			auto parent = first + (last - first - 1) / 2;
			auto tmp = last - 1;
			while (parent >= first && !comp(*parent, *tmp)) {  
				std::swap(*tmp, *parent);
				tmp = parent;
				parent = first + ((parent - first - 1) >= 0? (parent - first - 1) / 2: -1); // mark the head node
			}
		}
	}
	
	template <class RandIterator, class Compare>
	void sift_down(RandIterator first, RandIterator last, RandIterator start, Compare comp) {
		// compare with children and swap if comp is not satisfied
		if (last - first > 1) {
			if (!is_leaf(first, last, start)) {
				// start is leaf node
				auto left = first + 2 * (start - first) + 1;
				auto right = first + 2 * (start - first) + 2;
//				std::cout << "start=" << *start << "left=" << *left << "right=" << *right << std::endl;
				if (right < last && !comp(*start, *right) && !comp(*left, *right)) {
					std::swap(*start, *right);
//					std::cout << "swapping " << start - first << "(" << *start << ") and " << right - first << "(" << *right << ")" << std::endl;
					sift_down(first, last, right, comp);
				} else if (!comp(*start, *left)) {
					std::swap(*start, *left);
//					std::cout << "swapping " << start - first << "(" << *start << ") and " << left - first << "(" << *left << ")" << std::endl;
					sift_down(first, last, left, comp);
				}
			}
		}
	}
	
	template <class RandIterator, class Compare>
	void push_heap(RandIterator first, RandIterator last, Compare comp) {
		// New element is at the bottom and sift up
		sift_up(first, last, comp);
	}
	
	template <class RandIterator, class Compare>
	void pop_heap(RandIterator first, RandIterator last, Compare comp) {
		// Swap the first element and last element, and then sift down
		if (last - first > 1) {
			std::swap(*first, *(--last));
			sift_down(first, last, first, comp);
		}

	}
	
	template <class RandIterator, class Compare>
	void make_heap(RandIterator first, RandIterator last, Compare comp) {
		if (last - first > 1) {
			for (auto i = (last - first - 2) / 2 ; i >=0 ; i--) {
				// Starting from the last parent leaf, sift down
				sift_down(first, last, first + i, comp);
			}
		}
	}
}




#endif /* heap_algorithm_h */
