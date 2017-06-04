#pragma once
#include "Item.h"



Item::Item()
	:tier(0)
{
}

Item::Item(int t)
	:tier(t)
{
}

int Item::getTier()
{
	return tier;
}

void Item::setTier(int tier)
{
	this->tier = tier;
}

Item::~Item()
{
}
