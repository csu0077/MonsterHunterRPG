#pragma once
#include "Item.h"



Item::Item()
	:tier(0), count(0), name("")
{
}

Item::Item(int tier, int count, string name)
	:tier(tier), count(count), name(name)
{
}

int Item::getTier()
{
	return tier;
}

int Item::getCount()
{
	return count;
}

string Item::getName()
{
	return this->name;
}

void Item::setName(string name)
{
	this->name = name;
}

void Item::setCount(int count)
{
	this->count = count;
}

void Item::setTier(int tier)
{
	this->tier = tier;
}

void Item::operator=(const Item & I)
{
	this->name = I.name;
	this->count = I.count;
	this->tier = I.tier;
}

Item::~Item()
{
}
