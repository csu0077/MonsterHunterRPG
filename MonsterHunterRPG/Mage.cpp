#include "Mage.h"



Mage::Mage()
{
}

Mage::Mage(string name)
{
	setInitStats(name, 50, 200, 50, 50, 200, 150, "Mage");

	for (int i = 0; i < getRes().size(); i++)
	{
		setRes(i, 1);

	}


	addSkill("fire1");
	addSkill("ice1");
	addSkill("thunder1");
	addSkill("water1");
	addSkill("dragon1");
}

Mage::Mage(string name, int hp, int mp, int atk, int def, int mag, int mdef)
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

	for (int i = 0; i < getRes().size(); i++)
	{
		setRes(i, 1);

	}

	/*for (int i = 0; i < getStatus().size(); i++)
	{
		setStatus(i);
	}*/

	addSkill("fire1");
	addSkill("ice1");
	addSkill("thunder1");
	addSkill("water1");
	addSkill("dragon1");
}

Mage::~Mage()
{
}
