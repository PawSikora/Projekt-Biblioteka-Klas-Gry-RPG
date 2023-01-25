#pragma once
#include "GameCharacter.h"

class Mob : public GameCharacter
{
public:
	Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl);

	virtual ~Mob(){}
};

