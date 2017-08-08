#pragma once
#include "Human.h"
class Sharpshooter :
	public Human
{
public:
	Sharpshooter();
	Sharpshooter(string name);
	Sharpshooter(string name, int hp, int mp, int atk, int def, int mag, int mdef);

	~Sharpshooter();
};

