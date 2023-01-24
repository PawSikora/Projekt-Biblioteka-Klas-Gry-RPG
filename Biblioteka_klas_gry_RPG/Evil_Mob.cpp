#include "Evil_Mob.h"

#include <iostream>
#include <random>

#include "Consumables.h"

bool Evil_Mob::run()
{
	return true;
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
		int numberOfItem = (mt() % getItems().size());
		std::cout << numberOfItem << "\n\n\n";
		item = getItems()[numberOfItem];


		if (dynamic_cast<Consumables*>(item))
		{
			Consumables* item_ = dynamic_cast<Consumables*>(item);
			addEffect(&item_->getEffect());
			std::cout << this->getName() << " uzywa " << item_->getName() << " nakladajac na siebie efekt: " << enumEffectConversion(item_->getEffect().getType()) << " +" << std::to_string(item_->getEffect().getEffect()) << std::endl;
		}

		if (dynamic_cast<Weapon*>(item))
		{
			if (weapon != nullptr && weapon->isEquipped())
			{
				std::cout << this->getName() << " odklada " << item->getName() << std::endl;
				weapon->unequipWeapon();
			}
			weapon = dynamic_cast<Weapon*>(item);
			weapon->equipWeapon();
			std::cout << this->getName() << " ekwipuje " << weapon->getName() << std::endl;
		}

		if (dynamic_cast<Armor*>(item))
		{
			if (armor != nullptr && armor->isEquipped())
			{
				std::cout << this->getName() << " sciaga " << item->getName() << std::endl;
				armor->unequipArmor();
			}
			armor = dynamic_cast<Armor*>(item);
			armor->equipArmor();
			std::cout << this->getName() << " zaklada " << armor->getName() << std::endl;
		}
	}
}


Evil_Mob::Evil_Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, int health, int mana, std::vector<Item*> items, unsigned lvl, DangerLvL danger_)
	: Mob(name, race, characterClass, stats, Alignment::Evil, health, mana, items, lvl), danger_(danger_)
{
}

int Evil_Mob::chooseAction(int numOfChoices)
{
	std::mt19937 mt(time(nullptr));
	/*if(mt()%4==0)
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
		
	}*/

	return mt() % numOfChoices;

}
