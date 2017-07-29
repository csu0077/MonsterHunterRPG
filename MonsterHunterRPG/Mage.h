#pragma once
#include "Human.h"
class Mage :
	public Human
{
public:
	Mage();
	Mage(string name);
	Mage(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	~Mage();
};

