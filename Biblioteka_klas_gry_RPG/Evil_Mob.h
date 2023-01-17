#pragma once
#include "Mob.h"

class Evil_Mob : public Mob
{
	DangerLvL danger_;

public:
	Evil_Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats,
		int health, int mana, std::vector<Item*> items, unsigned lvl, DangerLvL danger_);

	DangerLvL danger() const
	{
		return danger_;
	}

	void set_danger(DangerLvL danger)
	{
		danger_ = danger;
	}
};

