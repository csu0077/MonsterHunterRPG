#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Monster.h"
#include "Sharpshooter.h"
#include "swordmaster.h"
#include "Monk.h"
#include "Item.h"
#include "Potion.h"
#include "Tonic.h"

using namespace std;

enum Ailments
{
	FB,
	WB,
	IB,
	TB,
	DB,
	BB,
	PSN,
	DPSN,
	LPSN,
	KNOCKOUT,
	PARA,
	MS,
	SLP,
	BLD,
	DED
};


int levelCheck(Monster & you, Monster & enemy)	//checks exp
{
	if (you.getLevel() <= enemy.getLevel() && enemy.getRole() != "Boss")
		return 10;
	else if (you.getLevel() <= enemy.getLevel() && enemy.getRole() == "Boss")
		return 100;
	else
		return 5;
}

void expCalc(Monster & you, Monster & enemy)
{
	int defExp = 10;
	
	vector <int> expVec = vector<int>(4);	//keeps then sets it all later

	expVec[0] += levelCheck(you, enemy);

	for (int i = 0; i < you.getPartySize(); i++)
		expVec[i+1] += levelCheck(you.getPartyM(i), enemy);

	for (int i = 0; i < enemy.getPartySize(); i++)
		expVec[0] += levelCheck(you, enemy.getPartyM(i));

	for (int i = 0; i < you.getPartySize(); i++)
		for (int j = 0; j < enemy.getPartySize(); j++)
		{
			expVec[i + 1] += levelCheck(you.getPartyM(i), enemy.getPartyM(j));
		}
			

	you.setExp(you.getExp() + expVec[0]);
	cout << you.getName() << " received " << expVec[0] << " exp" << endl;

	for (int i = 0; i < you.getPartySize(); i++)
	{
		you.setPartyExp(i, expVec[i + 1]);
		cout << you.getPartyM(i).getName() << " received " << expVec[i + 1] << " exp" << endl;
	}
		

	if (you.getExp() >= 100)
	{
		cout << you.getName() << " leveled up!" << endl;
		you.levelUP();//level up here
	}

	for (int i = 0; i < you.getPartySize(); i++)
	{
		if (you.getPartyM(i).getExp() >= 100)
		{
			cout << you.getPartyM(i).getName() << " leveled up!" << endl;
			you.levelUpPartyM(i);
		}
	}
}

void reset(Monster & m)	//reset party stats after every battle
{
	m.resetStats();

	for (int i = 0; i < m.getPartySize(); i++)
		m.resetPartyMStats(i);
}

void printStats(Monster & m)
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

void printInventory(Monster h)
{	
	cout << h.getName() << "'s inventory" << endl;
	for (unsigned int i = 0; i < h.getInventory().size(); i++)
	{
		

		if (h.getInventory()[i].getName() != "")
		{
			cout << i + 1 << ":";
			printItem(h.getInventory()[i]);
		}
			
	}
}

//checks if target for normal attacks is valid and then go throughs with damage calculations
bool checkValidTargetInput(Monster & you, Monster & enemy)
{
	bool targetChosen = false;

	while (!targetChosen)
	{
		cout << "choose target or cancel by pressing c" << endl;
		//choose who to attack

		if (enemy.getHP() > 0)
			cout << "1. " << enemy.getName() << endl;

		if (enemy.getPartySize() > 0)
		{
			for (int i = 0; i < enemy.getPartySize(); i++)
			{
				if(enemy.getPartyM(i).getHP() > 0)
					cout << i + 2 << ". " << enemy.getPartyM(i).getName() << endl;

			}
		}

		//test edge cases
		string target;
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
		else if (target == "1" && enemy.getHP() <= 0)
			cout << "Invalid input" << endl;
		else if (target == "2" && enemy.getPartyM(0).getHP() <= 0)
			cout << "Invalid input" << endl;
		else if (target == "3" && enemy.getPartyM(1).getHP() <= 0)
			cout << "Invalid input" << endl;
		else if (target == "4" && enemy.getPartyM(2).getHP() <= 0)
			cout << "Invalid input" << endl;
		else
		{
			int tgt = 5;	//5 is the leader

			if (target == "2")
				tgt = 0;
			else if (target == "3")
				tgt = 1;
			else if (target == "4")
				tgt = 2;
			else if (target == "c")
				return false;
			if (tgt != 5)
			{
				Monster temp = enemy.getPartyM(tgt);
				you.attack(temp);
				int modHP = temp.getHP();

				enemy.setPartyMHP(tgt, modHP);
				return true;
			}
			else
			{
				you.attack(enemy);
				cout << enemy.getName() << "'s HP: " << enemy.getHP() << endl;

				return true;
			}
		}
	}
	return false;
}

//checks if target for skills is valid and then go throughs with damage calculations
bool checkValidSkillTarget(Monster & you, Monster & enemy, string i)
{
	bool targetChosen = false;

	while (!targetChosen)
	{
		cout << "choose target or cancel by pressing c" << endl;
		//choose who to attack
		if (enemy.getHP() > 0)
			cout << "1. " << enemy.getName() << endl;

		if (enemy.getPartySize() > 0)
		{
			for (int i = 0; i < enemy.getPartySize(); i++)
			{
				if (enemy.getPartyM(i).getHP() > 0)
					cout << i + 2 << ". " << enemy.getPartyM(i).getName() << endl;
			}
		}

		//test edge cases
		string target;
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
		else if (target == "2" && enemy.getPartyM(0).getHP() <= 0)
			cout << "Invalid input" << endl;
		else if (target == "3" && enemy.getPartyM(1).getHP() <= 0)
			cout << "Invalid input" << endl;
		else if (target == "4" && enemy.getPartyM(2).getHP() <= 0)
			cout << "Invalid input" << endl;
		else
		{
			
			int tgt = 5;	//5 is the leader

			if (target == "2")
				tgt = 0;
			else if (target == "3")
				tgt = 1;
			else if (target == "4")
				tgt = 2;
			else if (target == "c")
				return false;

			int skill = stoi(i);

			if (tgt != 5)
			{
				Monster temp = enemy.getPartyM(tgt);

				

				you.skill(temp, skill);
				int modHP = temp.getHP();

				enemy.setPartyMHP(tgt, modHP);
				return true;
			}
			else
			{
				you.skill(enemy, skill);
				/*cout << you.getName() << " attacks " << enemy.getName() << endl;
				cout << enemy.getName() << "'s HP: " << enemy.getHP() << endl;*/
				return true;
			}
		}
	}
}

//checks if target for item is valid and then go throughs with the calculations
bool checkValidItemTarget(Monster & you, string i, bool partyM, Monster & yLeader)
{

	bool targetChosen = false;

	while (!targetChosen)
	{
		cout << "choose target or cancel by pressing c" << endl;
		cout << "1." << you.getName() << endl;
		
		if (partyM)
			cout << "6." << yLeader.getName() << endl;

		for (int i = 0; i < you.getPartySize(); i++)
		{
			cout << i + 2 <<  "." << you.getPartyM(i).getName() << endl;
		}

		//test edge cases
		
		string target;
		cout << ">>";
		cin >> target;

		if (target != "1" && target != "2" && target != "3" && target != "4" && target != "6" && target != "c")
			cout << "Invalid input" << endl;
		else if (target == "4" && you.getPartySize() < 3)
			cout << "Invalid input" << endl;
		else if (target == "3" && you.getPartySize() < 2)
			cout << "Invalid input" << endl;
		else if (target == "2" && you.getPartySize() < 1)
			cout << "Invalid input" << endl;

		else
		{
			
			int tgt = 5;	//5 is the leader

			if (target == "2")
				tgt = 0;
			else if (target == "3")
				tgt = 1;
			else if (target == "4")
				tgt = 2;
			else if (target == "c")
				return false;
			else if (target == "6")
				tgt = 6;

			int item = stoi(i)-1;

			if (tgt != 5 && tgt != 6)
			{
				int tgt = stoi(target);
				
				cout << you.getName() << " uses " << you.getInventory()[item].getName() << " on " <<
					you.getPartyM(tgt-2).getName() << endl;

				you.useItemParty(tgt-2, you.getInventory()[item].getName());

				return true;
			}
			else if (tgt == 6)
			{
				cout << you.getName() << " uses " << you.getInventory()[item].getName() << " on " <<
					yLeader.getName() << endl;

				you.useItemLeader(yLeader, you.getInventory()[item].getName());
				return true;
			}
			else
			{
				int item = stoi(i) - 1;
				
				cout << you.getName() << " uses " << you.getInventory()[item].getName() << endl;
				you.useItem(you.getInventory()[item].getName());
				return true;
			}
		}
	}


	return true;
}

void printMenu()
{
	cout << "a. Attack" << endl;
	cout << "s. Skills" << endl;
	cout << "d. Defend" << endl;
	cout << "f. Item" << endl;
}

bool stopBlocking = false;

void choice(Monster & you, Monster & enemy, int & yTurns, int & eTurns, bool partyM, Monster & yLeader)
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
			if (checkValidTargetInput(you, enemy))
			{
				choiceLoop = true;
				yTurns--;
			}
			
		}
		else if (choice == "s")	//skills
		{
			cout << "Choose a skill or type c to cancel" << endl;
			you.printSkills();

			bool skillChoiceValid = false;
			string input;
			
			while (!skillChoiceValid)
			{
				cin >> input;
				if (input != "1" && input != "2" && input != "3" && input != "4"
					&& input != "5" && input != "6" && input != "7" && input != "8" && input != "c")
				{
					//make so nothing happens when picking an empty index
					cout << "Invalid input" << endl;
				}
				else
					skillChoiceValid = true;
			}

			if (input != "c")
			{
				if ((you.getSkill(stoi(input) - 1) == "slash1" ||
					you.getSkill(stoi(input) - 1) == "impact1" ||
					you.getSkill(stoi(input) - 1) == "shot1" ||
					you.getSkill(stoi(input) - 1) == "fire1" ||
					you.getSkill(stoi(input) - 1) == "ice1" ||
					you.getSkill(stoi(input) - 1) == "thunder1" ||
					you.getSkill(stoi(input) - 1) == "water1" ||
					you.getSkill(stoi(input) - 1) == "dragon1") && you.getMP() < 5)
				{
					cout << "Not enough MP!" << endl;
				}
				else if (input != "c" && checkValidSkillTarget(you, enemy, input))
				{
					choiceLoop = true;
					yTurns--;
				}
			}
		
		}
		else if (choice == "d")	//defend
		{
			if (yTurns <= (you.getPartySize() + 1) * 2 && !stopBlocking)
			{
				yTurns++;
			}

			else
			{
				stopBlocking = true;
				yTurns--;
			}
			choiceLoop = true;
		}
		else if (choice == "f")	//item
		{
			int checkEmptyInventory = 0;

			for (int i = 0; i < you.getInventory().size(); i++)
			{
				if (you.getInventory()[i].getName() == "")
				{
					checkEmptyInventory++;
				}
			}

			if (checkEmptyInventory == 10)
			{
				cout << "Nothing in your inventory!" << endl;
			}
			else
			{
				printInventory(you);
				cout << "Choose an item or type c to cancel" << endl;

				bool itemChoiceValid = false;
				string input;

				while (!itemChoiceValid)
				{
					cin >> input;
					if (input != "1" && input != "2" && input != "3" && input != "4"
						&& input != "5" && input != "6" && input != "7" && input != "8" &&  input != "9" && input != "c")
					{
						//make so nothing happens when picking an empty index
						cout << "Invalid input" << endl;
					}
					else
						itemChoiceValid = true;
				}

				cout << "your input: " << input << endl;
				if (input != "c" && checkValidItemTarget(you, input, partyM, yLeader))
				{
					choiceLoop = true;
					yTurns--;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
		}
	}
}

int checkDead(Monster y)	//returns number of dead party members
{
	int bodyCount = 0;
	
	if (y.getHP() <= 0)
		bodyCount++;

	for (int i = 0; i < y.getPartySize(); i++)
	{
		if (y.getPartyM(i).getHP() <= 0)
		{
			y.setPartyStatus(i, DED, 1);
			bodyCount++;
		}
	}
	return bodyCount;
}

void turnLoop(Monster & you, Monster & enemy, int & yTurns, int & eTurns)
{

	while (yTurns)
	{
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

		choice(you, enemy, yTurns, eTurns, false, you);

		cout << "-----------------------------------------" << endl;
		cout << "Remaining Turns: " << yTurns << endl;
		cout << "-----------------------------------------" << endl;

		if (checkDead(enemy) == 1 + enemy.getPartySize())
		{
			return;
		}
			
			

		if ( you.getPartySize() >= 1)
		{
			if (you.getPartyM(0).getHP() > 0)
			{
				cout << you.getPartyM(0).getName() << "'s turn" << endl;
				choice(you.getPartyM(0), enemy, yTurns, eTurns, true, you);

				if (checkDead(enemy) == 1 + enemy.getPartySize())
					return;

				cout << "-----------------------------------------" << endl;
				cout << "Remaining Turns: " << yTurns << endl;
				cout << "-----------------------------------------" << endl;
			}

			if (you.getPartySize() >= 2)
			{
				if (you.getPartyM(1).getHP() > 0)
				{
					cout << you.getPartyM(1).getName() << "'s turn" << endl;
					choice(you.getPartyM(1), enemy, yTurns, eTurns, true, you);

					if (checkDead(enemy) == 1 + enemy.getPartySize())
						return;

					cout << "-----------------------------------------" << endl;
					cout << "Remaining Turns: " << yTurns << endl;
					cout << "-----------------------------------------" << endl;
				}
				

				if (you.getPartySize() >= 3)
				{
					if (you.getPartyM(2).getHP() > 0)
					{
						cout << you.getPartyM(2).getName() << "'s turn" << endl;
						choice(you.getPartyM(2), enemy, yTurns, eTurns, true, you);

						if (checkDead(enemy) == 1 + enemy.getPartySize())
							return;

						cout << "-----------------------------------------" << endl;
						cout << "Remaining Turns: " << yTurns << endl;
						cout << "-----------------------------------------" << endl;
					}
				}
			}
		}
	}
}


void enemyTurn(Monster & you, Monster & enemy, int & yTurns, int & eTurns)
{
	if (enemy.getName() == "Ludroth" || enemy.getName() == "Jaggi")
	{
		cout << enemy.getName() << "'s turn" << endl;
		srand(time(NULL));
		int randPartyM = rand() % (you.getPartySize() + 1);

		if (randPartyM == 0 && you.getHP() <= 0)
		{
			if (you.getPartySize() == 1 && you.getPartyM(0).getHP() > 0)
				randPartyM = 1;
			else if (you.getPartySize() == 2 && you.getPartyM(1).getHP() > 0)
				randPartyM = 2;
			else if (you.getPartySize() == 3 && you.getPartyM(2).getHP() > 0)
				randPartyM = 3;
		}
		else if (randPartyM == 1 && you.getPartyM(0).getHP() <= 0)
		{
			if (you.getPartySize() == 1 && you.getHP() > 0)
				randPartyM = 0;
			else if (you.getPartySize() == 2 && you.getPartyM(1).getHP() > 0)
				randPartyM = 2;
			else if (you.getPartySize() == 3 && you.getPartyM(2).getHP() > 0)
				randPartyM = 3;
		}
		else if (randPartyM == 2 && you.getPartyM(1).getHP() <= 0)
		{
			if (you.getPartySize() == 1 && you.getHP() > 0)
				randPartyM = 0;
			else if (you.getPartySize() == 2 && you.getPartyM(0).getHP() > 0)
				randPartyM = 1;
			else if (you.getPartySize() == 3 && you.getPartyM(2).getHP() > 0)
				randPartyM = 3;
		}
		else if (randPartyM == 3 && you.getPartyM(2).getHP() <= 0)
		{
			if (you.getPartySize() == 1 && you.getHP() > 0)
				randPartyM = 0;
			else if (you.getPartySize() == 2 && you.getPartyM(0).getHP() > 0)
				randPartyM = 1;
			else if (you.getPartySize() == 3 && you.getPartyM(1).getHP() > 0)
				randPartyM = 2;
		}

		if (!randPartyM)
		{
			cout << enemy.getName() << " attacks " << you.getName() << endl;
			enemy.attack(you);
		}
		else
		{
			cout << enemy.getName() << " attacks " << you.getPartyM(randPartyM - 1).getName() << endl;
			enemy.attack(you.getPartyM(randPartyM - 1));
		}
	}
	eTurns--;
}

void battle(Monster you, Monster enemy)
{
	cout << "Initializing Combat..." << endl;
	bool battleEnd = false;
	int yourTurns = you.getPartySize() + 1;

	for (int i = 0; i < you.getPartySize(); i++)
	{
		if (you.getPartyM(i).getHP() <= 0)
		{
			yourTurns--;
		}
	}

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
			cout << you.getName() << "'s Party Turn" << endl;
			cout << "-----------------------------------------" << endl;

			turnLoop(you, enemy, yourTurns, enemyTurns);
			yourTurn = false;

			cout << "enemies dead: " << checkDead(enemy) << endl;
			if (checkDead(enemy) == 1 + enemy.getPartySize())
			{
				battleEnd = true;
				expCalc(you, enemy);
			}

			enemyTurns = enemy.getPartySize() + 1 - checkDead(enemy);

		}
		else
		{
			cout << "-----------------------------------------" << endl;
			cout << "Enemy's Party Turn" << endl;
			cout << "Remaining Turns: " << enemyTurns << endl;
			cout << "-----------------------------------------" << endl;

			while (enemyTurns > 0)
			{
				if (enemy.getHP() > 0)	//jaggi/ludroth script
				{
					enemyTurn(you, enemy, yourTurns, enemyTurns);
				}

				if (enemy.getPartySize() >= 1)
				{
					if (enemy.getPartyM(0).getHP() > 0)
						enemyTurn(you, enemy.getPartyM(0), yourTurns, enemyTurns);
				}

				if (enemy.getPartySize() >= 2)
				{
					if (enemy.getPartyM(1).getHP() > 0)
						enemyTurn(you, enemy.getPartyM(1), yourTurns, enemyTurns);
				}

				if (enemy.getPartySize() == 3)
				{
					if (enemy.getPartyM(2).getHP() > 0)
						enemyTurn(you, enemy.getPartyM(2), yourTurns, enemyTurns);
				}

				stopBlocking = false;
				yourTurn = true;
				yourTurns = you.getPartySize() + 1 - checkDead(you);

				if (checkDead(you) == 1 + you.getPartySize())
				{
					cout << you.getName() << ": wow we suck...." << endl;
					battleEnd = true;
				}
					
			}
		}
	}

	cout << "Battle Complete" << endl;

	//reset(you);
}

void testCode()
{
	
	Swordmaster sm("Lyn");
	Sharpshooter john("John");
	Monk m("Wallace");

	
	Monster jaggi("Jaggi");
	Monster luddy("Ludroth");
	jaggi.addPartyM(luddy);
	
	m.setHP(m.getHP() - 10);
	Item hamburger(0, 1, "hamburger");
	sm.addItem(hamburger);
	
	m.addPartyM(sm);
	//printInventory(m);
	//m.useItem("hamburger");
	//cout << m.getHP() << endl;

	battle(m, jaggi);
	//todo
	//give exp at end of battle	(done)
	//add leveling up (done)
	//add a cancel for choosing skills (done)
	//add death status when reach 0 hp and remove turn from respective player (done)
	//do items (mostly done)
	//fix item class (mostly done)
	//test for bad inputs (progressing)
	//debug and test leveling up
	//add mage class (done)
	//add leveling up for monsters like what stats they level up (mostly done)
	//fix it so dead targets cannot be selected (done)
}

int main()
{
	testCode();
	string doo;
	cin >> doo;

	return 0;
}