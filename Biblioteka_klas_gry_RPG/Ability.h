#pragma once
#include <string>

#include "Effect.h"
#include "Parameters.h"
class Ability
{
	std::string name;
	int mpCost;
	bool unlocked = false;
	AbilityType type;
	int damage;
	Effect effect;

	void setDmg(int dmg);
public:
	Ability(std::string name, AbilityType type, int damage, int mpCost, Effect effect);
	void setMpCost(int mpCost);

	std::string getName();
	AbilityType getType() const;
	int getDmg() const;
	int getMpCost() const;
	Effect& getEffect();
	bool getStatus() const;

	Ability* unlockAbility();
};

