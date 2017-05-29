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

bool* Human::getStatus()
{
	return status;
}

void Human::setStatus(int ailment)
{
	this->status[ailment] = !this->status[ailment];	//pretty much just flip the bool
}

Human::~Human()
{
}
