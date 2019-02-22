/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ cyberdemon.h
 
 */


#ifndef cyberdemon_h
#define cyberdemon_h


#include <iostream>
using namespace std;
#include "demon.h"

namespace cs_creature {
	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int newStrength, int newHitpoints);
		string getSpecies() const;
	};
}

#endif /* cyberdemon_h */
