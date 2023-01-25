#include "Mob.h"
#include <iostream>

#include "Consumables.h"


Mob::Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl)
	: GameCharacter(name, race, characterClass, stats, alignment, health, mana, items, lvl)
{} 