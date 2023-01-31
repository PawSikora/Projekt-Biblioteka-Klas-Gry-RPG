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

	std::map<EffectType, int> defenseBuffs;
	std::map<EffectType, int> fireResistanceBuffs;
	std::map<EffectType, int> coldResistanceBuffs;
	std::map<EffectType, int> poisonResistanceBuffs;
	std::map<EffectType, int> magicResistanceBuffs;
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
	std::vector<Effect> effects;
	std::vector<Item*> items;
	unsigned int lvl;
	bool consciousness = true;

protected:
	GameCharacter(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, Alignment alignment, int hp, int mp, std::vector<Item*> items, unsigned int lvl);
	StatBuffs buffs;
	Weapon* weapon = nullptr;
	Armor* armor = nullptr;

public:
	bool getConsciousness() const;
	void deleteItem(int i);

	void setHp(int hp);
	void setMp(int mp);
	void setLvl(unsigned int lvl);
	void setInitiative(int initiative);
	void setDefense(int defense);
	void setGold(int gold);

	int getGold() const;
	std::string getName();
	int getHp() const;
	int getMp() const;
	int getDefense();
	Statistics& getStats();
	int getInitiative();
	unsigned int getLvl() const;
	GameCharacterClass& getClass();
	std::vector<Effect>& getEffects();
	std::vector<Item*>& getItems();

	void equipWeapon(Weapon* weapon);
	void unequipWeapon();
	void equipArmor(Armor* armor);
	void unequipArmor();
	int takeDamage(Effect& effectType,int dmg);
	bool useMP(int mpCost);
	void addEffect(Effect& effect);
	int addModifiers(std::map<EffectType, int> buffs_);
	void addItem(Item* item);
	void effectsInfluence();

	virtual ~GameCharacter() {}
};

