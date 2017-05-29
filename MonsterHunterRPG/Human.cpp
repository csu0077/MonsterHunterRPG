#include "Human.h"

Human::Human()
	:HP(1),MP(1)
{}

Human::Human(int hp, int mp)
	: HP(hp), MP(mp)
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
	this->status[ailment] = !this->status[ailment];
}

Human::~Human()
{
}
