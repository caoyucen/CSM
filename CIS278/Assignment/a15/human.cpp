/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ human.cpp
 
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "human.h"

namespace cs_creature {
	
	Human::Human():Creature(10,10){}
	
	
	Human::Human(int newStrength, int newHitpoints):Creature(newStrength,newHitpoints){}
	
	
	string Human::getSpecies() const
	{
		return "Human";
	}
	
}
