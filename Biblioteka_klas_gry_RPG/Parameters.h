#pragma once
#include <iostream>

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
	PhysicalDmg = 7,
	MagicDmg = 8,
	FireResistBoost = 9,
	ColdResistBoost = 10,
	PoisonResistBoost = 11,
	MagicResistBoost = 12,
	None = 13
};

std::string enumEffectConversion(EffectType effect);
static bool isNumber(std::string& s);
static int forceNumberInput(std::string& answer);
static int selectNumber(int a, int b);

inline std::string enumEffectConversion(EffectType effect)
{
	{
		std::string effects[] = { "Krwawienie", "Zatrucie", "Leczenie", "Obrona", "Podpalenie", "Porazenie", "Zamrozenie", "Obrazenia fizyczne", "Obrazenia magiczne", "Odpornosc na ogien", "Odpornosc na mroz", "Odpornosc na trucizne", "Odpornosc na magie", ""};
		return effects[(int)effect];
	}
}

inline bool isNumber(std::string& s)
{
	return s.find_first_not_of("0123456789-+") == std::string::npos;
}

inline int forceNumberInput(std::string& answer)
{
	while (!isNumber(answer))
	{
		std::cout << "Prosze wprowadzic numer" << std::endl;
		std::cin >> answer;

	}
	int resoult = std::stoi(answer);
	return resoult;

}

inline int selectNumber(int a, int b)
{
	std::string temp;
	std::cin >> temp;
	int temp_int = forceNumberInput(temp);
	while (temp_int > b || temp_int < a)
	{

		std::cout << "Wprowadzono numer z poza zakresu " << '\n';
		std::cin >> temp;
		temp_int = forceNumberInput(temp);
	}
	return temp_int;

}