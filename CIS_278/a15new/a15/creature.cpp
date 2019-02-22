/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_  creature.cpp
 
 */


#include "creature.h"

namespace cs_creature {
	Creature::Creature()
	{
		strength = 10;
		hitpoints = 10;
	}
	
	Creature::Creature(int newStrength, int newHitpoints)
	{
		strength = newStrength;
		hitpoints = newHitpoints;
	}
	
	int Creature::getDamage() const 
	{
		int damage;
		
		// All Creatures inflict damage which is a random number up to their strength
		damage = (rand() % strength) + 1;
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		
		// Specific creature type inflict their own dman
		/*
		 With a 50% chance elves inflict a magical attack that doubles the normal amount of damage.
		 Balrogs are very fast, so they get to attack twice
		 */
		return damage;
	}
	
	
	int Creature::getStrength() const
	{
		return strength;
	}
	
	int Creature::getHitpoints() const
	{
		return hitpoints;
	}
	void Creature::setHitpoint(const int newHitpoints)
	{
		hitpoints = newHitpoints;
	}
}
