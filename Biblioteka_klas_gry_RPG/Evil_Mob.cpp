#include "Evil_Mob.h"

#include <iostream>
#include <random>

#include "Consumables.h"

bool Evil_Mob::run()
{
	std::cout << "Czy na pewno chcesz uciec?[t/n]";
	std::string choice;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, choice);
	if (choice.find('t'))
		return true;
	return false;
}

int Evil_Mob::attack()
{
	int damage = 0;
	if (weapon != nullptr)
		damage += weapon->getDmg();

	if (getClass().getClassType() == ClassType::Warrior)
	{
		damage += (getStats().getStrength() + addModifiers(buffs.strengthBuffs) / 2.0);
	}
	else if (getClass().getClassType() == ClassType::Mage)
	{
		damage += (getStats().getIntelligence() + addModifiers(buffs.intelligenceBuffs) / 2.0);
	}
	else if (getClass().getClassType() == ClassType::Rogue)
	{
		damage += (getStats().getDexterity() + addModifiers(buffs.dexterityBuffs) / 2.0);
	}

	return damage;
}

void Evil_Mob::defend()
{
	Effect defend("Defending", EffectType::Defending, 3, 3);
	addEffect(&defend);
}

void Evil_Mob::useItem()
{
	if (getItems().size() <= 0);
	else
	{

		Item* item;
		std::mt19937 mt(time(nullptr));
		int numberOfItem = (mt() % getItems().size()) -1;
		item = getItems()[numberOfItem];


		if (dynamic_cast<Consumables*>(item))
		{
			Consumables* item_ = dynamic_cast<Consumables*>(item);
			Effect effect = item_->getEffect();
			addEffect(&effect);
		}

		if (dynamic_cast<Weapon*>(item))
		{
			if (weapon != nullptr && weapon->isEquipped())
				weapon->unequipWeapon();
			weapon = dynamic_cast<Weapon*>(item);
			weapon->equipWeapon();
		}

		if (dynamic_cast<Armor*>(item))
		{
			if (armor != nullptr && armor->isEquipped())
				armor->unequipArmor();
			armor = dynamic_cast<Armor*>(item);
			armor->equipArmor();
		}
	}
}


Evil_Mob::Evil_Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, int health, int mana, std::vector<Item*> items, unsigned lvl, DangerLvL danger_)
	: Mob(name, race, characterClass, stats, Alignment::Evil, health, mana, items, lvl), danger_(danger_)
{
}

void Evil_Mob::doSomething()
{
	std::mt19937 mt(time(nullptr));
	if(mt()%4==0)
	{
		run();
	}
	if (mt() % 4 == 1)
	{
		attack();
	}
	if (mt() % 4 == 2)
	{
		defend();
	}
	if (mt() % 4 == 3)
	{
		
	}


}
