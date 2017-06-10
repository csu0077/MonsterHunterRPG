#include "Human.h"

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

Human::Human()
{
	Monster();
	void setCount(int count);
	void setTier(int tier);
}

Human::Human(string name, int hp, int mp, int atk, int def, int mag, int mdef)
{
	Monster(name, hp, mp, atk, def, mag, mdef );	
	Item filler;
	inventory.push_back(filler);
}

void Human::attack(Monster mon)
{
}

Item Human::getItem(int i)
{
	return inventory[i];
}

void Human::addItem(Item item)
{
	for (int i = 0; i < inventory.size() - 1; i++)
	{
		if (inventory[i].getName() == "")
		{
			inventory[i] = item;
			return;
		}
		else if (inventory[i].getName() == item.getName())
		{
			inventory[i].setCount(inventory[i].getCount() + 1);
			return;
		}
	}

	inventory.push_back(item);
}

void Human::removeItem(string name)
{
	for (int i = 0; i < inventory.size() - 1; i++)
	{
		if (inventory[i].getName() == name)	
		{ 
			inventory[i].setName("");
			inventory[i].setCount(0);
			inventory[i].setTier(0);
			break;
		}
			
	}
}

vector<Item> Human::getInventory()
{
	return inventory;
}

Human::~Human()
{
}
