#pragma once
#include "Monster.h"
#include "Item.h"
#include <vector>

class Human:
	public Monster
{
public:
	Human();
	Human(string name, int hp, int mp, int atk, int def, int mag, int mdef);
	void attack(Monster mon);
	Item getItem(int i);	//returns item at index i
	void addItem(Item item); //not increment but just add to the inventory
	void removeItem(int i); //removes item from invetory
	void useItem(string name);
	vector <Item> getInventory();
	~Human();

private:
	vector <Item> inventory = vector <Item> (30);
	//gem class 

};

