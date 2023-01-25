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
	if (!choice.find('t'))
	{
		escaped = true;
		return true;
	}
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
	addEffect(new Effect("Defending", EffectType::Defending, 3, 3));
}

void MainGameCharacter::useItem()
{
	if (getItems().size() <= 0)
		std::cout << "Nie masz zadnych przedmiotow!\n";
	else
	{
		std::string answer;
		int choice;
		std::cout << "Z jakiego przedmiotu w plecaku chcialbys skorzystac?\n";
		for(int i = 0; i < getItems().size(); i++)
		{
			std::cout << i+1 << ". " << getItems()[i]->getName() << std::endl;
		}

		choice = selectNumber(1, getItems().size());

		Item* item = getItems().at(choice-1);

		if (dynamic_cast<Consumables*>(item))
		{
			Consumables* item_ = dynamic_cast<Consumables*>(item);
			if (item_->getEffect() != nullptr && item_->getUsed() == false)
			{
				addEffect(item_->getEffect());
				std::cout << this->getName() << " uzywa " << item_->getName() << " nakladajac na siebie efekt: " << enumEffectConversion(item_->getEffect()->getType()) << " +" << std::to_string(item_->getEffect()->getEffect()) << std::endl;

				item_->useItem();
				getItems().erase(getItems().begin() + choice - 1);
			}
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

void MainGameCharacter::levelUp()
{
	int wybor, lvl = getLvl();
	setLvl(lvl++);

	std::cout << "Zdobyles nowy poziom klasy: " + getClass().getName() + "!\n";
	std::cout << "Twoje statystki rosna:\n\n";

	if (getClass().getClassType() == ClassType::Warrior)
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
	else if (getClass().getClassType() == ClassType::Mage)
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
	else if (getClass().getClassType() == ClassType::Rogue)
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
	std::cout << std::endl;
	if(getClass().getNumOfAvailableAbilities() > 0)
	{
		std::cout << "Wybierz nowa zdolnosc do nauki:\n" << getClass().getAbilities();

		wybor = selectNumber(1, getClass().getNumOfAvailableAbilities());

		std::cout << "Odblokowano nowa zdolnosc: " << getClass().getAbility(wybor-1)->getName();

		/*Ability* temp = getClass().getAbility(wybor - 1);
		getClass().abilityUnlocked(temp);
		std::cout << "\n\nODBLOKOWANA ZDOLNOSC:\t" << temp->getName();*/
		getClass().abilityUnlocked(getClass().getAbility(wybor - 1)->unlockAbility());
	}
	else
	{
		std::cout << std::endl << getClass().getAbilities() << std::endl << "Brak umiejetnosci do odblokowania!\n\n";
	}
	
	increaseExpCap();
}

bool MainGameCharacter::getEscaped()
{
	return escaped;
}

bool MainGameCharacter::operator==(MainGameCharacter& other)
{
	return this->getName() == other.getName();
}
