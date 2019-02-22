/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ creature.h
 
 */



#ifndef creature_h
#define creature_h


#include <iostream>
#include <cstring>
#include <ctime> 
#include <cstdlib>
using namespace std;

namespace cs_creature {
	class Creature {
	private:
		int strength;           // how much damage this Creature inflicts
		int hitpoints;          // how much damage this Creature can sustain
		
	public:
		Creature();             // initialize to Human, 10 strength, 10 hitpoints
		Creature(int newStrength, int newHitpoints);
		
		virtual string getSpecies() const = 0;    // returns the type of the species
		
		virtual int getDamage() const ;         // returns the amount of damage this Creature
		// inflicts in one round of combat
		
		// also include appropriate accessors and mutators  
		int getStrength() const; // Gets the strength of the creature
		int getHitpoints() const;
		void setHitpoint(const int newHitpoints); // Sets the strength of the creature
	};
	
}
#endif /* creature_h */
