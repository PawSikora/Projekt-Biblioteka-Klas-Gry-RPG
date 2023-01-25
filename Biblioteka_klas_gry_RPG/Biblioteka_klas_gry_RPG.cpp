// Biblioteka_klas_gry_RPG.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.

#include <iostream>

#include "CharacterDesigner.h"
#include "Consumables.h"
#include "Encounter.h"
#include "Evil_Mob.h"
#include "MainGameCharacter.h"
#include "Mob.h"
#include "NPC.h"
#include "Weapon.h"

#define CombatMechanicTest
//#define TradingMechanicTest

#ifdef CombatMechanicTest
int main()
{
	/*MainGameCharacter player("Gerwant", GameCharacterRace::Human, GameCharacterClass(ClassType::Warrior, { new Ability("Whirl",AbilityType::Offensive,691, Effect("Bleed", EffectType::Bleeding, 2, 4)) }),
		Statistics(10, 10, 10, 10, 10, 10),
		Alignment::Neutral, 100, 100, { new Weapon("Aerodnight",1000,2107,100), new Armor ("Wiedzminski rynsztunek szkoly wilka", 20, 20, 0, Resistances(20, 20, 20, 20, 20))}, 1);*/

	//Wojownik
	Ability* whirl = new Ability("Mlynek", AbilityType::Offensive, 65, Effect("None", EffectType::Bleeding, 0, 0));
	Ability* rend = new Ability("Silne ciecie", AbilityType::Offensive, 80, Effect("None", EffectType::PhysicalDmg, 0, 0));
	std::vector<Ability*> warriorAbilities = { whirl, rend };
	GameCharacterClass warrior(ClassType::Warrior, warriorAbilities);

	//Mag
	Ability* fireball = new Ability("Kula ognia", AbilityType::Offensive, 60, Effect("Burning", EffectType::Burning, 5, 4));
	Ability* lightning = new Ability("Blyskawica", AbilityType::Offensive, 45, Effect("Shock", EffectType::Shocked, 4, 3));
	std::vector<Ability*> mageAbilities = { fireball, lightning };
	GameCharacterClass mage(ClassType::Mage, mageAbilities);

	//Łotrzyk
	Ability* backstab = new Ability("Cios w plecy", AbilityType::Offensive, 1000, Effect("Bleed", EffectType::Bleeding, 2, 5));
	Ability* poisonBlade = new Ability("Zatrute ostrze", AbilityType::Offensive, 60, Effect("Poison", EffectType::Poisoning, 4, 6));
	std::vector<Ability*> rogueAbilities = { backstab, poisonBlade };
	GameCharacterClass rogue(ClassType::Rogue, rogueAbilities);

	//Przedmioty Wojownika
	Item* weaponWarrior = new Weapon("Miecz templariusza", 220, 16, 5);
	Item* armorWarrior = new Armor("Zbroja templariusza", 450, 5, 3, Resistances(10, 10, 10, 10, 15));

	//Przedmioty Maga
	Item* weaponMage = new Weapon("Mrozna laska", 150, 15, 20);
	Item* armorMage = new Armor("Szaty efliego maga", 50, 2, 0, Resistances(5, 5, 5, 20, 15));

	//Przedmioty Łotrzyka
	Item* weaponRogue = new Weapon("Sztylety skrytobojcy", 120, 12, 15);
	Item* armorRogue = new Armor("Plaszcz lotrzyka", 120, 3, 1, Resistances(5, 5, 5, 5, 15));

	//Przedmioty przeciwnikow
	Item* weaponEnemy1 = new Weapon("Topor barbarzyncy", 80, 20, 5);
	Item* weaponEnemy2 = new Weapon("Budzygan herszta", 120, 13, 15);
	Item* armorEnemy1 = new Armor("Kolczuga grasanta", 220, 5, 5, Resistances(5, 5, 5, 5, 5));
	Item* armorEnemy2 = new Armor("Pancerz straznika miejskiego", 500, 10, 20, Resistances(10, 10, 10, 10, 10));

	//Przedmioty Ogolne
	Item* healingPotion = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));
	Item* healingPotion2 = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));
	Item* healingPotion3 = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));
	Item* healingPotion4 = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));
	Item* healingPotion5 = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));
	Item* healingPotion6 = new Consumables("Mikstura leczenia", 150, new Effect("Leczenie", EffectType::Healing, 20, 1));

	Item* fireResistPotion = new Consumables("Ognista mikstura", 100, new Effect("Odpornosc na ogien", EffectType::FireResistBoost, 10, 4));
	Item* fireResistPotion2 = new Consumables("Ognista mikstura", 100, new Effect("Odpornosc na ogien", EffectType::FireResistBoost, 10, 4));

	std::vector<Item*> enemyItems1 = { weaponEnemy1, armorEnemy1, healingPotion4 };
	std::vector<Item*> enemyItems2 = { weaponEnemy1, armorEnemy1, healingPotion5 };
	std::vector<Item*> enemyItems3 = { weaponEnemy2, armorEnemy2, fireResistPotion };

	std::vector<Item*> heroItems1 = { weaponWarrior, armorWarrior, healingPotion };
	std::vector<Item*> heroItems2 = { weaponMage, armorMage, healingPotion2, fireResistPotion2 };
	std::vector<Item*> heroItems3 = { weaponRogue, armorRogue, healingPotion3 };

	//Postacie testowe

	MainGameCharacter player1("Alistair", GameCharacterRace::Human, warrior, Statistics(14, 10, 12, 10, 10, 12), Alignment::Good, 120, 0, heroItems1, 1);
	 MainGameCharacter player2("Solas", GameCharacterRace::Elf, mage, Statistics(10, 10, 10, 16, 12, 12), Alignment::Neutral, 80, 120, heroItems2, 1);
	 MainGameCharacter player3("Varric", GameCharacterRace::Dwarf, rogue, Statistics(10, 16, 12, 14, 10, 10), Alignment::Good, 90, 0, heroItems3, 1);
	 std::vector<MainGameCharacter*> heroes = { &player1, &player2, &player3};

	 //Testowanie wpływu przedmiotow na postać
	/*std::cout << "\n\nObrazenia przed zalozeniem broni: " << player1.attack() << std::endl << std::endl;
	std::cout << "\n\nObrona przed zalozeniem pancerza: " << player1.getDefense() << std::endl << std::endl;
	player1.useItem();
	std::cout << "\n\nObrazenia po zalozeniu broni: " << player1.attack() << std::endl << std::endl;
	std::cout << "\n\nObrona po zalozeniu pancerza: " << player1.getDefense() << std::endl << std::endl;*/

	  //Testowanie przedmiotow postaci
	for (auto hero : heroes)
	{
		std::cout << "Przedmioty bohater " << hero->getName() << std::endl;
		for (auto item : hero->getItems())
		{
			std::cout << item->getName() << std::endl;
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n";

	//Testowanie zdolnosci

	for (auto hero : heroes)
	{
		std::cout << "Zdolnosci bohatera: " << hero->getName() << std::endl;
		std::cout << hero->getClass().getAbilities() << "\n\n";
		hero->levelUp();
		std::cout << "\n\n" << hero->getClass().getAbilities() << "\n\n";
	}
	std::cout << "\n\n\n";

	//Kreator postaci
	/*CharacterDesigner designer;
	auto player1 = designer.createCharacter();

	std::cout << "Przedmioty bohater " << player1->getName() << std::endl;
	for (auto item : player1->getItems())
	{
		std::cout << item->getName() << std::endl;
	}

	std::cout << "\n\n\n";*/



	//Evil_Mob CyklopSmokCzarnksiężnika("UluMulu", GameCharacterRace::Orc, warrior, Statistics(20, 8, 14, 4, 4, 0), Alignment::Evil, 150, 0, { new Weapon("Orkowy topor", 300, 30, 10), new Armor("Naramiennik orkow", 50, 1, 0, Resistances(0, 0, 0, 0,0)) }, 5);

	//Przeciwnicy testowi
	//Evil_Mob CyklopSmokCzarnoksieznika("UluMulu", GameCharacterRace::Orc, warrior, Statistics(20, 8, 14, 4, 4, 0), 150, 0, { new Weapon("Orkowy topor", 300, 5, 10), new Armor("Naramiennik orkow", 50, 1, 0, Resistances(0, 0, 0, 0,0)) }, 5, DangerLvL::Boss);
	Evil_Mob enemy1("Grasant", GameCharacterRace::Human, warrior, Statistics(14, 10, 140, 10, 10, 8), 120, 50, enemyItems1, 5, DangerLvL::Medium, 60);
	Evil_Mob enemy2("Drugi Grasant", GameCharacterRace::Human, warrior, Statistics(14, 10, 140, 10, 10, 8), 120, 50, enemyItems2, 5, DangerLvL::Medium, 60);
	Evil_Mob enemy3("Herszt", GameCharacterRace::Orc, warrior, Statistics(20, 8, 16, 10, 8, 12), 200, 0, enemyItems3, 10, DangerLvL::Boss, 200);
	std::vector<Evil_Mob*> enemies = { &enemy1, &enemy2, &enemy3 };

	std::cout << "\nKontynuowac do modulu walki?\n";
	system("pause");

	system("cls");
	Encounter obozBandytow;
	obozBandytow.combat(heroes, enemies);
	system("pause");
}

#endif

#ifdef TradingMechanicTest
int main()
{
	MainGameCharacter player("Gerwant", GameCharacterRace::Human,
		GameCharacterClass(ClassType::Warrior, { new Ability("Whirl",AbilityType::Offensive,691, Effect("Bleed", EffectType::Bleeding, 2, 4)) }),
		Statistics(10, 10, 10, 10, 10, 10),
		Alignment::Neutral, 100, 100, { new Weapon("Aerodnight",1000,2107,100) }, 1);

	GameCharacterClass warrior(ClassType::Warrior, { new Ability("Whirl", AbilityType::Offensive, 550, Effect("None", EffectType::None, 0, 0)), new Ability("Rend", AbilityType::Offensive, 1100, Effect("None", EffectType::None, 0, 0)) });

	GameCharacterClass mage(ClassType::Mage, { new Ability("Fireball", AbilityType::Offensive, 340, Effect("Burning", EffectType::Burning, 5, 4)), new Ability("Lightning", AbilityType::Offensive, 310, Effect("Shock", EffectType::Shocked, 4, 3)) });
	GameCharacterClass rogue(ClassType::Rogue, { new Ability("Backstab", AbilityType::Offensive, 1000, Effect("Bleed", EffectType::Bleeding, 2, 5)), new Ability("Poison Blade", AbilityType::Offensive, 700, Effect("Poison", EffectType::PoisonResistBoost, 4, 6)) });
	MainGameCharacter player1("Alistair", GameCharacterRace::Human, warrior, Statistics(14, 10, 12, 10, 10, 12), Alignment::Good, 120, 0, { new Weapon("Miecz templariusza", 220, 16, 5), new Armor("Zbroja templariusza", 450, 5, 3, Resistances(10, 10, 10, 10,10)) }, 1);
	player1.setGold(1000000);
	NPC WeponSmith("Alistair", GameCharacterRace::Human, warrior, Statistics(14, 10, 12, 10, 10, 12), 120, 0, { new Weapon("Miecz templariusza", 220, 16, 5), new Armor("Zbroja templariusza", 450, 5, 3, Resistances(10, 10, 10, 10,10)) }, 1, Role::ArmorSmith);
	WeponSmith.whatCanIDo(player1);

	/*NPC(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats
		, int health, int mana, std::vector<Item*> items, unsigned lvl, std::vector<Item*> item_list, Role role);*/

}
#endif

