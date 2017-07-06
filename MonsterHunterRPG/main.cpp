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

bool stopBlocking = false;

void choice(Monster & you, Monster & enemy, int & yTurns, int & eTurns)
{
	bool choiceLoop = false;
	while (!choiceLoop)
	{
		string choice;
		printMenu();
		cout << ">>";
		cin >> choice;

		if (choice == "a")
		{
			bool targetChosen = false;

			while (!targetChosen)
			{
				cout << "choose target or cancel by pressing c" << endl;
				//choose who to attack
				cout << "1. " << enemy.getName() << endl;

				if (enemy.getPartySize() > 0)
				{
					for (int i = 0; i < enemy.getPartySize(); i++)
					{
						cout << i + 2 << ". " << enemy.getPartyM(i).getName() << endl;
					}
				}

				//test edge cases
				string target;
				int rightChoices = 1 + enemy.getPartySize();
				cout << ">>";
				cin >> target;

				if (target != "1" && target != "2" && target != "3" && target != "4" && target != "c")
					cout << "Invalid input" << endl;
				else if (target == "4" && enemy.getPartySize() < 3)
					cout << "Invalid input" << endl;
				else if (target == "3" && enemy.getPartySize() < 2)
					cout << "Invalid input" << endl;
				else if (target == "2" && enemy.getPartySize() < 1)
					cout << "Invalid input" << endl;
				else
				{
				//todo: do damage to target
					int tgt = 5;	//5 is the leader

					if (target == "2")
						tgt = 0;
					else if (target == "3")
						tgt = 1;
					else if (target == "4")
						tgt = 2;

					if (tgt != 5)
					{
						Monster temp = enemy.getPartyM(tgt);
						you.attack(temp);
						int modHP = temp.getHP();

						enemy.setPartyMHP(tgt, modHP);
						cout << you.getName() << " attacks " << enemy.getPartyM(tgt).getName() << endl;
						targetChosen = true;
					}
					else
					{
						you.attack(enemy);
						cout << you.getName() << " attacks " << enemy.getName() << endl;
						cout << enemy.getName() << "'s HP: " << enemy.getHP() << endl;
						targetChosen = true;
					}
				}
			}

			choiceLoop = true;
			yTurns--;

			cout << "-----------------------------------------" << endl;
			cout << "Remaining Turns: " << yTurns << endl;
			cout << "-----------------------------------------" << endl;
		}
		else if (choice == "s")	//skills
		{
			choiceLoop = true;
		}
		else if (choice == "d")	//defend
		{
			if (yTurns <= (you.getPartySize() + 1) * 2 && !stopBlocking)
			{
				yTurns++;
				cout << "-----------------------------------------" << endl;
				cout << "Remaining Turns: " << yTurns << endl;
				cout << "-----------------------------------------" << endl;
			}
			
			else
			{
				stopBlocking = true;
				yTurns--;
				cout << "-----------------------------------------" << endl;
				cout << "Remaining Turns: " << yTurns << endl;
				cout << "-----------------------------------------" << endl;
			}
			choiceLoop = true;
		}
		else if (choice == "f")	//item
		{
			choiceLoop = true;
		}
		else
		{
			cout << "Invalid input" << endl;
		}
	}
}

void turnLoop(Monster & you, Monster & enemy, int & yTurns, int & eTurns)
{
	while (yTurns)
	{
		cout << "-----------------------------------------" << endl;
		cout << you.getName() << "'s Party Turn" << endl;
		cout << "Remaining Turns: " << yTurns << endl;
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
			cout << "MP: " << you.getPartyM(i).getMP() << "\t\t";

		cout << endl;

		cout << you.getName() << "'s turn" << endl;

		choice(you, enemy, yTurns, eTurns);


		if (you.getPartySize() >= 1)
		{
			cout << you.getPartyM(0).getName() << "'s turn" << endl;
			choice(you.getPartyM(0), enemy, yTurns, eTurns);

			if (you.getPartySize() >= 2)
			{
				cout << you.getPartyM(1).getName() << "'s turn" << endl;
				choice(you.getPartyM(1), enemy, yTurns, eTurns);

				if (you.getPartySize() >= 3)
				{
					cout << you.getPartyM(2).getName() << "'s turn" << endl;
					choice(you.getPartyM(2), enemy, yTurns, eTurns);

				}
			}
		}

		eTurns = enemy.getPartySize() + 1;
	}
}

void battle(Monster you, Monster enemy)
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
			turnLoop(you, enemy, yourTurns, enemyTurns);
			yourTurn = false;
		}
		else
		{
			cout << "-----------------------------------------" << endl;
			cout << "Enemy's Party Turn" << endl;
			cout << "Remaining Turns: " << enemyTurns << endl;
			cout << "-----------------------------------------" << endl;

			while (enemyTurns)
			{
				enemyTurns--;
				stopBlocking = false;
			}

			yourTurn = true;
			yourTurns = you.getPartySize() + 1;
		}
		
		//battleEnd = true;
	}
	cout << "Battle Complete" << endl;
}

void testCode()
{
	//testing Monster class Monster(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	Swordmaster sm("swordmaster",   100, 100, 10, 0, 10, 10);
	Sharpshooter ss("sharpshooter", 100, 100, 10, 2, 10, 10);
	Monk m("monk", 100, 100, 10, 10, 10, 10);
	Monster rathalos("Rathalos", 5000, 500, 500, 250, 250, 250, "Flying Wyvern");
	m.addPartyM(sm);
	rathalos.addPartyM(ss);
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
	//cout << "Rathalos MP: " << rathalos.getMP() << endl;
	battle(m, rathalos);
}

int main()
{
	testCode();
	string doo;
	cin >> doo;

	return 0;
}