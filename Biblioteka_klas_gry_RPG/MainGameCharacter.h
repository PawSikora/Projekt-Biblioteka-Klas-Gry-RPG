#pragma once
#include "GameCharacter.h"

class MainGameCharacter :public GameCharacter
{
	std::string playerName;

public:
	MainGameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl ,std::string playerName);
	bool run() override;
	bool attack() override;
	bool defend() override;
	void useItem() override;
};

