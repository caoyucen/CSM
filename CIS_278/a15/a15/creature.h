//
//  creature.h
//  a15
//
//  Created by baobao on 2018/11/26.
//  Copyright © 2018年 YUCEN CAO. All rights reserved.
//

#ifndef creature_h
#define creature_h

# include<string>
using namespace std;

namespace cs_creatures {
	class Creature {
	private:
		int strength;           // how much damage this Creature inflicts
		int hitpoints;          // how much damage this Creature can sustain
		virtual string getSpecies() const = 0;    // returns the type of the species
	public:
		Creature();             // initialize to Human, 10 strength, 10 hitpoints
		Creature(int newStrength, int newHitpoints);
		virtual int getDamage() const;         // returns the amount of damage this Creature
		// inflicts in one round of combat
		
		// also include appropriate accessors and mutators  
		int getStrength() const; // Gets the strength of the creature
		void setStrength(const int newStrength); // Sets the strength of the creature
	};
	
	class Human: public Creature {
	private:
		string getSpecies() const; 
	};
	
	class Demon: public Creature {
	private:
		virtual string getSpecies() const = 0;
	public:
		Demon(int newStrength, int newHitpoints);
		virtual int getDamage() const;
	};
	
	class Cyberdemon: public Demon {
	private:
		string getSpecies() const; 
	public:
		Cyberdemon(int newStrength, int newHitpoints);
	};
	
	class Balrog: public Demon {
	private:
		string getSpecies() const;
	public:
		Balrog(int newStrength, int newHitpoints);
		int getDamage() const;
	};
	
	class Elf: public Creature {
	private:
		string getSpecies() const;
	public:
		Elf(int newStrength, int newHitpoints);
		int getDamage() const;
	};
	
}

#endif /* creature_h */
