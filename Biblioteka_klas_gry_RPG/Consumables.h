#pragma once
#include "Ability.h"
#include "Item.h"

class Consumables : public Item
{
	Effect* effect = nullptr;
	bool used = false;

public:
	Consumables(std::string name, int value, Effect* effect);
	Effect* getEffect() const;

	void useItem();
	bool getUsed() const;

	~Consumables();
};

