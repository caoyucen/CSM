/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ demon.h
 
 */




#ifndef demon_h
#define demon_h


#include "creature.h"

namespace cs_creature {
	class Demon : public Creature{
	public:
		Demon();
		Demon(int newStrength, int newHitpoints);
		string getSpecies() const;
		int getDamage() const;
	
	};
}

#endif /* demons_h */
