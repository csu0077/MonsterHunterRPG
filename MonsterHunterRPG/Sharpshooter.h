#pragma once
#include "Human.h"
class Sharpshooter :
	public Human
{
public:
	Sharpshooter();
	void attack(Monster mon);
	~Sharpshooter();
};

