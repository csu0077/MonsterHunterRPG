#pragma once
class Monster
{
public:
	Monster();
	Monster(int hp, int mp, int atk, int def, int mag);
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
	~Monster();

private:
	int HP;
	int MP; //magic points
	int atk; //attack
	int def; //defence
	int mag; //magic
	int mDef; //magic defence
	bool status[14]; //status effect array
	bool resistances[8]; //resistances array i.e. whether or not weak to ice/ resist to fire
};

