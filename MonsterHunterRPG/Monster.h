#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Item.h"

using namespace std;

enum Ailment
{
	FIREBLIGHT,
	WATERBLIGHT,
	ICEBLIGHT,
	THUNDERBLIGHT,
	DRAGONBLIGHT,
	BLASTBLIGHT,
	POISON,
	DEADLYPOISON,
	LETHALPOISON,
	KO,
	PARALYSIS,
	MUDSNOW,
	SLEEP,
	BLEED, 
	DEAD
};

class Monster
{
public:
	Monster();
	void setInitStats(string name, int hp, int mp, int atk, int def, int mag, int mdef, string role);
	Monster(string name);
	Monster(string name, int hp, int mp, int atk, int def, int mag, int mdef, string role);
	void printSkills();
	void printParty();
	int getHP();
	int getMP();
	int getAtk();
	int getDef();
	int getMag();
	int getMDef();
	vector <bool> getStatus();
	vector <int> getRes();
	int getMaxHP();
	int getMaxMP();
	int getMaxAtk();
	int getMaxDef();
	int getMaxMag();
	int getMaxMDef();
	string getName();
	string getRole();
	void setRole(string role);

	void setHP(int hp);
	void setMP(int mp);
	void setAtk(int atk);
	void setDef(int def);
	void setMag(int mag);
	void setMDef(int mDef);
	void setStatus(int status);
	void setRes(int res, int i);
	void setMaxHP(int hp);
	void setMaxMP(int mp);
	void setMaxAtk(int atk);
	void setMaxDef(int def);
	void setMaxMag(int mag);
	void setMaxMDef(int mdef);
	void setName(string name);
	Monster & getPartyM(int i);
	void useItemLeader(Monster & m, string name);
	string getSkill(int i);
	void setPartyMHP(int i, int hp);
	void setPartyMMP(int i, int mp);
	void setPartyMAtk(int i, int atk);
	void setPartyMDef(int i, int def); //defence not regular magic defence
	void setPartyMMDef(int i, int mDef);
	//maybe add setting max stuff for party members as well
	void addPartyM(Monster & m);
	void removePartyM(Monster & m);
	int getPartySize();
	void printPartySize();
	void operator = (const Monster & m);
	void attack(Monster & m);
	void skill(Monster & m, int i, int & turns);
	void addSkill(string s);
	void removeSkill(int i);
	int getSkillSetSize();

	int getLevel();
	void setLevel(int level);
	int getExp();
	void setExp(int exp);
	void setPartyExp(int m, int exp);
	void levelUP();
	void levelUpPartyM(int i);
	void setStats(int hp, int mp, int atk, int def, int mag, int mdef);
	void resetStats();	//remove buffs, debuffs, and status ailments
	void resetPartyMStats(int i);
	void setPartyStatus(int i, int status, int state);
	Item getItem(int i);	//returns item at index i
	void addItem(Item item); //not increment but just add to the inventory
	void removeItem(int i); //removes item from invetory
	void useItem(string name);
	void useItemParty(int member, string name);
	vector <Item> getInventory();

	//1= weak, 2 = medium, 3 = strong
	void slash1(Monster & mon, int & turns); //weak slash damage
	void slash2(Monster & mon, int & turns); //medium slash damage
	void slash3(Monster & mon, int & turns); //strong slash damage

	void impact1(Monster & mon, int & turns); //weak impact damage
	void impact2(Monster & mon, int & turns); //medium impact damage
	void impact3(Monster & mon, int & turns); //strong impact damage

	void shot1(Monster & mon, int & turns);
	void shot2(Monster & mon, int & turns);
	void shot3(Monster & mon, int & turns);

	void fire1(Monster & mon, int & turns);
	void fire2(Monster & mon, int & turns);
	void fire3(Monster & mon, int & turns);

	void ice1(Monster & mon, int & turns);
	void ice2(Monster & mon, int & turns);
	void ice3(Monster & mon, int & turns);

	void water1(Monster & mon, int & turns);
	void water2(Monster & mon, int & turns);
	void water3(Monster & mon, int & turns);

	void thunder1(Monster & mon, int & turns);
	void thunder2(Monster & mon, int & turns);
	void thunder3(Monster & mon, int & turns);

	void dragon1(Monster & mon, int & turns);
	void dragon2(Monster & mon, int & turns);
	void dragon3(Monster & mon, int & turns);

	~Monster();

private:
	string name;
	int HP;
	int maxHP;
	int MP; //magic points
	int maxMP;
	int atk; //attack
	int maxAtk;
	int def; //defence
	int maxDef;
	int mag; //magic
	int maxMag;
	int mDef; //magic defence
	int maxMDef;
	int level;
	int exp;	//100 and up is a level up

	vector<bool> status = vector<bool>(15); //status effect array
	vector<int> statusCounter = vector<int>(15);
	vector <int> resistances = vector<int>(8); //resistances array i.e. whether or not weak to ice/ resist to fire
	vector <Monster> party;
	int partySize;
	string role;
	vector <string> skills;
	vector <Item> inventory = vector <Item>(10);

	void damageCalc(Monster & mon, int type, int power, int & turns)	//type is type of damage i.e. slash damage, power is how strong the attack will be i.e. weak/medium/strong
	{
		double attackPow = double(getAtk());
		switch (power)
		{
		case 1:
			attackPow *= 1.25;
			break;
		case 2:
			attackPow *= 1.5;
			break;
		default:
			attackPow *= 1;
			break;
		}

		double damage =  attackPow - mon.getDef();

		cout << "attacker's attack: " << attackPow << endl;
		cout << "defender's defence: " << mon.getDef() << endl;

		if (type != 100)
		{
			if (mon.getRes()[type] == 2)		//if the bool is true at index, that is the weakness
			{
				turns += 1;
				damage *= 2;
				cout << mon.getName() << "'s weakness was hit!!!" << endl;
			}
				
			else if (!mon.getRes()[type])
				damage = 0;
		}
		
		if (damage <= 0)
			damage = 0;					//no damage if negative value*/

		cout << "calculated damage: " << damage << endl << endl;
		mon.setHP(mon.getHP() - int(damage));
		cout << "Remaining HP: " << mon.getHP() << endl << endl;

		if (mon.getHP() <= 0)
		{
			cout << mon.getName() << " is dead!" << endl;
			mon.setStatus(DEAD);
		}
	}


	void counter(int ailment)
	{
		if (!statusCounter[ailment])	//counter is zero, meaning no blight yet
			statusCounter[ailment] = 3;
		else
		{
			statusCounter[ailment]--;

			if (!statusCounter[ailment])
				setStatus(ailment);
		}
	}

	void ailmentCounter(int ailment)
	{
		double damage = 0.0;

		switch (ailment)
		{
		case FIREBLIGHT:
			counter(FIREBLIGHT);
			break;
		case WATERBLIGHT:
			counter(WATERBLIGHT);
			//todo implement turn system before hand
			break;
		case THUNDERBLIGHT:
			counter(THUNDERBLIGHT);
			//todo: add status vulerability chance
			break;
		case ICEBLIGHT:
			counter(ICEBLIGHT);
			//todo implement turn system before hand
			break;
		case DRAGONBLIGHT:
			counter(DRAGONBLIGHT);
			break;
		case BLASTBLIGHT:
			counter(BLASTBLIGHT);
			break;
		case POISON:
			counter(POISON);
			damage = 0.05 * double(getMaxHP()); 
			setHP(getHP() - int(damage));
			break;
		case DEADLYPOISON:
			counter(DEADLYPOISON);
			damage = 0.1 * double(getMaxHP());
			setHP(getHP() - int(damage));
			break;
		case LETHALPOISON:
			counter(LETHALPOISON);
			damage = 0.15 * double(getMaxHP());
			setHP(getHP() - int(damage));
			break;
		case KO:
			counter(KO);
			break;
		case PARALYSIS:
			counter(PARALYSIS);
			break;
		case MUDSNOW:
			counter(MUDSNOW);
			break;
		case SLEEP:
			counter(SLEEP);
			break;
		case BLEED:
			counter(BLEED);
			break;
		default:
			break;
		}
	}

};

