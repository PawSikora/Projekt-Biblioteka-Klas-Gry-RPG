#pragma once
#include "Item.h"
#include "Resistances.h"

class Armor : public Item
{
	bool equip;
	int defense;
	int mobilityPenalty;
	Resistances resistances;

public:
	Armor(std::string name, int value, int defense, int mobilityPenalty, Resistances resistances);
	void setDefense(int defense);
	void setMobilityPenalty(int MobilityPenalty);

	int getDefense();
	int getMobilityPenalty();
	Resistances getResistances();
};

