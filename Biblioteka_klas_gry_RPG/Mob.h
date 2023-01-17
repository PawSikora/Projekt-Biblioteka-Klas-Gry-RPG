#pragma once
#include "GameCharacter.h"

class Mob : public GameCharacter
{
public:
	Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl) : GameCharacter(name, race, characterClass, stats, alignment, health, mana, items, lvl)
	{
	} //!Masz to poprawic soltysie!

	bool run()  override { return true; }
	int attack() override { return 0; }
	void defend() override {}
	void useItem() override {}
};

