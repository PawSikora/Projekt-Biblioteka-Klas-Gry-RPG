#include "CharacterDesigner.h"


bool CharacterDesigner::isNumber(std::string& s)
{
	
		return s.find_first_not_of("0123456789-+") == std::string::npos;
	

}

int CharacterDesigner::forceNumberInput(std::string& answer)
{


		while (!isNumber(answer))
		{
			std::cout << "Prosze wprowadzic numer" << std::endl;
			std::cin >> answer;

		}
		int resoult = std::stoi(answer);
		return resoult;
	
}

GameCharacterRace CharacterDesigner::raceChoice()
{
	std::string temp = " ";
	std::cout << " Oto rasy do wyboru" << '\n';
	std::cout << "1 Czlowiek (  )" << '\n';
	std::cout << "2 Elf (+1 wisdom, +1 intelligence, +1 dexterity ,-2 consitution ,-1 strength" << '\n';
	std::cout << "3 Krasnolud(+1 strength, +3 consitution, +1 charisma, -3 dexterity, -2 wisdom " << '\n';
	std::cout << "4 Ork ( +5 strength, +3 consitution, -4 intelligence,-3 charisma, -2 wisdom  " << '\n';
	
	switch (forceNumberInput(temp))
	{
	case 1:
		race = GameCharacterRace::Human;
		return GameCharacterRace::Human;
	case 2:
		race = GameCharacterRace::Elf;
		return GameCharacterRace::Elf;
	case 3:
		race = GameCharacterRace::Dwarf;
		return GameCharacterRace::Dwarf;
	case 4:
		race = GameCharacterRace::Orc;
		return GameCharacterRace::Orc;

	}

	


}

GameCharacterClass CharacterDesigner::classChoice()
{
	

	std::string temp = " ";
	system("cls");
	std::cout << " Teraz wybierz klase " << '\n';
	std::cout << "1 Wojownik ( +2 sila )" << '\n';
	std::cout << "2 Mage (+3 wisdom, +3 intelligence, -2 dexterity ,-2 consitution ,-3 strength" << '\n';
	std::cout << "3 Rogue(+3 charisma, +3 dexterity, -1 strength, -1 consitution,  -1 wisdom, -1 intelligence " << '\n';

	GameCharacterClass warrior(ClassType::Warrior, { new Ability("Whirl", AbilityType::Offensive, 550, Effect("None", EffectType::None, 0, 0)), new Ability("Rend", AbilityType::Offensive, 1100, Effect("None", EffectType::None, 0, 0)) });

	GameCharacterClass mage(ClassType::Mage, { new Ability("Fireball", AbilityType::Offensive, 340, Effect("Burning", EffectType::Burning, 5, 4)), new Ability("Lightning", AbilityType::Offensive, 310, Effect("Shock", EffectType::Shocked, 4, 3)) });

	GameCharacterClass rogue(ClassType::Rogue, { new Ability("Backstab", AbilityType::Offensive, 1000, Effect("Bleed", EffectType::Bleeding, 2, 5)), new Ability("Poison Blade", AbilityType::Offensive, 700, Effect("Poison", EffectType::PoisonResistBoost, 4, 6)) });
	switch (forceNumberInput(temp))
	{
	case 1:
		return warrior;
	case 2:
		return mage;
	case 3:
		return rogue;
		default:
			return rogue;
	}



}

Alignment CharacterDesigner::alignmentChoice()
{
	std::string temp=" ";
	//system("cls");
	std::cout << " Teraz wybierz Strone " << '\n';
	std::cout << "1 Zlo" << '\n';
	std::cout << "2 Neutralny" << '\n';
	std::cout << "3 Dobro " << '\n';
	switch (forceNumberInput(temp))
	{
	case 1:
		return Alignment::Evil;
	case 2:
		return Alignment::Neutral;
	case 3:
		return Alignment::Evil;
	}
}

void CharacterDesigner::statsDistribution(MainGameCharacter& character_t )
{
	
	int strength=10;
	int dexterity=10;
	int consitution=10;
	int intelligence=10;
	int wisdom=10;
	int charisma=10;
	character_t.getStats().setCharisma(charisma);
	character_t.getStats().setConsitution(consitution);
	character_t.getStats().setDexterity(dexterity);
	character_t.getStats().setStrength(strength);
	character_t.getStats().setIntelligence(intelligence);
	character_t.getStats().setWisdom(wisdom);

	if (character_t.getClass().getName().find("Warrior") == 0) {
		strength += 2;
		
	}

	else if (character_t.getClass().getName().find("Mage") == 0) {
		wisdom += 3;
		intelligence += 3;
		dexterity -= 2;
		consitution -= 2;
		strength -= 3;

	}
	else {
		charisma += 3;
		dexterity += 3;
		strength -= 1;
		consitution -= 1;
		intelligence -= 1;
		wisdom -= 1;
	}

	switch (race)
	{
	case GameCharacterRace::Human:

		break;

	case GameCharacterRace::Elf:
		wisdom += 1;
		intelligence =+ 1;
		dexterity =+ 1;
		consitution -= 2;
		strength -= 1;
		break;
	case GameCharacterRace::Dwarf:
		wisdom -=2;
		dexterity -= 3;
		consitution += 3;
		strength += 1;
		charisma += 1;
		break;
	case GameCharacterRace::Orc: 
		strength += 5;
		consitution += 3;
		intelligence -= 4;
		charisma -= 3;
		wisdom -= 2;
		break;

	}
	std::string temp = " ";
	for (size_t i = 6; i > 0; i--)
	{
		system("cls");
		std::cout << "Masz do rozdania " << i << " punktow" <<" (Wpisz numer przy punkcie aby dodac 1 (UWAGA ZMIAN NIE MOZNA COFNAC!)" << '\n';
		std::cout << "1 Sila :" << strength << '\n';
		std::cout << "2 Zrecznosc :" << dexterity << '\n';
		std::cout << "3 Wytrzymalosc :" << consitution << '\n';
		std::cout << "4 Intelekt :" << intelligence << '\n';
		std::cout << "5 Madrosc :" << wisdom << '\n';
		std::cout << "6 Charyzma :" << charisma << '\n';
		std::cin >> temp;
		switch (forceNumberInput(temp))
		{
		case 1:
			strength++;
			break;
		case 2:
			dexterity++;
			break;
		case 3:
			consitution++;
			break;
		case 4:
			intelligence++;
			break;
		case 5:
			wisdom++;
			break;

		case 6:
			charisma++;
			break;
		}


	}
	
	character_t.getStats().setCharisma(charisma);
	character_t.getStats().setConsitution(consitution);
	character_t.getStats().setDexterity(dexterity);
	character_t.getStats().setStrength(strength);
	character_t.getStats().setIntelligence(intelligence);
	character_t.getStats().setWisdom(wisdom);
	character_t.setHp(character_t.getStats().getConsitution() * 2);
	character_t.setMp(character_t.getStats().getWisdom() * 2);

	std::cout << character_t.getMp();
	std::cout << character_t.getHp();
	std::cout << character_t.getStats().getCharisma();
	std::cout << character_t.getStats().getConsitution();
	std::cout << character_t.getStats().getDexterity();
	std::cout << character_t.getStats().getIntelligence();
	std::cout << character_t.getStats().getStrength();
	std::cout << character_t.getStats().getWisdom();

}

