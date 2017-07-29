#include "Monk.h"

Monk::Monk()
{
}

Monk::Monk(string name)
{
	setInitStats(name, 200, 50, 100, 100, 100, 100, "Monk");

	for (int i = 0; i < getRes().size() - 1; i++)
	{
		setRes(i, 1);

	}

	/*for (int i = 0; i < getStatus().size() - 1; i++)
	{
		setStatus(i);
	}*/
	addSkill("impact1");
}

Monk::Monk(string name, int hp, int mp, int atk, int def, int mag, int mdef)
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
	setRole("Monk");

	for (int i = 0; i < getRes().size() - 1; i++)
	{
		setRes(i, 1);
		
	}


	addSkill("impact1");
}

void Monk::attack(Monster & mon)
{
	impact1(mon);
}

Monk::~Monk()
{
}
