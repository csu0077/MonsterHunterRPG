#include "Human.h"

enum MyEnum
{
	SLASH,
	IMPACT,
	SHOT,
	FIRE,
	ICE,
	WATER,
	THUNDER,
	DRAGON
};

enum MyEnum1
{
	WEAK,
	MEDIUM,
	STRONG
};

Human::Human()
{
	Monster();
	void setCount(int count);
	void setTier(int tier);
}

Human::Human(string name, int hp, int mp, int atk, int def, int mag, int mdef)
{
	Monster(name, hp, mp, atk, def, mag, mdef, "Human");	
	Item filler;
	//inventory.push_back(filler);
}

void Human::attack(Monster mon)
{
}


Human::~Human()
{
}
