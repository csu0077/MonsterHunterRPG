#include "Sharpshooter.h"

Sharpshooter::Sharpshooter()
{
}

Sharpshooter::Sharpshooter(string name, int hp, int mp, int atk, int def, int mag, int mdef)
{
	setName(name);
	setHP(hp);
	setMP(mp);
	setAtk(atk);
	setDef(def);
	setMag(mag);
	setMDef(mdef);
	setMaxHP(hp);
	setMaxMP(mp);
	setMaxAtk(atk);
	setMaxDef(def);
	setMaxMag(mag);
	setMaxMDef(mdef);

	for (int i = 0; i < getRes().size(); i++)
	{
		setRes(i, 1);

	}

	for (int i = 0; i < getStatus().size(); i++)
	{
		setStatus(i);
	}

}

void Sharpshooter::attack(Monster & mon)
{
	shot1(mon);
}

Sharpshooter::~Sharpshooter()
{
}
