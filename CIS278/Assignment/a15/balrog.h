/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_  balrog.h
 
 */



#ifndef balrog_h
#define balrog_h

#include <iostream>
using namespace std;
#include "demon.h"

namespace cs_creature {
	class Balrog : public Demon {
	public:
		Balrog();
		Balrog(int newStrength, int newHitpoints);
		string getSpecies() const;
		int getDamage() const;
	};
}

#endif /* balrog_h */
