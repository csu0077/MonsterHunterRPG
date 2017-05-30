#pragma once
class Human
{
public:
	Human();
	Human(int hp, int mp, int atk, int def, int mag);
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

	~Human();

private:
	int HP;	//hit points
	int MP; //magic points
	int atk; //attack
	int def; //defence
	int mag; //magic
	int mDef; //magic defence
	
	bool status[14]; //status effect array
	bool resistances[8]; //resistances array i.e. whether or not weak to ice/ resist to fire
	//inventory class
	//gem class 
};

