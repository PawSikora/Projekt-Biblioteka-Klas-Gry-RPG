#pragma once
#include <string>

#include "Effect.h"
#include "Parameters.h"
class Ability
{
	std::string name;
	bool unlocked;
	AbilityType type;
	int damage;
	Effect effect;

	void setDmg(int dmg);
public:
	Ability(std::string name, AbilityType type, int damage, Effect effect);
	std::string getName();
	AbilityType getType();
	int getDmg();
	Effect getEffect();

	//??
	void unlockAbility();
};
