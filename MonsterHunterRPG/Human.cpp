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
}

Human::Human(int hp, int mp, int atk, int def, int mag, int mdef)
{
	Monster(hp, mp, atk, def, mag, mdef );
}

void Human::attack(Monster mon)
{
}

Human::~Human()
{
}
