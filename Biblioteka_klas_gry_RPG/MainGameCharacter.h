#pragma once
#include "GameCharacter.h"

class MainGameCharacter :public GameCharacter
{
	int exp = 0;
	int nextLvl = 50;
public:
	MainGameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl);

	int getExp();
	void increaseExp(int exp);
	void increaseExpCap();

	bool run() override;
	int attack() override;
	void defend() override;
	void useItem() override;
	void levelUp();
};

