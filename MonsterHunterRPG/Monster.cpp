#include "Monster.h"

Monster::Monster()
	:HP(1),MP(1),atk(1),def(1),mag(1)
{
}

Monster::Monster(int hp, int mp, int atk, int def, int mag)
	:HP(hp),MP(mp),atk(atk),def(def),mag(mag)
{}

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


void Monster::setStatus(int ailment)
{
	this->status[ailment] = !this->status[ailment];  //pretty much just flip the bool
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
	return this->def;
}

void Monster::setMag(int mag)
{
	this->mag = mag;
}

int Monster::getMDef()
{
	return this->def;
}

void Monster::setMDef(int mDef)
{
	this->mDef = mDef;
}

bool* Monster::getStatus()
{
	return status;
}

Monster::~Monster()
{
}
