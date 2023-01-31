#include "CharacterDesigner.h"

GameCharacterRace CharacterDesigner::raceChoice()
{
	std::cout << " Oto rasy do wyboru" << '\n';
	std::cout << "1 Czlowiek (  )" << '\n';
	std::cout << "2 Elf (+1 wisdom, +1 intelligence, +1 dexterity ,-2 consitution ,-1 strength" << '\n';
	std::cout << "3 Krasnolud(+1 strength, +3 consitution, +1 charisma, -3 dexterity, -2 wisdom " << '\n';
	std::cout << "4 Ork ( +5 strength, +3 consitution, -4 intelligence,-3 charisma, -2 wisdom  " << '\n';
	
	switch (selectNumber(1,4))
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
	

	//Wojownik
	Ability* whirl = new Ability("Mlynek", AbilityType::Offensive, 65, Effect("Bleeding", EffectType::Bleeding, 1, 1));
	Ability* rend = new Ability("Silne ciecie", AbilityType::Offensive, 80, Effect("Physical DMG", EffectType::PhysicalDmg, 1, 1));
	std::vector<Ability*> warriorAbilities = { whirl, rend };
	GameCharacterClass warrior(ClassType::Warrior, warriorAbilities);

	//Mag
	Ability* fireball = new Ability("Kula ognia", AbilityType::Offensive, 60, Effect("Burning", EffectType::Burning, 5, 4));
	Ability* lightning = new Ability("Blyskawica", AbilityType::Offensive, 45, Effect("Shock", EffectType::Shocked, 4, 3));
	std::vector<Ability*> mageAbilities = { fireball, lightning };
	GameCharacterClass mage(ClassType::Mage, mageAbilities);

	//£otrzyk
	Ability* backstab = new Ability("Cios w plecy", AbilityType::Offensive, 1000, Effect("Bleed", EffectType::Bleeding, 2, 5));
	Ability* poisonBlade = new Ability("Zatrute ostrze", AbilityType::Offensive, 60, Effect("Poison", EffectType::Poisoning, 4, 6));
	std::vector<Ability*> rogueAbilities = { backstab, poisonBlade };
	GameCharacterClass rogue(ClassType::Rogue, rogueAbilities);


	system("cls");
	std::cout << " Teraz wybierz klase " << '\n';
	std::cout << "1 Wojownik ( +2 sila )" << '\n';
	std::cout << "2 Mage (+3 wisdom, +3 intelligence, -2 dexterity ,-2 consitution ,-3 strength" << '\n';
	std::cout << "3 Rogue(+3 charisma, +3 dexterity, -1 strength, -1 consitution,  -1 wisdom, -1 intelligence " << '\n';

	switch (selectNumber(1, 3))
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

	std::cout << " Teraz wybierz Strone " << '\n';
	std::cout << "1 Zlo" << '\n';
	std::cout << "2 Neutralny" << '\n';
	std::cout << "3 Dobro " << '\n';
	switch (selectNumber(1, 3))
	{
	case 1:
		return Alignment::Evil;
	case 2:
		return Alignment::Neutral;
	case 3:
		return Alignment::Evil;
	}
}

void CharacterDesigner::statsDistribution(MainGameCharacter& character_t ) const
{
	
	int strength=10;
	int dexterity=10;
	int constitution=10;
	int intelligence=10;
	int wisdom=10;
	int charisma=10;
	character_t.getStats().setCharisma(charisma);
	character_t.getStats().setConsitution(constitution);
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
		constitution -= 2;
		strength -= 3;

	}
	else {
		charisma += 3;
		dexterity += 3;
		strength -= 1;
		constitution -= 1;
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
		constitution -= 2;
		strength -= 1;
		break;
	case GameCharacterRace::Dwarf:
		wisdom -=2;
		dexterity -= 3;
		constitution += 3;
		strength += 1;
		charisma += 1;
		break;
	case GameCharacterRace::Orc: 
		strength += 5;
		constitution += 3;
		intelligence -= 4;
		charisma -= 3;
		wisdom -= 2;
		break;

	}
	for (size_t i = 6; i > 0; i--)
	{
		system("cls");
		std::cout << "Masz do rozdania " << i << " punktow" <<" (Wpisz numer przy punkcie aby dodac 1 (UWAGA ZMIAN NIE MOZNA COFNAC!)" << '\n';
		std::cout << "1 Sila :" << strength << '\n';
		std::cout << "2 Zrecznosc :" << dexterity << '\n';
		std::cout << "3 Wytrzymalosc :" << constitution << '\n';
		std::cout << "4 Intelekt :" << intelligence << '\n';
		std::cout << "5 Madrosc :" << wisdom << '\n';
		std::cout << "6 Charyzma :" << charisma << '\n';

		switch (selectNumber(1, 6))
		{
		case 1:
			strength++;
			break;
		case 2:
			dexterity++;
			break;
		case 3:
			constitution++;
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
	character_t.getStats().setConsitution(constitution);
	character_t.getStats().setDexterity(dexterity);
	character_t.getStats().setStrength(strength);
	character_t.getStats().setIntelligence(intelligence);
	character_t.getStats().setWisdom(wisdom);
	character_t.setHp(character_t.getStats().getConsitution() * 2);
	character_t.setMp(character_t.getStats().getWisdom() * 2);


}

MainGameCharacter CharacterDesigner::createCharacter()
{
	//Przedmioty Wojownika
	Item* weaponWarrior = new Weapon("Miecz templariusza", 220, 16, 5);
	Item* armorWarrior = new Armor("Zbroja templariusza", 450, 5, 3, Resistances(10, 10, 10, 10, 15));

	//Przedmioty Maga
	Item* weaponMage = new Weapon("Mrozna laska", 150, 15, 20);
	Item* armorMage = new Armor("Szaty efliego maga", 50, 2, 0, Resistances(5, 5, 5, 20, 15));

	//Przedmioty £otrzyka
	Item* weaponRogue = new Weapon("Sztylety skrytobojcy", 120, 12, 15);
	Item* armorRogue = new Armor("Plaszcz lotrzyka", 120, 3, 1, Resistances(5, 5, 5, 5, 15));

	std::string name_t;
	std::cout << "Jak sie nazywasz" << '\n';
	std::cin >> name_t;
	Alignment all_t = alignmentChoice();
	GameCharacterRace race_t = raceChoice();
	GameCharacterClass class_t = classChoice();

	MainGameCharacter player_t =  MainGameCharacter(name_t, race_t, class_t,
		Statistics(10, 10, 10, 10, 10, 10), all_t, 3, 3,
		{}, 1);
	statsDistribution(player_t);
	switch (player_t.getClass().getClassType())
	{
	case ClassType::Mage:
		player_t.addItem(weaponMage);
		player_t.addItem(armorMage);
		break;
	case ClassType::Rogue:
		player_t.addItem(weaponRogue);
		player_t.addItem(armorRogue);
		break;
	case ClassType::Warrior:
		player_t.addItem(weaponWarrior);
		player_t.addItem(armorWarrior);
		break;

	}

	return player_t;
}

