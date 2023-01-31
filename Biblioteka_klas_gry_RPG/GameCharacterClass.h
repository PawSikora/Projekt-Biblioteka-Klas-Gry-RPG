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

	std::string getName() const;
	ClassType getClassType() const;
	Ability* getAbility(int index) const;
	Ability* getUnlockedAbility(int index) const;
	std::string getAbilities();
	std::string getUnlockedAbilities();
	int getNumOfAvailableAbilities() const;
	int getNumOfUnlockedAbilities() const;
};

