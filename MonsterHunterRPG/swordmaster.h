#pragma once
#include "Human.h"

class Swordmaster :
	public Human
{
	public:
		Swordmaster();
		Swordmaster(string name);
		Swordmaster(string name, int hp, int mp, int atk, int def, int mag, int mdef);
		virtual ~Swordmaster();
};

