//
//  main.cpp
//  discrete_event_driven_simulation
//
//  Created by Yucen Cao on 2019/3/10.
//  Copyright © 2019年 YUCEN CAO. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "priority_queue.h"
#include "heap_algorithm.h"

using namespace std;

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	vector<int> a{14, 5, 9, 17, 11, 28, 10, 2, 3, 19, 7};
	// cout << int(a.end() - a.begin()) << endl;
	// swap(*(a.begin()), *(a.end() - 1));
	// cout << *(a.begin()) << " " << *(a.end() - 1) << endl;
	cout << "comp(1, 2): " << std::less<int>()(1,2) << endl;
	heap_algorithm::make_heap(a.begin(), a.end(), std::less<int>());
	for (auto i = a.begin(); i != a.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	// pq test
	PriorityQueue<int> pq;
	pq.push(8);
	pq.push(3);
	pq.push(1);
	pq.push(5);
	pq.push(6);
	pq.push(0);
	pq.push(7);
	pq.push(4);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	
	
	return 0;
}
