 //
//  creature.cpp
//  a15
//
//  Created by baobao on 2018/11/26.
//  Copyright © 2018年 YUCEN CAO. All rights reserved.
//

#include <iostream>
#include "creature.h"
using namespace std;

namespace cs_creatures {
	string Human::getSpecies() const {
		return "Human";
	}
	
	string Cyberdemon::getSpecies() const {
		return "Cyberdemon";
	}
	
	string Balrog::getSpecies() const {
		return "Balrog";
	}
	
	string Elf::getSpecies() const {
		return "Elf";
	}
	
	Creature::Creature(int newStrength, int newHitpoints)
	:strength(newStrength), hitpoints(newHitpoints) {
	}
	
	int Creature::getDamage() const {
		int damage;
		
		// All Creatures inflict damage which is a random number up to their strength
		damage = (rand() % strength) + 1;
		cout << getSpecies() << " attacks for " << damage << " points!" << endl;
		
		// Specific creature type inflict their own dman
		/*
		 With a 50% chance elves inflict a magical attack that doubles the normal amount of damage.
		 Balrogs are very fast, so they get to attack twice
		 */
		return damage;
	}
	
	int Creature::getStrength() const {
		return strength;
	}
	
	Demon::Demon(int newStrength, int newHitpoints) 
	:Creature(newStrength, newHitpoints) {
	}	
	
	int Demon::getDamage() const {
		int damage;
		
		// Demons have a 25% chance of inflicting a demonic attack which is an additional 50 damage points. Balrogs and Cyberdemons are Demons.
		damage = Creature::getDamage();
		if (rand() % 4 == 0) {
			damage += 0.5 * damage;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}
		return damage;
	}
	
	Cyberdemon::Cyberdemon(int newStrength, int newHitpoints)
	:Demon(newStrength, newHitpoints) {
	}
	
	Balrog::Balrog(int newStrength, int newHitpoints)
	:Demon(newStrength, newHitpoints) {
	}
	
	int Balrog::getDamage() const {
		int damage;
		int damage2;
		// Balrogs are very fast, so they get to attack twice
		damage = Demon::getDamage();
		damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage += damage2;
		return damage;
	}
	
	Elf::Elf(int newStrength, int newHitpoints)
	:Creature(newStrength, newHitpoints) {		
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
