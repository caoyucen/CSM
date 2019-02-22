/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_  elf.cpp
 
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "elf.h"

namespace cs_creature {
	
	Elf::Elf():Creature(10,10){}
	
	
	Elf::Elf(int newStrength, int newHitpoints):Creature(newStrength,newHitpoints){}
	
	
	string Elf::getSpecies() const
	{
		return "Elf";
	}
	
	
	int Elf::getDamage() const {
		int damage;
		damage = Creature::getDamage();
		// With a 50% chance elves inflict a magical attack that doubles the normal amount of damage.
		if (rand() % 2 == 0) {
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage *= 2;
		}
		return damage;
	}

}
