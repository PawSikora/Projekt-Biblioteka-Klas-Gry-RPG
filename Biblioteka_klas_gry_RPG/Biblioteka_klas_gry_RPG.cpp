// Biblioteka_klas_gry_RPG.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

//Effect("Bleed", 1, 0)

#include "Encounter.h"
#include "MainGameCharacter.h"
#include "Mob.h"
#include "Weapon.h"

int main()
{
	MainGameCharacter player("Gerwant", GameCharacterRace::Human, 
		GameCharacterClass("Witcher",{new Ability("Whirl",AbilityType::Offensive,691, Effect("Bleed", EffectType::Bleeding, 2, 4))}),
		Statistics(10, 10, 10, 10, 10, 10),
		Alignment::Neutral, 100, 100, {new Weapon("Aerodnight",1000,2107,100)}, 1);

	GameCharacterClass warrior("Warrior", { new Ability("Whirl", AbilityType::Offensive, 550, Effect("None", EffectType::None, 0, 0)), new Ability("Rend", AbilityType::Offensive, 1100, Effect("None", EffectType::None, 0, 0)) });

	GameCharacterClass mage("Mage", { new Ability("Fireball", AbilityType::Offensive, 340, Effect("Burning", EffectType::Burning, 5, 4)), new Ability("Lightning", AbilityType::Offensive, 310, Effect("Shock", EffectType::Shocked, 4, 3)) });

	GameCharacterClass rogue("Rogue", { new Ability("Backstab", AbilityType::Offensive, 1000, Effect("Bleed", EffectType::Bleeding, 2, 5)), new Ability("Poison Blade", AbilityType::Offensive, 700, Effect("Poison", EffectType::PoisonResistBoost, 4, 6)) });

	MainGameCharacter player1("Alistair", GameCharacterRace::Human, warrior, Statistics(14, 10, 12, 10, 10, 12), Alignment::Good, 120, 0, { new Weapon("Miecz templariusza", 220, 16, 5), new Armor("Zbroja templariusza", 450, 5, 3, Resistances(10, 10, 10, 10)) }, 1);

	MainGameCharacter player2("Solas", GameCharacterRace::Elf, mage, Statistics(10, 10, 10, 16, 12, 12), Alignment::Neutral, 80, 120, { new Weapon("Mrozna laska", 150, 15, 20), new Armor("Szaty efliego maga", 50, 2, 0, Resistances(5, 5, 5, 20)) }, 1);

	MainGameCharacter player3("Varric", GameCharacterRace::Dwarf, rogue, Statistics(10, 16, 12, 14, 10, 10), Alignment::Good, 90, 0, { new Weapon("Sztylet skrytobojcy", 120, 12, 15), new Armor("Plaszcz lotrzyka", 120, 3, 1, Resistances(5, 5, 5, 5)) }, 1);

	std::cout << "Przedmioty bohater " << player1.getName() << std::endl;
	for (auto item : player1.getItems())
	{
		std::cout << item->getName() << std::endl;
	}

	std::cout << "Przedmioty bohater " << player2.getName() << std::endl;
	for (auto item : player2.getItems())
	{
		std::cout << item->getName() << std::endl;
	}

	std::cout << "Przedmioty bohater " << player3.getName() << std::endl;
	for (auto item : player3.getItems())
	{
		std::cout << item->getName() << std::endl;
	}

	Mob CyklopSmokCzarnksiężnika("UluMulu", GameCharacterRace::Orc, warrior, Statistics(20, 8, 14, 4, 4, 0), Alignment::Evil, 250, 0, { new Weapon("Orkowy topor", 300, 30, 10), new Armor("Naramiennik orkow", 50, 1, 0, Resistances(0, 0, 0, 0)) }, 5);

	player1.useItem();

	/*system("cls");
	Encounter labiryntDowna;
	std::vector<MainGameCharacter*> heroes;
	heroes.push_back(&player1);
	heroes.push_back(&player2);
	heroes.push_back(&player3);
	std::vector<Mob*> enemies;
	enemies.push_back(&CyklopSmokCzarnksiężnika);
	labiryntDowna.combat(heroes, enemies);*/
	
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
