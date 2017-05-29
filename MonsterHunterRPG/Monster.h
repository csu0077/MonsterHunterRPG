#pragma once
class Monster
{
public:
	Monster();
	Monster(int hp, int sp);
	int getHP();
	void setHP(int hp);
	int getMP();
	void setMP(int mp);
	bool* getStatus();
	void setStatus(int status);
	~Monster();

private:
	int HP;
	int MP; //magic points
	int atk; //attack
	int def; //defence
	int mag; //magic
	bool status[14]; //status effect array
};

