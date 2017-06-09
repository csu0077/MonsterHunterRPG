#include <iostream>
#include <string>
#include "Monster.h"
#include "Sharpshooter.h"
#include "swordmaster.h"
#include "Monk.h"

using namespace std;

void printStats(Monster m)
{
	cout << "name:" << m.getName() << endl <<
		"HP:" << m.getHP() << endl <<
		"MP:" << m.getMP() << endl <<
		"Atk:" << m.getAtk() << endl <<
		"Def:" << m.getDef() << endl <<
		"Mag:" << m.getMag() << endl <<
		"Mdef:" << m.getMDef() << endl << endl;
}

void testCode()
{
	//testing Monster class Monster(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	Swordmaster sm("swordmaster",   100, 100, 10, 0, 10, 10);
	Sharpshooter ss("sharpshooter", 100, 100, 10, 2, 10, 10);
	//Monk m("monk", 100, 100, 10, 10, 10, 10);

	printStats(sm);
	printStats(ss);
	//printStats(m);

	cout << sm.getName() << " attacks " << ss.getName() << endl << endl;
	sm.attack(ss);
	printStats(ss);

	//testing Item class
}

int main()
{
	testCode();
	string doo;
	cin >> doo;
}