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
	Monster(name, hp, mp, atk, def, mag, mdef, "Human");	
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
			if (inventory[i].getCount())
			{
				inventory[i].setCount(inventory[i].getCount() - 1);
				return;
			}
			else
			{
				Item temp = inventory[inventory.size() - 1];
				inventory[i] = temp;
				inventory.pop_back();
				return;
			}
		}
	}
}

void hpMPCheck(int points, Human & h, Item i)	//helper function for use item
{
	if (h.getHP() + points > h.getMaxHP())
	{
		h.setHP(h.getMaxHP());
		h.removeItem(i.getName());
		return;
	}
	else
	{
		h.setHP(h.getHP() + points);
		h.removeItem(i.getName());
		return;
	}
}

void Human::useItem(string name)
{
	//Potion
	//0 == 50 hp one target, 1 == 50 hp all, 2 == 100 hp one target, 3 == 100 hp all, 4 == 200 hp one, 
	//5 == 200 hp all, 6 == 500 hp one, 7 == 500 all, 8 == full heal, 9 == full heal all

	//Ether
	//0 == 25 mp one target, 1 == 25 mp all, 2 == 50 mp target, 3 == 50 mp all, 4 == 100 sp one, 
	//5 == 100 sp all, 6 == 250 sp one, 7 == 250 all, 8 == full sp heal, 9 == full sp heal all

	//Tonic
	//0 == blight heal, 1 == poison heal, 2 == para heal, 3 == mud/snow cleanse, 4 == wake up
	//5 == bleed heal
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getName() == name)
		{
			if (name == "hamburger")
			{
				int health = 50;

				hpMPCheck(health, *this, inventory[i]);
			}
			else if (name == "cheeseburger")
			{
				int health = 100;

				hpMPCheck(health, *this, inventory[i]);
			}
			else if (name == "Western bacon burger")
			{
				int health = 200;
				hpMPCheck(health, *this, inventory[i]);
			}
			else if (name == "7up")
			{
				int mp = 25;
				hpMPCheck(mp, *this, inventory[i]);
			}
			else if (name == "Coke")
			{
				int mp = 50;
				hpMPCheck(mp, *this, inventory[i]);
			}
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
