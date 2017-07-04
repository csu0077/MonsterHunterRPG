#pragma once
#include "Human.h"
class Monk :
	public Human
{
public:
	Monk();
	Monk(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	virtual void attack(Monster & mon);
	~Monk();
};

