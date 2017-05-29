#pragma once
class Human
{
public:
	Human();
	Human(int hp, int sp);
	int getHP();
	void setHP(int hp);
	int getMP();
	void setMP(int mp);
	bool* getStatus();
	void setStatus(int status);
	~Human();

private:
	int HP;	//hit points
	int MP; //magic points
	bool status[14]; //status effect array
	//inventory class
	//gem class 
};

