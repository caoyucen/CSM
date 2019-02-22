/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_  cyberdemon.cpp
 
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "cyberdemon.h"

namespace cs_creature {
	
	Cyberdemon::Cyberdemon():Demon(10,10){}
	
	
	Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) : Demon(newStrength, newHitpoints){}
	
	
	string Cyberdemon::getSpecies() const
	{
		return "Cyberdemon";
	}
	
	
}
