#pragma once
#include "Item.h"
class Tonic :		//for healing status ailments i.e. poison or fire blight
	public Item
{
public:
	Tonic();
	Tonic(int tier);
	~Tonic();
};

