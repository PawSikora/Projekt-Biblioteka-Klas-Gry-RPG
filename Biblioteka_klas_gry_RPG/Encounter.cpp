#include "Encounter.h"
#include <iostream>

#include "Evil_Mob.h"

Encounter::Encounter() : d4(Dice(4)), d6(Dice(6)), d8(Dice(8)), d10(Dice(10)), d12(Dice(12)), d20(Dice(20))
{
}

bool Encounter::isNumber(std::string& s)
{
	return s.find_first_not_of("0123456789-+") == std::string::npos;
}

int Encounter::forceNumberInput(std::string& answer)
{

	while (!isNumber(answer))
	{
		std::cout << "Prosze wprowadzic numer" << std::endl;
		std::cin >> answer;

	}
	int result = std::stoi(answer);
	return result;
}

void Encounter::combat(std::vector<MainGameCharacter*> heroes, std::vector<Evil_Mob*> enemies)
{
	int heroesInitiative = 0, enemiesInitiative = 0, heroDeathCounter = 0, enemyDeathCounter = 0, selectedAction, dmg, escape;
	std::string choice;
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

	std::cout << "Napotkano przeciwnikow!\n\n" << "Pojawili sie:\n";
	for(int i = 0; i < enemies.size(); i++)
	{
		std::cout << i+1 << ". " << enemies[i]->getName() << std::endl;
	}

	if (turn)
		std::cout << "\nBohaterowie rozpoczynaja starcie!\n";
	else
		std::cout << "\nWrogowie rozpoczynaja starcie!\n";

	do
	{
		if(turn)
		{
			std::cout << "Liczba bohaterow: " << heroes.size() << std::endl;
			for (auto hero : heroes)
			{
				std::cout << std::endl << hero->getName() << " rozpoczyna swoja ture!" << std::endl;
				std::cout << "Jaki ruch wykona?\n" << "1. Atak\n" << "2. Obrona\n" << "3. Uzycie przedmiotu\n" << "4. Ucieczka" << std::endl;

				std::cin >> choice;
				selectedAction = forceNumberInput(choice);

				switch (selectedAction)
				{
				case 1:
					std::cout << "Ktorego przeciwnika chcesz zaatakowac?\n";
					for (int i = 0; i < enemies.size(); i++)
						std::cout << i+1 << ". " << enemies[i]->getName() << std::endl;

					std::cin >> choice;
					selectedAction = forceNumberInput(choice);

					enemies[selectedAction-1]->takeDamage(EffectType::PhysicalDmg,hero->attack());
					std::cout << enemies[selectedAction - 1]->getName() << " obrywa za " << hero->attack() << std::endl;
					break;

				case 2: //Zabezpieczyc je¿eli bohater ju¿ siê broni??? -  Zrobione :D
					hero->defend();
					break;

				case 3:
					hero->useItem();
					break;

				case 4: //Lepiej to dopracowaæ - Zrobione :D
					if(hero->run())
					{
						std::cout << std::endl << hero->getName() << " ucieka z pola bitwy!\n";
						heroes.erase(std::remove(heroes.begin(), heroes.end(), hero), heroes.end());
					}
					break;
				}
			}
			
		}
		else
		{
			std::cout << "Tura przeciwnikow!\n\n";

			for (auto enemy : enemies)
			{
				std::cout << enemy->getName() << " rozpoczyna swoja ture!" << std::endl;

				if (enemy->getHp() > 30)
				{
					//std::cout << "dziala1\n\n";
					selectedAction = 3; //enemy->chooseAction(3) + 1;
				}
				else
				{
					//std::cout << "dziala2\n\n";
					escape = d6.roll();
					if (escape > 4)
						selectedAction = 4;
				}

				std::cout << "Przeciwnik wybiera: " << selectedAction << "\n\n";
				switch (selectedAction)
				{
				case 1:
					std::cout << enemy->getName() << " atakuje!\n";

					selectedAction = enemy->chooseAction(heroes.size());

					heroes[selectedAction]->takeDamage(EffectType::PhysicalDmg, enemy->attack());
					std::cout << heroes[selectedAction]->getName() << " obrywa za " << enemy->attack() << std::endl;
					break;

				case 2:

					//if (!(std::find(enemy->getEffects().begin(), enemy->getEffects().end(), Effect("", EffectType::Defending, 0, 0)) != enemy->getEffects().end()))
						enemy->defend();
					//else
						//std::cout << enemy->getName() << " Probuje sie bronic ale juz to robi!" << std::endl; //Moze w ogole tego nie uwzgledniac
					break;

				case 3:
					enemy->useItem(); //Zrobic wyswietlanie komunikatu na temat wykorzystywango przedmiotu
					std::cout << enemy->getName() << " uzywa przedmiotu!\n";
					break;

				case 4: //Lepiej to dopracowaæ
					if (enemy->run())
					{
						//heroes.erase(std::remove(heroes.begin(), heroes.end(), hero->getName()), heroes.end()); Cos nie tak z erasem
						std::cout << std::endl << enemy->getName() << " ucieka z pola bitwy!\n";
						enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
					}
					break;
				}
				
			}
		}

		std::cout << std::endl;

		for (auto hero : heroes)
		{
			if (hero->getHp() == 0)
				heroDeathCounter++;
			std::cout << hero->getName() << " ma jeszcze " << hero->getHp() << " hp!" << std::endl << std::endl;
			if(hero->getEffects().size() > 0)
				hero->effectsInfluence();
		}

		for (auto enemy : enemies)
		{
			if (enemy->getHp() == 0)
				enemyDeathCounter++;
			std::cout << enemy->getName() << " ma jeszcze " << enemy->getHp() << " hp!" << std::endl << std::endl;
			if (enemy->getEffects().size() > 0)
				enemy->effectsInfluence();
		}

		if (heroDeathCounter == heroes.size() || enemyDeathCounter == enemies.size())
			break;
		turn = !turn; // Blokuje przejscie do sprawdzenia warunku while i zaczyna kolejna ture mimo ze przeciwnik ma 0 hp!
		std::cout << std::endl;
	}
	while (heroDeathCounter < heroes.size() || enemyDeathCounter < enemies.size());

	if (heroDeathCounter < heroes.size())
		std::cout << "\nBOHATEROWIE ZWYCIEZYLI!\n";
	if (enemyDeathCounter < enemies.size())
		std::cout << "\nWROGOWIE ZWYCIEZYLI!\n";
}
