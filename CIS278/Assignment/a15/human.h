/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ human.h
 
 */




#ifndef human_h
#define human_h

#include "creature.h"

namespace cs_creature {
	class Human : public Creature{
	public:
		Human();
		Human(int newStrength, int newHitpoints);
		string getSpecies() const;
		
	};
}


#endif /* human_h */
