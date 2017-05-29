#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(int hp, int mp)
	:HP(hp),MP(mp)
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

bool* Monster::getStatus()
{
	return status;
}

Monster::~Monster()
{
}
