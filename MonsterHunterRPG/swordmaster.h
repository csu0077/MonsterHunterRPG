#pragma once
#include "Human.h"

class Swordmaster :
	public Human
{
	public:
		Swordmaster();
		void attack(Monster mon);
		virtual ~Swordmaster();
};

