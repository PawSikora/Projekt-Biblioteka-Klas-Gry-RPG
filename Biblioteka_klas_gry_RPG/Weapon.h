#pragma once
#include "Item.h"
class Weapon : public Item
{
	bool equip;
	int dmg;
	int armorPenetration;

public:
	Weapon(std::string name, int value, int dmg, int armorPenetration);
	void setDmg(int dmg);
	void setArmorPenetration(int armorPenetration);
};

