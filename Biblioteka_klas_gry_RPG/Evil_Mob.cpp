#include "Evil_Mob.h"

Evil_Mob::Evil_Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, int health, int mana, std::vector<Item*> items, unsigned lvl, DangerLvL danger_)
	: Mob(name, race, characterClass, stats, Alignment::Evil, health, mana, items, lvl), danger_(danger_)
{
}