#include "GameCharacter.h"

#include <stdexcept>

GameCharacter::GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl)
	:name(name),race(race),characterClass(characterClass), stats(stats), alignment(alignment), items(items)
{
	setHp(hp);
	setMp(mp);
	setLvl(lvl);
}

int GameCharacter::getHp()
{
	return hp;
}

int GameCharacter::getMp()
{
	return mp;
}

unsigned int GameCharacter::getLvl()
{
	return lvl;
}

void GameCharacter::setHp(int hp)
{
	if (hp < 0) throw std::invalid_argument("Hp musi byc liczba dodatnia");
	this->hp = hp;
}

void GameCharacter::setMp(int mp)
{
	if (mp < 0) throw std::invalid_argument("Mp musi byc liczba dodatnia");
	this->mp = mp;
}

void GameCharacter::setLvl(unsigned int lvl)
{
	if (lvl < 0) throw std::invalid_argument("Lvl musi byc liczba dodatnia");
	this->lvl = lvl;
}
