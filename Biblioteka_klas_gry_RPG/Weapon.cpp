#include "Weapon.h"

#include <stdexcept>

void Weapon::setDmg(int dmg)
{
	if (dmg < 0) throw std::invalid_argument("Obrazenia nie moga byc ujemne");
	this->dmg = dmg;
}

void Weapon::setArmorPenetration(int armorPenetration)
{
	if (armorPenetration < 0) throw std::invalid_argument("Pzebicie pancerza nie moze byc ujemne");
	this->armorPenetration = armorPenetration;
}

Weapon::Weapon(std::string name, int value, int dmg, int armorPenetration)
	:Item(name,value)
{
	setDmg(dmg);
	setArmorPenetration(armorPenetration);
}
