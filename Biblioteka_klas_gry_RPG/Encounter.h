#pragma once
#include <vector>

#include "Dice.h"
#include "Evil_Mob.h"
#include "MainGameCharacter.h"
#include "Mob.h"


class Encounter
{
	Dice d4, d6, d8, d10, d12, d20;

public:
	Encounter();

	void combat(std::vector<MainGameCharacter*> heroes, std::vector<Evil_Mob*> enemies);

	bool isNumber(std::string& s);
	int forceNumberInput(std::string& answer);
};
