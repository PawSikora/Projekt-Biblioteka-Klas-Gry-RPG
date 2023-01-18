#pragma once
enum class DangerLvL
{
	Boss,
	Very_dangerous,
	Dangerous,
	Medium,
	Easy,
	Begginer

};
enum class Role
{
	ArmorSmith,
	WeponSmith,
	PotionSeller,
	MiscSeller,
	SpellSeller,
	InnKeeper,
};
enum class GameCharacterRace
{
	Human,
	Elf,
	Dwarf,
	Orc,
};

enum class ClassType
{
	Warrior,
	Mage,
	Rogue,
};

enum class Alignment
{
	Good,
	Neutral,
	Evil,
};

enum class AbilityType //Offensive itp czy Physical, magical itp
{
	Offensive,
	Defensive,
	Supportive,
};

enum class EffectType
{
	Bleeding,
	Poisoning,
	Healing,
	Defending,
	Burning,
	Shocked,
	Freezing,
	PhysicalDmg,
	MagicDmg,
	FireResistBoost,
	ColdResistBoost,
	PoisonResistBoost,
	MagicResistBoost,
	None
};