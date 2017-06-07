#include <iostream>
#include <string>
#include "Monster.h"
#include "Sharpshooter.h"
#include "swordmaster.h"
#include "Monk.h"

using namespace std;

void testCode()
{
	//Monster(string name, int hp, int mp, int atk, int def, int mag, mdef)
	Swordmaster masterFoo;
	cout << "Master foo hp: " << masterFoo.getMaxHP() << endl;
	cout << "Master foo mp: " << masterFoo.getMaxMP() << endl;
	cout << "Master foo atk: " << masterFoo.getMaxAtk() << endl;
	cout << "Master foo def: " << masterFoo.getMaxDef() << endl;
	cout << "Master foo mDef: " << masterFoo.getMaxMDef() << endl;
	cout << "Master foo mag: " << masterFoo.getMaxMag() << endl;
	Sharpshooter shooterBar("obama", 10, 10, 10, 10, 0, 0);
	cout << shooterBar.getName() << endl;
	cout << shooterBar.getMaxHP() << endl;
	cout << shooterBar.getMaxMP() << endl;
	cout << shooterBar.getMaxAtk() << endl;
	cout << shooterBar.getMaxDef() << endl;
	cout << shooterBar.getMaxMDef() << endl;
	cout << shooterBar.getMaxMag() << endl;
}

int main()
{
	testCode();
	string doo;
	getline(cin , doo);
}