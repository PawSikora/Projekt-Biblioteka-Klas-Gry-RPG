#include "GameCharacter.h"
#include <cmath>
#include <iostream>

#include <stdexcept>

#include "Consumables.h"

bool GameCharacter::isNumber(std::string& s)
{
	return s.find_first_not_of("0123456789-+") == std::string::npos;
}

int GameCharacter::forceNumberInput(std::string& answer)
{

	while (!isNumber(answer))
	{
		std::cout << "Prosze wprowadzic numer" << std::endl;
		std::cin >> answer;

	}
	int result = std::stoi(answer);
	return result;
}



GameCharacter::GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl)
	:name(name),race(race),characterClass(characterClass), stats(stats), alignment(alignment), items(items)
{
	setHp(hp);
	setMp(mp);
	setLvl(lvl);

	for (auto item : items)
	{
		if (dynamic_cast<Weapon*>(item))
			equipWeapon(dynamic_cast<Weapon*>(item));
		if (dynamic_cast<Armor*>(item))
			equipArmor(dynamic_cast<Armor*>(item));
	}

	if (getClass().getClassType() == ClassType::Warrior)
	{
		setInitiative(4);
		setDefense(3 + getStats().getDexterity() / 2.0);
	}
	else if (getClass().getClassType() == ClassType::Mage)
	{
		setInitiative(3);
		setDefense(1 + getStats().getDexterity() / 2.0);
	}
	else if (getClass().getClassType() == ClassType::Rogue)
	{
		setInitiative(5);
		setDefense(5 + getStats().getDexterity() / 2.0);
	}
}

int GameCharacter::getHp()
{
	return hp;
}

int GameCharacter::getMp()
{
	return mp;
}

int GameCharacter::getDefense()
{
	int def = defense + addModifiers(buffs.defenseBuffs);

	if(armor != nullptr)
		return def + armor->getDefense();
	return def;
}

Statistics& GameCharacter::getStats()
{
	return stats;
}

unsigned int GameCharacter::getLvl()
{
	return lvl;
}

int GameCharacter::getInitiative()
{
	return initiative + std::floor(getStats().getDexterity()/2.0);
}


void GameCharacter::setGold(int gold)
{
	if (gold < 0) throw std::invalid_argument("Posiadane zloto nie moze byc ujemne");
	this->gold = gold;
}

std::string GameCharacter::getName()
{
	return name;
}

GameCharacterClass GameCharacter::getClass()
{
	return characterClass;
}

std::vector<Effect*>& GameCharacter::getEffects()
{
	return effects;
}

std::vector<Item*>& GameCharacter::getItems()
{
	return items;
}

bool GameCharacter::getConsciousness()
{
	return consciousness;
}

void GameCharacter::deleteItem(int i)
{
	if(items.size() > 0)
		items.erase(items.begin() + i);
}

void GameCharacter::setHp(int hp)
{
	if (hp <= 0)
	{
		this->hp = 0;
		consciousness = false;
	}
	else	
		this->hp = hp;
}

void GameCharacter::setMp(int mp)
{
	if (mp < 0) throw std::invalid_argument("Mp musi byc liczba dodatnia");
	this->mp = mp;
}

void GameCharacter::setInitiative(int initiative)
{
	this->initiative = initiative;
}

void GameCharacter::setDefense(int defense)
{
	if (defense < 0) throw std::invalid_argument("Obrona musi byc liczba dodatnia");
	this->defense = defense;
}

int GameCharacter::getGold()
{
	return gold;
}

void GameCharacter::setLvl(unsigned int lvl)
{
	this->lvl = lvl;
}

void GameCharacter::equipWeapon(Weapon* weapon)
{
	this->weapon = weapon;
	this->weapon->equipWeapon();
}

void GameCharacter::equipArmor(Armor* armor)
{
	this->armor = armor;
	this->armor->equipArmor();
}

void GameCharacter::takeDamage(EffectType effectType, int dmg)
{
	int dmgDealt = 0;
	if(armor != nullptr && armor->isEquipped())
	{
		switch (effectType)
		{
			case EffectType::Bleeding:
			{
				dmgDealt = dmg - armor->getResistances().getBleedResistance();
				break;
			}
			case EffectType::Burning:
			{
				dmgDealt = dmg - armor->getResistances().getFireResistance() - addModifiers(buffs.fireResistanceBuffs);
				break;
			}
			case EffectType::Poisoning:
			{
				dmgDealt = dmg - armor->getResistances().getPoisonResistance() - addModifiers(buffs.poisonResistanceBuffs);
				break;
			}
			case EffectType::MagicDmg:
			{
				dmgDealt = dmg - armor->getResistances().getMagicResistance() - addModifiers(buffs.magicResistanceBuffs);
				break;
			}
			case EffectType::Freezing:
			{
				dmgDealt = dmg - armor->getResistances().getColdResistance() - addModifiers(buffs.coldResistanceBuffs);
				break;
			}
		}
	}

	if(effectType == EffectType::PhysicalDmg)
		dmgDealt = dmg - getDefense();

	dmgDealt = dmgDealt > 0 ? dmgDealt : 5;
	setHp(hp - dmgDealt);
}

bool GameCharacter::useMP(int mpCost)
{
	return  mp > mpCost;
}

void GameCharacter::addEffect(Effect* effect)
{
	bool effectAlreadyAdded = false;

	for (auto eff : effects) {
		if (eff->getType() == effect->getType()) {
			effectAlreadyAdded = true;
		}
	}

	if(!effectAlreadyAdded)
		effects.push_back(effect);
}

int GameCharacter::addModifiers(std::map<EffectType, int> buffs_)
{
	int modifier = 0;
	for (auto buff : buffs_)
	{
		modifier += buff.second;
	}
	return modifier;
}

void GameCharacter::addItem(Item* item)
{
	if(item != nullptr)
		items.push_back(item);
}

void GameCharacter::effectsInfluence()
{
	for (auto effect : effects)
	{
		switch (effect->getType())
		{
		case EffectType::Bleeding:
			takeDamage(EffectType::Bleeding,4);
			buffs.strengthBuffs.insert({effect->getType(), effect->getEffect()});
			buffs.consitutionBuffs.insert({ effect->getType(), effect->getEffect() });
			std::cout << this->getName() << " cierpi z powodu krwawienia! Traci " << -4 << "hp! I otrzymje kare do sily oraz wytrzymalosci!\n\n";
			break;

		case  EffectType::Poisoning:
			takeDamage(EffectType::Poisoning,5);
			buffs.strengthBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.consitutionBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.intelligenceBuffs.insert({effect->getType(), effect->getEffect()});
			std::cout << this->getName() << " cierpi z powodu zatrucia! Traci " << -5 << "hp! I otrzymje kare do sily, wytrzymalosci oraz inteligencji!\n\n";
			break;

		case  EffectType::Healing:
			hp += effect->getEffect();
			std::cout << this->getName() << " odzysukuje " << effect->getEffect() << "hp!\n\n";
			break;

		case EffectType::Defending:
			
			buffs.defenseBuffs.insert({ effect->getType(), effect->getEffect() });
			std::cout << this->getName() << " zyskuje bonus +" << effect->getEffect() << " do obrony dzieki swojej postawie!\n\n";
			break;

		case EffectType::Burning:
			takeDamage(EffectType::Burning,5);
			buffs.intelligenceBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.wisdomBuffs.insert({ effect->getType(), effect->getEffect() });
			std::cout << this->getName() << " cierpi z powodu podpalenia! Traci " << -5 << "hp! I otrzymje kare do inteligencji oraz madrosci!\n\n";
			break;

		case EffectType::Shocked:
			takeDamage(EffectType::MagicDmg,3);
			buffs.dexterityBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.wisdomBuffs.insert({ effect->getType(), effect->getEffect() });
			std::cout << this->getName() << " cierpi z powodu porazenia! Traci " << -3 << "hp! I otrzymje kare do zrecznosci oraz madrosci!\n\n";
			break;

		case EffectType::Freezing:
			takeDamage(EffectType::Freezing,3);
			buffs.strengthBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.dexterityBuffs.insert({ effect->getType(), effect->getEffect() });
			std::cout << this->getName() << " cierpi z powodu zamrozenia! Traci " << -3 << "hp! I otrzymje kare do sily oraz zrecznosci!\n\n";
			break;

		case EffectType::FireResistBoost:
			buffs.fireResistanceBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::ColdResistBoost:
			buffs.coldResistanceBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::PoisonResistBoost:
			buffs.poisonResistanceBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::MagicResistBoost:
			buffs.magicResistanceBuffs.insert({ effect->getType(), effect->getEffect() });
			break;
		}

		if(effect->passTime())
		{
			buffs.strengthBuffs.erase(effect->getType());
			buffs.dexterityBuffs.erase(effect->getType());
			buffs.consitutionBuffs.erase(effect->getType());
			buffs.intelligenceBuffs.erase(effect->getType());
			buffs.wisdomBuffs.erase(effect->getType());
			buffs.charismaBuffs.erase(effect->getType());

			buffs.defenseBuffs.erase(effect->getType());
			buffs.fireResistanceBuffs.erase(effect->getType());
			buffs.coldResistanceBuffs.erase(effect->getType());
			buffs.poisonResistanceBuffs.erase(effect->getType());
			buffs.magicResistanceBuffs.erase(effect->getType());

			
			int i = 0;
			bool effectAlreadyAdded = false;

			for (auto eff : effects) {
				if (eff->getType() == effect->getType()) {
					effectAlreadyAdded = true;
				}
				else 
					i++;
			}


			if (effectAlreadyAdded)
			{
				delete effects.at(i);
				effects.erase(effects.begin()+i);
			}
				
		}
	}
}
