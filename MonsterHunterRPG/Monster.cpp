#include "Monster.h"

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

Monster::Monster()
	:HP(1),MP(1),atk(1),def(1),mag(1)
{
}

Monster::Monster(int hp, int mp, int atk, int def, int mag)
	:HP(hp),MP(mp),atk(atk),def(def),mag(mag)
{}

void Monster::setHP(int hp)
{
	this->HP = hp;
}

int Monster::getHP()
{
	return this->HP;
}

void Monster::setMP(int mp)
{
	this->MP = mp;
}

int Monster::getMP()
{
	return this->MP;
}

int Monster::getAtk()
{
	return this->atk;
}

void Monster::setAtk(int atk)
{
	this->atk = atk;
}

int Monster::getDef()
{
	return this->def;
}

void Monster::setDef(int def)
{
	this->def = def;
}

int Monster::getMag()
{
	return this->def;
}

void Monster::setMag(int mag)
{
	this->mag = mag;
}

int Monster::getMDef()
{
	return this->def;
}

void Monster::setMDef(int mDef)
{
	this->mDef = mDef;
}

bool* Monster::getStatus()
{
	return this->status;
}

void Monster::setStatus(int ailment)
{
	this->status[ailment] = !this->status[ailment];  //pretty much just flip the bool
}

bool* Monster::getRes()
{
	return this->resistances;
}

void Monster::setRes(int res)
{
	this->resistances[res] = !this->resistances[res];  //pretty much just flip the bool
}

void Monster::slash1(Monster mon) //weak slash damage
{
	damageCalc(mon, SLASH, WEAK);
}

void Monster::slash2(Monster mon) //medium slash damage
{
	damageCalc(mon, SLASH, MEDIUM);
}

void Monster::slash3(Monster mon) //strong slash damage
{
	damageCalc(mon, SLASH, STRONG);
}

void Monster::impact1(Monster mon) 
{
	damageCalc(mon, IMPACT, WEAK);
}

void Monster::impact2(Monster mon)
{
	damageCalc(mon, IMPACT, MEDIUM);
}

void Monster::impact3(Monster mon)
{
	damageCalc(mon, IMPACT, STRONG);
}

void Monster::shot1(Monster mon)
{
	damageCalc(mon, SHOT, WEAK);
}

void Monster::shot2(Monster mon)
{
	damageCalc(mon, SHOT, MEDIUM);
}

void Monster::shot3(Monster mon)
{
	damageCalc(mon, SHOT, STRONG);
}

void Monster::fire1(Monster mon)
{
	damageCalc(mon, FIRE, WEAK);
}

void Monster::fire2(Monster mon)
{
	damageCalc(mon, FIRE, MEDIUM);
}

void Monster::fire3(Monster mon)
{
	damageCalc(mon, FIRE, STRONG);
}


void Monster::ice1(Monster mon)
{
	damageCalc(mon, ICE, WEAK);
}

void Monster::ice2(Monster mon)
{
	damageCalc(mon, ICE, MEDIUM);
}

void Monster::ice3(Monster mon)
{
	damageCalc(mon, ICE, STRONG);
}

void Monster::water1(Monster mon)
{
	damageCalc(mon, WATER, WEAK);
}

void Monster::water2(Monster mon)
{
	damageCalc(mon, WATER, MEDIUM);
}

void Monster::water3(Monster mon)
{
	damageCalc(mon, WATER, STRONG);
}

void Monster::thunder1(Monster mon)
{
	damageCalc(mon, THUNDER, WEAK);
}

void Monster::thunder2(Monster mon)
{
	damageCalc(mon, THUNDER, MEDIUM);
}

void Monster::thunder3(Monster mon)
{
	damageCalc(mon, THUNDER, STRONG);
}

void Monster::dragon1(Monster mon)
{
	damageCalc(mon, DRAGON, WEAK);
}

void Monster::dragon2(Monster mon)
{
	damageCalc(mon, DRAGON, MEDIUM);
}

void Monster::dragon3(Monster mon)
{
	damageCalc(mon, DRAGON, STRONG);
}

void Monster::fireBlight()
{

}

void Monster::waterBlight()
{
}

void Monster::thunderBlight()
{
}

void Monster::iceBlight()
{
}

void Monster::dragonBlight()
{
}

void Monster::blastBlight()
{
}

void Monster::poison()
{
}

void Monster::dPoison()
{
}

void Monster::lPoison()
{
}

void Monster::KO()
{
}

void Monster::para()
{
}

void Monster::mudSnow()
{
}

void Monster::sleep()
{
}

void Monster::bleed()
{
}

Monster::~Monster()
{
}
