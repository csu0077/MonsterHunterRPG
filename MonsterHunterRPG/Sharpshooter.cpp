#include "Sharpshooter.h"

Sharpshooter::Sharpshooter()
{
}

Sharpshooter::Sharpshooter(string name)
{
	setInitStats(name, 100, 100, 150, 50, 50, 50, "Sharpshooter");

	for (int i = 0; i < getRes().size(); i++)
	{
		setRes(i, 1);

	}

	/*for (int i = 0; i < getStatus().size(); i++)
	{
		setStatus(i);
	}*/

	addSkill("shot1");
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
	setRole("Sharpshooter");

	for (int i = 0; i < getRes().size() - 1; i++)
	{
		setRes(i, 1);

	}

	/*for (int i = 0; i < getStatus().size() - 1; i++)
	{
		setStatus(i);
	}*/

	addSkill("shot1");
}

Sharpshooter::~Sharpshooter()
{
}
