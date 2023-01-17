#include "GameCharacter.h"
#include <cmath>

#include <stdexcept>

GameCharacter::GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl)
	:name(name),race(race),characterClass(characterClass), stats(stats), alignment(alignment), items(items)
{
	setHp(hp);
	setMp(mp);
	setLvl(lvl);

	if (getClass().getName() == "Wojownik")
	{
		setInitiative(4);
	}
	else if (getClass().getName() == "Czarodziej")
	{
		setInitiative(3);
	}
	else if (getClass().getName() == "Lotrzyk")
	{
		setInitiative(5);
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
	return defense + armor->getDefense();
}

Statistics GameCharacter::getStats()
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

std::vector<Effect*> GameCharacter::getEffects()
{
	return effects;
}

std::vector<Item*> GameCharacter::getItems()
{
	return items;
}

void GameCharacter::deleteItem(int i)
{
	items.erase(items.begin() + i);
}

void GameCharacter::setHp(int hp)
{
	if (hp < 0) throw std::invalid_argument("Hp musi byc liczba dodatnia");
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

int GameCharacter::getGold()
{
	return gold;
}

void GameCharacter::setLvl(unsigned int lvl)
{
	if (lvl < 0) throw std::invalid_argument("Lvl musi byc liczba dodatnia");
	this->lvl = lvl;
}

void GameCharacter::equipWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

void GameCharacter::equipArmor(Armor armor)
{
	this->armor = &armor;
}

void GameCharacter::takeDamage(int dmg)
{
	if (hp > dmg)
		setHp(hp - dmg);
}

bool GameCharacter::useMP(int mpCost)
{
	return  mp > mpCost;
}

void GameCharacter::addEffect(Effect* effect)
{
	if (!(std::find(effects.begin(), effects.end(), effect) != effects.end()))
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
	items.push_back(item);
}

void GameCharacter::effectsInfluence()
{
	for (auto effect : effects)
	{
		switch (effect->getType())
		{
		case EffectType::Bleeding:
			takeDamage(4);
			buffs.strengthBuffs.insert({effect->getType(), effect->getEffect()});
			buffs.consitutionBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case  EffectType::Poisoning:
			takeDamage(5);
			buffs.strengthBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.consitutionBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.intelligenceBuffs.insert({effect->getType(), effect->getEffect()});
			break;

		case  EffectType::Healing:
			//int heal = hp * 0.3;
			hp += effect->getEffect();
			break;

		case EffectType::Defending:
			defense += effect->getEffect();
			break;

		case EffectType::Burning:
			takeDamage(5);
			buffs.intelligenceBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.wisdomBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::Shocked:
			takeDamage(3);
			buffs.dexterityBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.wisdomBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::Freezing:
			takeDamage(4);
			buffs.strengthBuffs.insert({ effect->getType(), effect->getEffect() });
			buffs.dexterityBuffs.insert({ effect->getType(), effect->getEffect() });
			break;

		case EffectType::FireResistBoost:
			//Jakos z resistem z armoru polaczyc
			break;

		case EffectType::ColdResistBoost:
			//Jakos z resistem z armoru polaczyc
			break;

		case EffectType::PoisonResistBoost:
			//Jakos z resistem z armoru polaczyc
			break;

		case EffectType::MagicResistBoost:
			//Jakos z resistem z armoru polaczyc
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
			if (effect->getType() == EffectType::Defending)
				defense -= 3;
			//effects.erase(std::remove(effects.begin(), effects.end(), effect->getType()), effects.end());
		}
	}
}
