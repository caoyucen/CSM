/*
 
 YUCEN CAO
 11/28/2018
 CIS 278
 Instructor: Dave Harden
 Assignment 15_ a15.cpp
 
 */

#include <iostream>
#include <cstring>
#include <ctime> 
#include <cstdlib>
using namespace std;
#include "creature.h"
#include "human.h"
#include "elf.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "demon.h"

using namespace cs_creature;
using namespace std;



void battleArena(Creature &Creature1, Creature& Creature2)
{
	while (true)
	{
		int db1; //damage by Creature1
		int db2; //damage by Creature2
		
		db1 = Creature1.getDamage();
		db2 = Creature2.getDamage();
		Creature1.setHitpoint(Creature1.getHitpoints() - db2);
		Creature2.setHitpoint(Creature2.getHitpoints() - db1);
		
		if (Creature1.getHitpoints() <= 0 || Creature2.getHitpoints() <= 0)
		{
			if (Creature1.getHitpoints() <= 0 && Creature2.getHitpoints() <= 0)
			{
				cout << "Tie" << endl;
			}
			else if (Creature1.getHitpoints() <= 0)
			{
				cout << "The " << Creature2.getSpecies() << " won." << endl;
			}
			else
			{
				cout << "The " << Creature1.getSpecies() << " won." << endl;
			}
			break;
		}
	}
	
}


int main()
{
	srand(static_cast<unsigned>(time(0)));
	
	//Elf and Balrog
	cout << "Elf & Balrog:" << endl;
	Elf e(50,50);
	Balrog b(50,50);
	battleArena(e, b);
	cout << endl;
	
	
	//Human and Cyberdemon
	cout << "Human & Cyberdemon:" << endl; 
	Human h(50,50);
	Cyberdemon c(50,50);
	battleArena(h, c);
	cout << endl;
	
	//Elf and Cyberdemon
	cout << "Elf & Cyberdemon:" << endl;
	Elf e2(50, 50);
	Cyberdemon c2(50,50);
	battleArena(e2, c2);
	cout << endl;
	
	//Human and Balrog
	cout << "Human & Balrog:" << endl;
	Human h2(50,50);
	Balrog b2(50,50);
	battleArena(h2, b2);
	cout << endl;
	
	//Elf and Human
	cout << "Elf & Human:" << endl;
	Elf e3(50,50);
	Human h3(50,50);
	battleArena(e3, h3);
	cout << endl;
	
	//Balrog and Cyberdemon
	cout << "Balrog & Cyberdemon:" << endl;
	Balrog b3(50, 50);
	Cyberdemon c3(50,50);
	battleArena(b3, c3);
	cout << endl;
}




/*
 Elf & Balrog:
 The Elf attacks for 29 points!
 Magical attack inflicts 29 additional damage points!
 The Balrog attacks for 47 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 27 additional damage points!
 Tie
 
 Human & Cyberdemon:
 The Human attacks for 17 points!
 The Cyberdemon attacks for 50 points!
 The Cyberdemon won.
 
 Elf & Cyberdemon:
 The Elf attacks for 22 points!
 The Cyberdemon attacks for 37 points!
 The Elf attacks for 2 points!
 The Cyberdemon attacks for 50 points!
 The Cyberdemon won.
 
 Human & Balrog:
 The Human attacks for 41 points!
 The Balrog attacks for 10 points!
 Demonic attack inflicts 50 additional damage points!
 Balrog speed attack inflicts 34 additional damage points!
 The Balrog won.
 
 Elf & Human:
 The Elf attacks for 20 points!
 Magical attack inflicts 20 additional damage points!
 The Human attacks for 8 points!
 The Elf attacks for 39 points!
 The Human attacks for 48 points!
 Tie
 
 Balrog & Cyberdemon:
 The Balrog attacks for 50 points!
 Balrog speed attack inflicts 24 additional damage points!
 The Cyberdemon attacks for 13 points!
 The Balrog won.
 
 */
