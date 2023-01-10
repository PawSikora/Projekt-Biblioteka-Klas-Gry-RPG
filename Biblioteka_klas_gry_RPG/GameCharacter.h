#pragma once
#include <string>
#include <vector>

#include "GameCharacterClass.h"
#include "IActions.h"
#include "Item.h"
#include "Statistics.h"
#include "Parameters.h"

class GameCharacter : public IActions
{
	std::string name;
	GameCharacterRace race;
	GameCharacterClass characterClass;
	Statistics stats;
	Alignment alignment;
	int hp;
	int mp;
	std::vector<Item*> items;
	unsigned int lvl;

	void setHp(int hp);
	void setMp(int mp);
	void setLvl(unsigned int lvl);

protected:
	GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl);

public:
	std::string getName();
	int getHp();
	int getMp();
	unsigned int getLvl();

	virtual ~GameCharacter() {}
};

