#include "MainGameCharacter.h"
#include <iostream>

#include "Consumables.h"


MainGameCharacter::MainGameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int health, int mana, std::vector<Item*> items, unsigned int lvl)
	:GameCharacter(name,race,characterClass,stats,alignment,health,mana,items,lvl)
{}

int MainGameCharacter::getExp()
{
	return exp;
}

void MainGameCharacter::increaseExp(int exp)
{
	if (exp < 0) throw std::invalid_argument("Exp musi byc liczba dodatnia");
	this->exp += exp;
}

void MainGameCharacter::increaseExpCap()
{
	nextLvl += 50;
}

bool MainGameCharacter::run()
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

int MainGameCharacter::attack()
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
		damage += (getStats().getDexterity() + addModifiers(buffs.dexterityBuffs)/2.0);
	}
	
	return damage;
}

void MainGameCharacter::defend()
{
	Effect defend("Defending", EffectType::Defending, 3, 3);
	addEffect(&defend);
}

void MainGameCharacter::useItem()
{
	if (getItems().size() <= 0)
		std::cout << "Nie masz zadnych przedmiotow!\n";
	else
	{
		int choice;
		std::cout << "Z jakiego przedmiotu w plecaku chcialbys skorzystac?\n";
		for(int i = 0; i < getItems().size(); i++)
		{
			std::cout << i+1 << ". " << getItems()[i]->getName() << std::endl;
		}

		do
		{
			std::cin >> choice;
			if (choice > getItems().size() || choice < 1)
				std::cout << "Wybierz poprawny przedmiot!(1-" << getItems().size() << ")\n";
		} while (choice < 1 || choice > getItems().size());

		Item* item = getItems().at(choice-1);

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

void MainGameCharacter::levelUp()
{
	int wybor, lvl = getLvl();
	setLvl(lvl++);

	std::cout << "Zdobyles nowy poziom " + getClass().getName() + "!\n";
	std::cout << "Twoje statystki rosna:\n";

	if (getClass().getName() == "Wojownik")
	{
		int str = getStats().getStrength();
		int con = getStats().getConsitution();
		int cha = getStats().getCharisma();
		std::cout << "Twoja sila wzrasta! " + std::to_string(str) + " ---> " + std::to_string((str + 2)) + '\n';
		std::cout << "Twoja wytrzymalosc wzrasta! " + std::to_string(con) + " ---> " + std::to_string((con + 1)) + '\n';
		std::cout << "Twoja charyzma wzrasta! " + std::to_string(cha) + " ---> " + std::to_string((cha + 1)) + '\n';
		getStats().setStrength(str + 2);
		getStats().setConsitution(con + 1);
		getStats().setCharisma(cha + 1);
	}
	else if (getClass().getName() == "Czarodziej")
	{
		int int_ = getStats().getIntelligence();
		int wis = getStats().getWisdom();
		int cha = getStats().getCharisma();
		std::cout << "Twoja inteligencja wzrasta! " + std::to_string(int_) + " ---> " + std::to_string((int_ + 2)) + '\n';
		std::cout << "Twoja madrosc wzrasta! " + std::to_string(wis) + " ---> " + std::to_string((wis + 1)) + '\n';
		std::cout << "Twoja charyzma wzrasta! " + std::to_string(cha) + " ---> " + std::to_string((cha + 1)) + '\n';
		getStats().setIntelligence(int_ + 2);
		getStats().setWisdom(wis + 1);
		getStats().setCharisma(cha + 1);
	}
	else if (getClass().getName() == "Lotrzyk")
	{
		int dex = getStats().getDexterity();
		int int_ = getStats().getIntelligence();
		int con = getStats().getConsitution();
		std::cout << "Twoja zwinnosc wzrasta! " + std::to_string(dex) + " ---> " + std::to_string((dex + 2)) + '\n';
		std::cout << "Twoja inteligencja wzrasta! " + std::to_string(int_) + " ---> " + std::to_string((int_ + 1)) + '\n';
		std::cout << "Twoja wytrzymalosc wzrasta! " + std::to_string(con) + " ---> " + std::to_string((con + 1)) + '\n';
		getStats().setDexterity(dex + 2);
		getStats().setConsitution(con + 1);
		getStats().setIntelligence(int_ + 1);
	}

	std::cout << "Wybierz nowa zdolnosc do nauki:\n" << getClass().getAbilities();

	std::cin >> wybor;

	std::cout << "Odblokowano nowa zdolnosc: " << getClass().getAbility(wybor)->getName();
	getClass().getAbility(wybor)->unlockAbility();
	increaseExpCap();
}
