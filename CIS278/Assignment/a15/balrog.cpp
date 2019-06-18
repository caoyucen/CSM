/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ balrog.cpp
 
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "balrog.h"

namespace cs_creature {
	
	Balrog::Balrog():Demon(10,10){}
	
	
	Balrog::Balrog(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints){}
	
	
	string Balrog::getSpecies() const
	{
		return "Balrog";
	}
	
	int Balrog ::getDamage() const
	{
		int damage;
		int damage2;
		// Balrogs are very fast, so they get to attack twice
		damage = Demon::getDamage();
		damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage = damage + damage2;
		return damage;
	}
	
}

