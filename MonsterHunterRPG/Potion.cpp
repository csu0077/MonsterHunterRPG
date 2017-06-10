#include "Potion.h"



Potion::Potion()
{
}

Potion::Potion(int tier)
{
	setTier(tier);
}

Potion::Potion(int tier, int count, string name)
{
	setName(name);
	setCount(count);
	setTier(tier);
}


Potion::~Potion()
{
}
