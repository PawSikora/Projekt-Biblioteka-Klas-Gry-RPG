#include "Encounter.h"
#include <iostream>

Encounter::Encounter() : d4(Dice(4)), d6(Dice(6)), d8(Dice(8)), d10(Dice(10)), d12(Dice(12)), d20(Dice(20))
{
}

void Encounter::combat(std::vector<MainGameCharacter*> heroes, std::vector<Mob*> enemies)
{
	int heroesInitiative = 0, enemiesInitiative = 0, heroDeathCounter = 0, enemyDeathCounter = 0, choice;
	bool turn = false;

	std::sort(heroes.begin(), heroes.end(), [](MainGameCharacter* h1, MainGameCharacter* h2) { return h1->getInitiative() > h2->getInitiative(); });
	std::sort(enemies.begin(), enemies.end(), [](Mob* e1, Mob* e2) { return e1->getInitiative() > e2->getInitiative(); });

	for (auto hero : heroes)
	{
		heroesInitiative += hero->getInitiative();
	}

	for (auto enemy : enemies)
	{
		enemiesInitiative += enemy->getInitiative();
	}

	if (heroesInitiative > enemiesInitiative)
		turn = true;

	std::cout << "Napotkano przeciwnikow!\n" << "Pojawili sie: ";
	for(int i = 0; i < enemies.size(); i++)
	{
		std::cout << i+1 << ". " << enemies[i]->getName() << std::endl;
	}

	if (turn)
		std::cout << "Bohaterowie rozpoczynaja starcie!\n";
	else
		std::cout << "Wrogowie rozpoczynaja starcie!\n";

	do
	{
		if(turn)
		{
			for (auto hero : heroes)
			{
				std::cout << hero->getName() << " rozpoczyna swoja ture!" << std::endl;
				std::cout << "Jaki ruch wykona?\n" << "1. Atak\n" << "2. Obrona\n" << "3. Uzycie przedmiotu\n" << "4. Ucieczka" << std::endl;

				do
				{
					std::cin >> choice;
					if (choice > 4 || choice < 1)
						std::cout << "Wybierz czynnosc 1-4.!\n";
				}
				while (choice < 1 || choice > 4);

				switch (choice)
				{
				case 1:
					std::cout << "Ktorego przeciwnika chcesz zaatakowac?\n";
					for (int i = 0; i < enemies.size(); i++)
						std::cout << i+1 << ". " << enemies[i]->getName() << std::endl;

					do
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						std::cin >> choice;
						if (choice > enemies.size() || choice < 1)
							std::cout << "Wybierz poprawnego przeciwnika!(1-" << enemies.size() << ")\n";
					} while (choice < 1 || choice > enemies.size());

					enemies[choice-1]->takeDamage(EffectType::PhysicalDmg,hero->attack());
					break;

				case 2: //Zabezpieczyc je¿eli bohater ju¿ siê broni???
					hero->defend();
					break;

				case 3:
					hero->useItem();
					break;

				case 4: //Lepiej to dopracowaæ
					if(hero->run())
					{
						//heroes.erase(std::remove(heroes.begin(), heroes.end(), hero->getName()), heroes.end()); Cos nie tak z erasem
					}
					break;
				}
			}
			
		}
		else
		{
			std::cout << "Tura przeciwnikow!";
		}





		for (auto hero : heroes)
		{
			if (hero->getHp() == 0)
				heroDeathCounter++;
		}

		for (auto enemy : enemies)
		{
			if (enemy->getHp() == 0)
				enemyDeathCounter++;
		}
		turn = !turn;
	}
	while (heroDeathCounter < heroes.size() || enemyDeathCounter < enemies.size());
}
