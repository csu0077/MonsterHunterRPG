#pragma once
#include "Monster.h"
#include "Item.h"
#include <vector>

class Human:
	public Monster
{
public:
	Human();
	Human(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	void attack(Monster mon);
	
	~Human();
	
	//gem class 

};

