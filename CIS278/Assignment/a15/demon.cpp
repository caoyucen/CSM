/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ demon.cpp
 
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "demon.h"

namespace cs_creature {
	
	
	Demon::Demon():Creature(10,10){}
	
	
	Demon::Demon(int newStrength, int newHitpoints) : Creature(newStrength, newHitpoints){}
	
	
	string Demon::getSpecies() const
	{
		return "Demon";
	}
	
	int Demon ::getDamage() const
	{
		int damage = Creature::getDamage();
		if (rand() % 4 == 0)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}
		return (damage);
	}
	
	
}
