#pragma once


enum Ailment
{
	FIREBLIGHT,
	WATERBLIGHT,
	ICEBLIGHT,
	THUNDERBLIGHT,
	DRAGONBLIGHT,
	BLASTBLIGHT,
	POISON,
	DEADLYPOISON,
	LETHALPOISON,
	KO,
	PARALYSIS,
	MUDSNOW,
	SLEEP,
	BLEED
};

class Monster
{
public:
	Monster();
	Monster(int hp, int mp, int atk, int def, int mag, int mdef);
	int getHP();
	void setHP(int hp);
	int getMP();
	void setMP(int mp);
	int getAtk();
	void setAtk(int atk);
	int getDef();
	void setDef(int def);
	int getMag();
	void setMag(int mag);
	int getMDef();
	void setMDef(int mDef);
	bool* getStatus();
	void setStatus(int status);
	bool* getRes();
	void setRes(int res);

	int getMaxHP();
	int getMaxMP();
	int getMaxAtk();
	int getMaxDef();
	int getMaxMag();
	int getMaxMDef();

	void setMaxHP(int hp);
	void setMaxMP(int mp);
	void setMaxAtk(int atk);
	void setMaxDef(int def);
	void setMaxMag(int mag);
	void setMaxMDef(int mdef);

	//1= weak, 2 = medium, 3 = strong
	void slash1(Monster mon); //weak slash damage
	void slash2(Monster mon); //medium slash damage
	void slash3(Monster mon); //strong slash damage

	void impact1(Monster mon); //weak impact damage
	void impact2(Monster mon); //medium impact damage
	void impact3(Monster mon); //strong impact damage

	void shot1(Monster mon);
	void shot2(Monster mon);
	void shot3(Monster mon);

	void fire1(Monster mon);
	void fire2(Monster mon);
	void fire3(Monster mon);

	void ice1(Monster mon);
	void ice2(Monster mon);
	void ice3(Monster mon);

	void water1(Monster mon);
	void water2(Monster mon);
	void water3(Monster mon);

	void thunder1(Monster mon);
	void thunder2(Monster mon);
	void thunder3(Monster mon);

	void dragon1(Monster mon);
	void dragon2(Monster mon);
	void dragon3(Monster mon);


	~Monster();

private:
	int HP;
	int maxHP;
	int MP; //magic points
	int maxMP;
	int atk; //attack
	int maxAtk;
	int def; //defence
	int maxDef;
	int mag; //magic
	int maxMag;
	int mDef; //magic defence
	int maxMDef;
	bool status[14]; //status effect array
	int statusCounter[14];
	bool resistances[8]; //resistances array i.e. whether or not weak to ice/ resist to fire

	void damageCalc(Monster mon, int type, int power)	//type is type of damage i.e. slash damage, power is how strong the attack will be i.e. weak/medium/strong
	{
		double damage = mon.getDef() - getAtk();

		switch (power)
		{
		case 1:
			damage *= 1.25;
			break;
		case 2:
			damage *= 1.5;
			break;
		default:
			damage *= 1;
			break;
		}

		if (mon.getRes()[type])		//if the bool is true at index, that is the weakness
			damage *= 2;
		else
			damage /= 2;

		if (damage <= 0)
			damage = 0;					//no damage if negative value

		mon.setHP(mon.getHP() - damage);
	}

	void counter(int ailment)
	{
		if (!statusCounter[ailment])	//counter is zero, meaning no blight yet
			statusCounter[ailment] = 3;
		else
		{
			statusCounter[ailment]--;

			if (!statusCounter[ailment])
				setStatus(ailment);
		}
	}

	void ailmentCounter(int ailment)
	{
		double damage = 0.0;

		switch (ailment)
		{
		case FIREBLIGHT:
			counter(FIREBLIGHT);
			break;
		case WATERBLIGHT:
			counter(WATERBLIGHT);
			//todo implement turn system before hand
			break;
		case THUNDERBLIGHT:
			counter(THUNDERBLIGHT);
			//todo: add status vulerability chance
			break;
		case ICEBLIGHT:
			counter(ICEBLIGHT);
			//todo implement turn system before hand
			break;
		case DRAGONBLIGHT:
			counter(DRAGONBLIGHT);
			break;
		case BLASTBLIGHT:
			counter(BLASTBLIGHT);
			break;
		case POISON:
			counter(POISON);
			damage = 0.05 * double(getMaxHP()); 
			setHP(getHP() - damage);
			break;
		case DEADLYPOISON:
			counter(DEADLYPOISON);
			damage = 0.1 * double(getMaxHP());
			setHP(getHP() - damage);
			break;
		case LETHALPOISON:
			counter(LETHALPOISON);
			damage = 0.15 * double(getMaxHP());
			setHP(getHP() - damage);
			break;
		case KO:
			counter(KO);
			break;
		case PARALYSIS:
			counter(PARALYSIS);
			break;
		case MUDSNOW:
			counter(MUDSNOW);
			break;
		case SLEEP:
			counter(SLEEP);
			break;
		case BLEED:
			counter(BLEED);
			break;
		default:
			break;
		}
	}
};

