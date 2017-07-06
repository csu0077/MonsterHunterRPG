#include "swordmaster.h"

Swordmaster::Swordmaster()
{
	Monster();
}

Swordmaster::Swordmaster(string name, int hp, int mp, int atk, int def, int mag, int mdef)
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
	setRole("Swordmaster");
	for (int i = 0; i < getRes().size() - 1; i++)
	{
		setRes(i, 1);

	}

	for (int i = 0; i < getStatus().size() - 1; i++)
	{
		setStatus(i);
	}

	this->addSkill("slash1");
}

void Swordmaster::attack(Monster & mon)
{
	slash1(mon);
}

Swordmaster::~Swordmaster()
{
}
