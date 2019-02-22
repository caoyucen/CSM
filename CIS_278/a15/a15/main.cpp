//
//  main.cpp
//  a15
//
//  Created by baobao on 2018/11/26.
//  Copyright © 2018年 YUCEN CAO. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
using namespace cs_creatures;
using namespace std;

void battleArena(Creature& a, Creature& b) {
	
}

int main() {
	srand(static_cast<unsigned>(time(0)));
	Elf e(50, 50);
	Balrog b(50, 50);
	
	battleArena(e, b);
	return 0;
}

