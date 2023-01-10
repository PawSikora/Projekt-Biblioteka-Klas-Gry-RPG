#include "MainGameCharacter.h"

MainGameCharacter::MainGameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl, std::string playerName)
	:GameCharacter(name,race,characterClass,stats,alignment,health,mana,items,lvl),playerName(playerName)
{
}

bool MainGameCharacter::run()
{
	return false;
}

bool MainGameCharacter::attack()
{
	return false;
}

bool MainGameCharacter::defend()
{
	return false;
}

void MainGameCharacter::useItem()
{
}
