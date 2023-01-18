#pragma once
#include <map>
#include <string>
#include <vector>

#include "Armor.h"
#include "GameCharacterClass.h"
#include "IActions.h"
#include "Item.h"
#include "Statistics.h"
#include "Parameters.h"
#include "Weapon.h"

struct StatBuffs
{
	std::map<EffectType, int> strengthBuffs;
	std::map<EffectType, int> dexterityBuffs;
	std::map<EffectType, int> consitutionBuffs;
	std::map<EffectType, int> intelligenceBuffs;
	std::map<EffectType, int> wisdomBuffs;
	std::map<EffectType, int> charismaBuffs;
};

class GameCharacter : public IActions
{
	std::string name;
	GameCharacterRace race;
	GameCharacterClass characterClass;
	Statistics stats;
	Alignment alignment;
	int gold=0;
	int hp;
	int mp;
	int initiative;
	int defense;
	std::vector<Effect*> effects;
	std::vector<Item*> items;
	unsigned int lvl;
	bool consciousness = true;

protected:
	GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl);
	StatBuffs buffs;
	Weapon* weapon = nullptr;
	Armor* armor = nullptr;

public:
	void deleteItem(int i);
	void setHp(int hp);
	void setMp(int mp);
	void setLvl(unsigned int lvl);
	void setInitiative(int initiative);
	void setDefense(int defense);
	int getGold();
	void setGold(int gold);
	std::string getName();
	int getHp();
	int getMp();
	int getDefense();
	Statistics getStats();
	int getInitiative();
	unsigned int getLvl();
	GameCharacterClass getClass();
	std::vector<Effect*> getEffects();
	std::vector<Item*> getItems();
	bool isNumber(std::string& s);
	int forceNumberInput(std::string& answer);
	void equipWeapon(Weapon weapon);
	void equipArmor(Armor armor);
	void takeDamage(EffectType effectType,int dmg);
	bool useMP(int mpCost);
	void addEffect(Effect* effect);
	int addModifiers(std::map<EffectType, int> buffs_);
	void addItem(Item* item);
	void effectsInfluence();

	virtual ~GameCharacter() {}
};

