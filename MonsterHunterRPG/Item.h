#pragma once
#include <string>
using namespace std;

class Item
{
public:
	Item();
	Item(int tier, int count, string name);
	int getTier();
	int getCount();
	string getName();
	void setName(string name);
	void setCount(int count);
	void setTier(int tier);
	void operator = (const Item & I);
	~Item();

private:
	int tier;
	string name;
	int count;
	//Potion
	//0 == 50 hp one target, 1 == 50 hp all, 2 == 100 hp one target, 3 == 100 hp all, 4 == 200 hp one, 
	//5 == 200 hp all, 6 == 500 hp one, 7 == 500 all, 8 == full heal, 9 == full heal all

	//Ether
	//0 == 25 mp one target, 1 == 25 mp all, 2 == 50 mp target, 3 == 50 mp all, 4 == 100 sp one, 
	//5 == 100 sp all, 6 == 250 sp one, 7 == 250 all, 8 == full sp heal, 9 == full sp heal all

	//Tonic
	//0 == blight heal, 1 == poison heal, 2 == para heal, 3 == mud/snow cleanse, 4 == wake up
	//5 == bleed heal
};

