#include "Human.h"

Human::Human()
	:HP(1),MP(1)
{}

Human::Human(int hp, int mp, int atk, int def, int mag)
	: HP(hp), MP(mp), atk(atk), def(def), mag(mag)
{}

int Human::getHP()
{
	return HP;
}

void Human::setHP(int hp)
{
	this->HP = hp;
}

int Human::getMP()
{
	return MP;
}

void Human::setMP(int mp)
{
	this->MP = mp;
}

int Human::getAtk()
{
	return this->atk;
}

void Human::setAtk(int atk)
{
	this->atk = atk;
}

int Human::getDef()
{
	return this->def;
}

void Human::setDef(int def)
{
	this->def = def;
}

int Human::getMag()
{
	return this->def;
}

void Human::setMag(int mag)
{
	this->mag = mag;
}

int Human::getMDef()
{
	return this->def;
}

void Human::setMDef(int mDef)
{
	this->mDef = mDef;
}

bool* Human::getStatus()
{
	return status;
}

void Human::setStatus(int ailment)
{
	this->status[ailment] = !this->status[ailment];	//pretty much just flip the bool
}

bool* Human::getRes()
{
	return this->resistances;
}

void Human::setRes(int res)
{
	this->resistances[res] = !this->resistances[res];  //pretty much just flip the bool
}

Human::~Human()
{
}
