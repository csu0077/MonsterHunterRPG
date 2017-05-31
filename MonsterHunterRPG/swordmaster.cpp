#include "swordmaster.h"

Swordmaster::Swordmaster()
{
	Monster();
}

void Swordmaster::attack(Monster mon)
{
	slash1(mon);
}

Swordmaster::~Swordmaster()
{
}
