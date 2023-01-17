#pragma once
enum class GameCharacterRace
{
	Human,
	Elf,
	Dwarf,
	Orc,
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
	FireResistBoost,
	ColdResistBoost,
	PoisonResistBoost,
	MagicResistBoost,
	None
};