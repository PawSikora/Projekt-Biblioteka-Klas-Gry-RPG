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
	Bleeding = 0,
	Poisoning = 1,
	Healing = 2,
	Defending = 3,
	Burning = 4,
	Shocked = 5,
	Freezing = 6,
	PhysicalDmg,
	MagicDmg,
	FireResistBoost,
	ColdResistBoost,
	PoisonResistBoost,
	MagicResistBoost,
	None
};

std::string enumEffectConversion(EffectType effect);

inline std::string enumEffectConversion(EffectType effect)
{
	{
		std::string effects[] = { "Krwawienie", "Zatrucie", "Leczenie", "Obrona", "Podpalenie", "Porazenie", "Zamrozenie" };
		return effects[(int)effect];
	}
}
