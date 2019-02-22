/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_  elf.h
 
 */



#ifndef elf_h
#define elf_h


#include "creature.h"

namespace cs_creature {
	class Elf : public Creature{
	public:
		Elf();
		Elf(int newStrength, int newHitpoints);
		string getSpecies() const;
		int getDamage() const;
	};
}


#endif /* elf_h */
