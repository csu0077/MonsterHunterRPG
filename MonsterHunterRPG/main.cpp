#include <iostream>
#include <string>
#include <vector>
#include "Monster.h"
#include "Sharpshooter.h"
#include "swordmaster.h"
#include "Monk.h"
#include "Item.h"
#include "Potion.h"
#include "Tonic.h"

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

void printItem(Item i)
{
	cout << "item name: " << i.getName() << endl <<
		"tier:" << i.getTier() << endl <<
		"count:" << i.getCount() << endl << endl;
}

void printInventory(Human h)
{	
	cout << h.getName() << "'s inventory" << endl;
	for (int i = 0; i < h.getInventory().size(); i++)
	{
		cout << i << ":";
		printItem(h.getInventory()[i]);
	}
}

void printMenu()
{
	cout << "a. Attack" << endl;
	cout << "s. Skills" << endl;
	cout << "d. Defend" << endl;
	cout << "f. Item" << endl;
}

void battle(Monster you, Monster enemy )
{
	cout << "Initializing Combat..." << endl;
	bool battleEnd = false;
	int yourTurns = you.getPartySize() + 1;
	int enemyTurns = enemy.getPartySize() + 1;
	bool yourTurn = true; //true == your turn, false == enemy turn

	cout << "You: " << you.getName() << endl;
	you.printParty();
	cout << endl;
	cout << "Enemy: " << enemy.getName() << endl;
	enemy.printParty();
	cout << endl;
	
	while (!battleEnd)
	{
		if (yourTurn)
		{
			cout << "-----------------------------------------" << endl;
			cout << "Your Party's Turn" << endl;
			cout << "Remaining Turns: " << yourTurns << endl;
			cout << "-----------------------------------------" << endl;
			cout << you.getName() << "\t\t";

			for (int i = 0; i < you.getPartySize(); i++)
				cout << you.getPartyM(i).getName() << "\t\t";

			cout << endl;

			cout << "HP: " << you.getHP() << "\t\t";

			for (int i = 0; i < you.getPartySize(); i++)
				cout << "HP: " << you.getPartyM(i).getHP() << "\t\t";

			cout << endl;

			cout << "MP: " << you.getMP() << "\t\t";

			for (int i = 0; i < you.getPartySize(); i++)
				cout << "MP: " << you.getPartyM(i).getHP() << "\t\t";

			cout << endl;

			cout << you.getName() << "'s turn" << endl;

			string choice;
			printMenu();
			cout << ">>";
			cin >> choice;

		}
		else
		{
			cout << "-----------------------------------------" << endl;
			cout << "Enemy's Party Turn" << endl;
			cout << "Remaining Turns: " << enemyTurns << endl;
			cout << "-----------------------------------------" << endl;
		}
		
		battleEnd = true;
	}
	cout << "Battle Complete" << endl;
}

void testCode()
{
	//testing Monster class Monster(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	Swordmaster sm("swordmaster",   100, 100, 10, 0, 10, 10);
	Sharpshooter ss("sharpshooter", 100, 100, 10, 2, 10, 10);
	Monk m("monk", 100, 100, 10, 10, 10, 10);

	m.addPartyM(sm);

	/*printStats(sm);
	//printStats(ss);
	printStats(m);

	//cout << sm.getName() << " attacks " << ss.getName() << endl << endl;
	//sm.attack(ss);
	//printStats(ss);

	//cout << sm.getName() << " attacks with medium strength " << m.getName() << endl << endl;
	//sm.slash2(m);
	//printStats(m);

	cout << sm.getName() << " attacks with high strength " << m.getName() << endl << endl;
	sm.slash3(m);
	printStats(m);

	//testing Item class
	//Item(int tier, int count, string name);
	Potion p(0, 1, "hamburger");	//0 is lowest tier

	cout << m.getName() << " puts a hamburger in his inventory..." << endl;
	m.addItem(p);
	//printInventory(m);

	cout << m.getName() << " puts a hamburger in his inventory..." << endl;
	m.addItem(p);
	//printInventory(m);

	cout << m.getName() << " eats a hamburger" << endl;
	m.useItem("hamburger");
	printInventory(m);
	printStats(m);
	/*m.printParty();
	cout << endl;
	m.addPartyM(ss);
	m.printParty();
	m.printPartySize();

	m.removePartyM(ss);
	m.printParty();
	m.printPartySize();

	m.addPartyM(ss);
	m.printParty();
	m.printPartySize();*/

	battle(m, ss);
}

int main()
{
	testCode();
	string doo;
	cin >> doo;

	return 0;
}