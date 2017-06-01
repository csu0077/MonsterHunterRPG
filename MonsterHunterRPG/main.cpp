#include <iostream>
#include <string>
#include "Monster.h"
#include "Sharpshooter.h"
#include "swordmaster.h"
#include "Monk.h"

using namespace std;

int main()
{
	//Monster(int hp, int mp, int atk, int def, int mag)
	Swordmaster masterFoo;
	
	cout << "Master foo hp: " << masterFoo.getMaxHP() << endl;
	cout << "Master foo mp: " << masterFoo.getMaxMP() << endl;
	cout << "Master foo atk: " << masterFoo.getMaxAtk() << endl;
	cout << "Master foo def: " << masterFoo.getMaxDef() << endl;
	cout << "Master foo mDef: " << masterFoo.getMaxMDef() << endl;
	cout << "Master foo mag: " << masterFoo.getMaxMag() << endl;

	string doo;
	getline(cin , doo);
}