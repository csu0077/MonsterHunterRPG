#pragma once
#include "Human.h"
class Monk :
	public Human
{
public:
	Monk();
	void attack(Monster mon);
	~Monk();
};

