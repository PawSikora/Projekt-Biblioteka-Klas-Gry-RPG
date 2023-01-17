#include "Mob.h"
#include <iostream>

#include "Consumables.h"


Mob::Mob(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl)
	: GameCharacter(name, race, characterClass, stats, alignment, health, mana, items, lvl)
{

} 

bool Mob::run()
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

int Mob::attack()
{
	int damage = 0;
	damage += weapon->getDmg();
	if (getClass().getName() == "Wojownik")
	{
		damage += (getStats().getStrength() + addModifiers(buffs.strengthBuffs) / 2.0);
	}
	else if (getClass().getName() == "Czarodziej")
	{
		damage += (getStats().getIntelligence() + addModifiers(buffs.intelligenceBuffs) / 2.0);
	}
	else if (getClass().getName() == "Lotrzyk")
	{
		damage += (getStats().getDexterity() + addModifiers(buffs.dexterityBuffs) / 2.0);
	}

	return damage;
}

void Mob::defend()
{
	Effect defend("Defending", EffectType::Defending, 3, 3);
	addEffect(&defend);
}

void Mob::useItem()
{
	if (getItems().size() <= 0)
		std::cout << "Nie masz zadnych przedmiotow!\n";
	else
	{
		int choice;
		std::cout << "Z jakiego przedmiotu w plecaku chcialbys skorzystac?\n";
		for (int i = 0; i < getItems().size(); i++)
		{
			std::cout << i + 1 << ". " << getItems()[i]->getName() << std::endl;
		}

		do
		{
			std::cin >> choice;
			if (choice > getItems().size() || choice < 1)
				std::cout << "Wybierz poprawny przedmiot!(1-" << getItems().size() << ")\n";
		} while (choice < 1 || choice > getItems().size());

		Item* item = getItems().at(choice - 1);

		if (dynamic_cast<Consumables*>(item))
		{
			Consumables* item_ = dynamic_cast<Consumables*>(item);
			Effect effect = item_->getEffect();
			addEffect(&effect);
		}


		if (dynamic_cast<Weapon*>(item))
		{
			//if (weapon != nullptr && weapon->isEquipped())
				//weapon->unequipWeapon();
			dynamic_cast<Weapon*>(item)->equipWeapon();
			weapon->equipWeapon();
		}


		if (dynamic_cast<Armor*>(item))
		{
			if (weapon != nullptr || armor->isEquipped())
				armor->unequipArmor();
			dynamic_cast<Armor*>(item)->equipArmor();
			armor->equipArmor();
		}

	}
}