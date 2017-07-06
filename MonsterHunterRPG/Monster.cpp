#include "Monster.h"

enum Element
{
	SLASH,
	IMPACT,
	SHOT,
	FIRE,
	ICE,
	WATER,
	THUNDER,
	DRAGON
};

enum Pwr
{
	WEAK,
	MEDIUM,
	STRONG
};

Monster::Monster()
	:name("doofus"),HP(1),MP(1),atk(1),def(1),mag(1), mDef(1), role("nothing")
{
	maxHP = HP;
	maxMP = MP;
	maxAtk = atk;
	maxDef = def;
	maxMag = mag;
	maxMDef = mDef;
	//party.push_back(*this);
	//partySize++;
}

Monster::Monster(string name, int hp, int mp, int atk, int def, int mag, int mdef, string role)
	:HP(hp),MP(mp),atk(atk),def(def),mag(mag)
{
	this->name = name;
	this->role = role;
	maxHP = HP;
	maxMP = MP;
	maxAtk = atk;
	maxDef = def;
	maxMag = mag;
	maxMDef = mDef;
	//party.push_back(*this);
	//partySize++;
}

void Monster::printParty()
{
	cout << "Party" << endl;
	for (int i = 0; i < party.size(); i++)
	{
		if(party[i].getName() != "doofus")
			cout << party[i].getName() << endl;
	}
}

void Monster::setHP(int hp)
{
	this->HP = hp;
}

int Monster::getHP()
{
	return this->HP;
}

void Monster::setMP(int mp)
{
	this->MP = mp;
}

int Monster::getMP()
{
	return this->MP;
}

int Monster::getAtk()
{
	return this->atk;
}

void Monster::setAtk(int atk)
{
	this->atk = atk;
}

int Monster::getDef()
{
	return this->def;
}

void Monster::setDef(int def)
{
	this->def = def;
}

int Monster::getMag()
{
	return this->mag;
}

void Monster::setMag(int mag)
{
	this->mag = mag;
}

int Monster::getMDef()
{
	return this->mDef;
}

void Monster::setMDef(int mDef)
{
	this->mDef = mDef;
}

vector<bool> Monster::getStatus()
{
	return status;
}

void Monster::setStatus(int ailment)
{
	this->status[ailment] = !this->status[ailment];  //pretty much just flip the bool
}

vector<int> Monster::getRes()
{
	return this->resistances;
}

void Monster::setRes(int res, int i)	//i represents whenever or not the unit is weak to said element i.e. 0 = no damage, 1 = neutral, 2 = weakness
{
	this->resistances[res] = i;  //pretty much just flip the bool
}

int Monster::getMaxHP()
{
	return this->maxHP;
}

int Monster::getMaxMP()
{
	return maxMP;
}

int Monster::getMaxAtk()
{
	return maxAtk;
}

int Monster::getMaxDef()
{
	return maxDef;
}

int Monster::getMaxMag()
{
	return maxMag;
}

int Monster::getMaxMDef()
{
	return maxMDef;
}

string Monster::getName()
{
	return this->name;
}

string Monster::getRole()
{
	return this->role;
}

void Monster::setRole(string role)
{
	this->role = role;
}

void Monster::setMaxHP(int hp)
{
	this->maxHP = hp;
}

void Monster::setMaxMP(int mp)
{
	this->maxMP = mp;
}

void Monster::setMaxAtk(int atk)
{
	this->maxAtk = atk;
}

void Monster::setMaxDef(int def)
{
	this->maxDef = def;
}

void Monster::setMaxMag(int mag)
{
	this->maxMag = mag;
}

void Monster::setMaxMDef(int mdef)
{
	this->maxMDef = mdef;
}

void Monster::setName(string name)
{
	this->name = name;
}

Monster Monster::getPartyM(int i)
{
	return party[i];
}

void Monster::setPartyMHP(int i, int hp)
{
	party[i].setHP(hp);
}

void Monster::setPartyMMP(int i, int mp)
{
	party[i].setMP(mp);
}

void Monster::setPartyMAtk(int i, int atk)
{
	party[i].setAtk(atk);
}

void Monster::setPartyMDef(int i, int def)
{
	party[i].setDef(def);
}

void Monster::setPartyMMDef(int i, int mDef)
{
	party[i].setMDef(mDef);
}

void Monster::addPartyM(Monster & m)
{
	//todo do something about empty spots

	for (int i = 0; i < party.size(); i++)
	{
		if (party[i].getName() == "doofus")
		{
			party[i] = m;
			partySize++;
			cout << getName() << " added " << m.getName() << " to the party" << endl;
			return;
		}
	}

	if (partySize != 3 && party.size() != 3)
	{
		party.push_back(m);
		partySize++;
		cout << getName() << " added " << m.getName() << " to the party" << endl;
		return;
	}

	else if (partySize == 3)
	{
		cout << "party is full" << endl;
		return;
	}	
}


void Monster::removePartyM(Monster & m)
{
	for (int i = 0; i < party.size(); i++)
	{
		if (party[i].getName() == m.getName())
		{
			Monster temp = party[party.size() - 1];
			party[i] = temp;
			party.pop_back();
			partySize--;
		}
	}
}

int Monster::getPartySize()
{
	return partySize;
}

void Monster::printPartySize()
{
	cout << "Party Size: " << partySize << endl;
	cout << "Party Vector Size: " << party.size() << endl;
}

void Monster::operator=(const Monster & m)
{
	this->name = m.name;
	this->HP = m.HP;
	this->MP = m.MP;
	this->atk = m.atk;
	this->def = m.def;
	this->mag = m.mag;
	this->mDef = m.mDef;

	this->maxHP = m.maxHP;
	this->maxMP = m.maxMP;
	this->maxAtk = m.maxAtk;
	this->maxDef = m.maxDef;
	this->maxMag = m.maxMag;
	this->maxMDef = m.maxMDef;

}

void Monster::attack(Monster & m)
{
	damageCalc(m, 100, WEAK); //100 is non elemental damage
}

void Monster::skill(Monster & m)
{

}

void Monster::addSkill(string s)
{
	skills.push_back(s);
}

void Monster::removeSkill(string s)
{
	for (int i = 0; i < skills.size(); i++)
	{
		if (s == skills[i])
		{
			string temp = skills[skills.size() - 1];
			skills[i] = temp;
			skills.pop_back();
			return;
		}
	}

	cout << "No such skill" << endl;
}

void Monster::slash1(Monster & mon) //weak slash damage
{
	cout << "slash 1" << endl;
	damageCalc(mon, SLASH, WEAK); //in the monster.h file
}

void Monster::slash2(Monster & mon) //medium slash damage
{
	cout << "slash 2" << endl;
	damageCalc(mon, SLASH, MEDIUM);
}

void Monster::slash3(Monster & mon) //strong slash damage
{
	cout << "slash 3" << endl;
	damageCalc(mon, SLASH, STRONG);
}

void Monster::impact1(Monster & mon) 
{
	cout << "impact 1" << endl;
	damageCalc(mon, IMPACT, WEAK);
}

void Monster::impact2(Monster & mon)
{
	cout << "impact 2" << endl;
	damageCalc(mon, IMPACT, MEDIUM);
}

void Monster::impact3(Monster & mon)
{
	cout << "impact 3" << endl;
	damageCalc(mon, IMPACT, STRONG);
}

void Monster::shot1(Monster & mon)
{
	cout << "shot 1" << endl;
	damageCalc(mon, SHOT, WEAK);
}

void Monster::shot2(Monster & mon)
{
	cout << "shot 2" << endl;
	damageCalc(mon, SHOT, MEDIUM);
}

void Monster::shot3(Monster & mon)
{
	cout << "shot 3" << endl;
	damageCalc(mon, SHOT, STRONG);
}

void Monster::fire1(Monster & mon)
{
	cout << "fire 1" << endl;
	damageCalc(mon, FIRE, WEAK);
}

void Monster::fire2(Monster & mon)
{
	cout << "fire 2" << endl;
	damageCalc(mon, FIRE, MEDIUM);
}

void Monster::fire3(Monster & mon)
{
	cout << "fire 3" << endl;
	damageCalc(mon, FIRE, STRONG);
}


void Monster::ice1(Monster & mon)
{
	cout << "ice 1" << endl;
	damageCalc(mon, ICE, WEAK);
}

void Monster::ice2(Monster & mon)
{
	cout << "ice 2" << endl;
	damageCalc(mon, ICE, MEDIUM);
}

void Monster::ice3(Monster & mon)
{
	cout << "ice 3" << endl;
	damageCalc(mon, ICE, STRONG);
}

void Monster::water1(Monster & mon)
{
	cout << "water 1" << endl;
	damageCalc(mon, WATER, WEAK);
}

void Monster::water2(Monster & mon)
{
	cout << "water 2" << endl;
	damageCalc(mon, WATER, MEDIUM);
}

void Monster::water3(Monster & mon)
{
	cout << "water 3" << endl;
	damageCalc(mon, WATER, STRONG);
}

void Monster::thunder1(Monster & mon)
{
	cout << "thunder 1" << endl;
	damageCalc(mon, THUNDER, WEAK);
}

void Monster::thunder2(Monster & mon)
{
	cout << "thunder 2" << endl;
	damageCalc(mon, THUNDER, MEDIUM);
}

void Monster::thunder3(Monster & mon)
{
	cout << "thunder 3" << endl;
	damageCalc(mon, THUNDER, STRONG);
}

void Monster::dragon1(Monster & mon)
{
	cout << "dragon 1" << endl;
	damageCalc(mon, DRAGON, WEAK);
}

void Monster::dragon2(Monster & mon)
{
	cout << "dragon 2" << endl;
	damageCalc(mon, DRAGON, MEDIUM);
}

void Monster::dragon3(Monster & mon)
{
	cout << "dragon 3" << endl;
	damageCalc(mon, DRAGON, STRONG);
}

Monster::~Monster()
{
}
