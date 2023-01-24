#pragma once
#include "GameCharacter.h"

class Mob : public GameCharacter
{
public:
	Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl);
	bool run()  override;
	int attack() override;
	void defend() override;
	void useItem() override;

	virtual ~Mob(){}
};

