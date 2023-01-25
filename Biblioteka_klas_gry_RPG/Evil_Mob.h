#pragma once
#include "Mob.h"

class Evil_Mob : public Mob
{
	int exp;
	DangerLvL danger_;
	bool escaped = false;
public:
	Evil_Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats,
		int health, int mana, std::vector<Item*> items, unsigned lvl, DangerLvL danger_, int exp);

	bool run() override;
	int attack() override;
	void defend() override;
	void useItem() override;
	int chooseAction(int numOfChoices);

	DangerLvL getDanger() const;
	int getExp();
	bool getEscaped();

	void setDanger(DangerLvL danger);
	void setExp(int exp);
};

