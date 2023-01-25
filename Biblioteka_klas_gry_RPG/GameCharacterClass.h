#pragma once
#include <string>
#include <vector>

#include "Ability.h"

class GameCharacterClass
{
	ClassType classType;
	std::vector<Ability*> abilities;
	std::vector<Ability*> unlockedAbilities;

public:
	GameCharacterClass(ClassType classType, std::vector<Ability*> abilities);

	void addAbility(Ability* ability);
	void abilityUnlocked(Ability* ability);

	std::string getName();
	ClassType getClassType();
	Ability* getAbility(int index);
	Ability* getUnlockedAbility(int index);
	std::string getAbilities();
	std::string getUnlockedAbilities();
	int getNumOfAvailableAbilities();
	int getNumOfUnlockedAbilities();
};

