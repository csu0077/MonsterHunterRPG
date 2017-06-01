#include "Sharpshooter.h"

Sharpshooter::Sharpshooter()
{
}

Sharpshooter::Sharpshooter(string name, int hp, int mp, int atk, int def, int mag, int mdef)
{
	Human(name, hp, mp, atk, def, mag, mdef);
}

void Sharpshooter::attack(Monster mon)
{
	shot1(mon);
}

Sharpshooter::~Sharpshooter()
{
}
