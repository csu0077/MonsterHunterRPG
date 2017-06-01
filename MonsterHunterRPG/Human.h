#pragma once
#include "Monster.h"

class Human:
	public Monster
{
public:
	Human();
	Human(int hp, int mp, int atk, int def, int mag, int mdef);
	void attack(Monster mon);
	~Human();

private:
	//inventory class
	//gem class 

};

