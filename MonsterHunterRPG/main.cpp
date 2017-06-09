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

void printRes(Monster m)
{
	cout << "printing " << m.getName() << "'s resistances..." << endl;
	cout << "slash: " << m.getRes()[0] << endl;
	cout << "impact: " << m.getRes()[1] << endl;
	cout << "shot: " << m.getRes()[2] << endl;
	cout << "fire: " << m.getRes()[3] << endl;
	cout << "water: " << m.getRes()[4] << endl;
	cout << "thunder: " << m.getRes()[5] << endl;
	cout << "ice: " << m.getRes()[6] << endl;
	cout << "dragon: " << m.getRes()[7] << endl;

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
	printRes(ss);

	//testing Item class
}

int main()
{
	testCode();
	string doo;
	cin >> doo;
	//for (int i = 0; i < 2000000000; i++);
}