#pragma once
#include "Item.h"
class Potion :
	public Item
{
public:
	Potion();
	Potion(int tier);
	Potion(int tier, int count, string name);
	~Potion();
};

