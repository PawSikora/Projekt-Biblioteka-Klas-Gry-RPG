#pragma once
#include "Mob.h"
#include "MainGameCharacter.h"
class NPC : public Mob
{
	std::vector<Item*> itemList;
	Role role_;
	void printItems(std::vector<Item*> items);
	void greet();
	void SellItem(MainGameCharacter &character);
	void BuyItem(MainGameCharacter &character);
	void Dialog(MainGameCharacter &character);
	void DialogInnKeeper(MainGameCharacter &character);
	std::string myRole() const;

public:
	NPC(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats
		, int health, int mana, std::vector<Item*> items, unsigned lvl,Role role);
	void whatCanIDo(MainGameCharacter &character);

};

