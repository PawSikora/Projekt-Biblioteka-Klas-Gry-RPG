#include "Encounter.h"
#include <iostream>

Encounter::Encounter() : d4(Dice(4)), d6(Dice(6)), d8(Dice(8)), d10(Dice(10)), d12(Dice(12)), d20(Dice(20))
{
}

void Encounter::updateUnitState(std::vector<MainGameCharacter*>& heroes, std::vector<Evil_Mob*>& enemies)
{
	std::cout << std::endl;

	for(auto it = heroes.begin(); it != heroes.end();)
	{
		if (!(*it)->getEffects().empty())
			(*it)->effectsInfluence();
		if (!(*it)->getConsciousness())
		{
			std::cout << (*it)->getName() << " traci przytomnosc od obrazen!\n\n";
			it = heroes.erase(it);
		}
		else
		{
			std::cout << (*it)->getName() << " ma jeszcze " << (*it)->getHp() << " hp!\n\n";
			++it;
		}
	}

	for (auto it = enemies.begin(); it != enemies.end();)
	{

		if (!(*it)->getEffects().empty())
			(*it)->effectsInfluence();
		if (!(*it)->getConsciousness())
		{
			std::cout << (*it)->getName() << " traci przytomnosc od obrazen!\n\n";
			it = enemies.erase(it);
		}
		else
		{
			std::cout << (*it)->getName() << " ma jeszcze " << (*it)->getHp() << " hp!\n\n";
			++it;
		}
	}
	system("pause");
	std::cout << std::string(20, '=') << "\n\n";
}

int Encounter::criticalHit(GameCharacter& unit, int dmg)
{
	switch (unit.getClass().getClassType())
	{
		case ClassType::Warrior:
			if (d12.roll() >= 11)
			{
				std::cout << unit.getName() << " wykonuje krytyczne obrazenia!\n";
				return dmg * 2;
			}
			return dmg;

		case ClassType::Rogue:
			if (d6.roll() >= 4)
			{
				std::cout << unit.getName() << " wykonuje krytyczne obrazenia!\n";
				return dmg * 2;
			}
			return dmg;
		case ClassType::Mage:
			if (d20.roll() == 20)
			{
				std::cout << unit.getName() << " wykonuje krytyczne obrazenia!\n";
				return dmg * 2;
			}
			return dmg;
	default:
		throw std::invalid_argument("Nieznany typ klasy");
	}
}


void Encounter::combat(std::vector<MainGameCharacter*> heroes, std::vector<Evil_Mob*> enemies)
{
	int heroesInitiative = 0, enemiesInitiative = 0, selectedAction, dmgDealt = 0;
	std::string choice;
	bool turn = false, escapeHero = false, escapeEnemy = false;
	Ability* selectedAbility = nullptr;
	Effect physicalDmg("Zwykle obrazenia", EffectType::PhysicalDmg, 0, 0);

	std::sort(heroes.begin(), heroes.end(), [](MainGameCharacter* h1, MainGameCharacter* h2) { return h1->getInitiative() > h2->getInitiative(); });
	std::sort(enemies.begin(), enemies.end(), [](Evil_Mob* e1, Evil_Mob* e2) { return e1->getInitiative() > e2->getInitiative(); });

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
		std::cout << "Liczba bohaterow: " << heroes.size() << std::endl;
		if (turn)
		{

			for (auto hero : heroes)
			{
				std::cout << std::endl << hero->getName() << " rozpoczyna swoja ture!" << std::endl;
				std::cout << "Jaki ruch wykona?\n" << "1. Atak\n" << "2. Obrona\n" << "3. Uzycie przedmiotu\n" << "4. Ucieczka" << std::endl;

				selectedAction = selectNumber(1, 4);

				switch (selectedAction)
				{
				case 1:

					if (hero->getClass().getNumOfUnlockedAbilities() > 0)
					{
						std::cout << "1. Zwykly atak\n";
						std::cout << "2. Uzyj zdolnosci\n";
						selectedAction = selectNumber(1, 2);
					}

					switch (selectedAction)
					{
					case 2:
						choice.clear();
						do
						{
							std::cout << "Jakiej zdolnosci chcesz uzyc?\n" << hero->getClass().getUnlockedAbilities();
							selectedAction = selectNumber(1, hero->getClass().getNumOfUnlockedAbilities());
							selectedAbility = hero->getClass().getUnlockedAbility(selectedAction - 1);
							if (hero->useMP(selectedAbility->getMpCost()))
							{
								std::cout << "Ktorego przeciwnika chcesz zaatakowac?\n";
								for (int i = 0; i < enemies.size(); i++)
									std::cout << i + 1 << ". " << enemies[i]->getName() << std::endl;

								selectedAction = selectNumber(1, enemies.size());
								dmgDealt = enemies[selectedAction - 1]->takeDamage(selectedAbility->getEffect(), criticalHit(*hero, selectedAbility->getDmg()));
								std::cout << hero->getName() << " uzywa " << selectedAbility->getName() << " kosztem " << selectedAbility->getMpCost() << " swojej many!\n";
								std::cout << enemies[selectedAction - 1]->getName() << " obrywa za " << dmgDealt << "\n\n";
								break;
							}
							std::cout << "Nie masz wystarczajacej many na uzycie " << selectedAbility->getName() << "!\n";
							std::cout << "Aktualna mana: " << hero->getMp() << std::endl;

							std::cout << "Czy chcesz uzyc innej zdolnosci?[t/n]";
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::getline(std::cin, choice);
						} while ((choice.find('n') == std::string::npos));

						if ((choice.find('n') == std::string::npos))
							break;

						std::cout << "\n" << hero->getName() << " Atakuje normalnie!" << std::endl;

					default:
						std::cout << "Ktorego przeciwnika chcesz zaatakowac?\n";
						for (int i = 0; i < enemies.size(); i++)
							std::cout << i + 1 << ". " << enemies[i]->getName() << std::endl;

						selectedAction = selectNumber(1, enemies.size());

						dmgDealt = enemies[selectedAction - 1]->takeDamage(physicalDmg, criticalHit(*hero, hero->attack()));
						std::cout << enemies[selectedAction - 1]->getName() << " obrywa za " << dmgDealt << "\n\n";
						break;
					}
					break;

				case 2:
					hero->defend();
					std::cout << hero->getName() << " broni sie!\n\n";
					break;

				case 3:
					hero->useItem();
					break;

				case 4:
					if (hero->run())
					{
						std::cout << std::endl << hero->getName() << " ucieka z pola bitwy!\n\n";
						escapeHero = true;
					}
					break;
				}
			}

			if (escapeHero)
			{
				heroes.erase(std::remove_if(heroes.begin(), heroes.end(), [](MainGameCharacter* otherHero) {return otherHero->getEscaped(); }), heroes.end());
				escapeHero = false;
			}

		}
		else
		{
			std::cout << "Tura przeciwnikow!\n\n";

			for (auto enemy : enemies)
			{
				std::cout << "\n" << enemy->getName() << " rozpoczyna swoja ture!" << std::endl;

				if (enemy->getHp() > 30)
				{
					selectedAction = enemy->chooseAction(3) + 1;
				}
				else
				{
					int escape = d6.roll();
					if (escape > 4)
						selectedAction = 4;
				}

				std::cout << "Przeciwnik wybiera: " << selectedAction << "\n\n";
				switch (selectedAction)
				{
				case 1:
					if (enemy->getClass().getNumOfUnlockedAbilities() > 0)
					{
						selectedAction = enemy->chooseAction(2) + 1;
					}

					switch (selectedAction)
					{
					case 2:
						choice.clear();
						do
						{
							selectedAbility = enemy->getClass().getAbility(enemy->chooseAction(enemy->getClass().getNumOfUnlockedAbilities()));

							if (enemy->useMP(selectedAbility->getMpCost()))
							{
								selectedAction = enemy->chooseAction(heroes.size());
								dmgDealt = heroes[selectedAction]->takeDamage(selectedAbility->getEffect(), criticalHit(*enemy, selectedAbility->getDmg()));
								std::cout << enemy->getName() << " uzywa " << selectedAbility->getName() << "!\n";
								std::cout << heroes[selectedAction]->getName() << " obrywa za " << dmgDealt << "\n\n";
								break;
							}

							choice = std::to_string(enemy->chooseAction(2));
						} while ((choice.find('1') == std::string::npos));

						if ((choice.find('1') == std::string::npos))
							break;

						std::cout << "\n" << enemy->getName() << " Atakuje normalnie!" << std::endl;

					default:

						std::cout << enemy->getName() << " atakuje!\n";

						selectedAction = enemy->chooseAction(heroes.size());

						dmgDealt = heroes[selectedAction]->takeDamage(physicalDmg, criticalHit(*enemy, enemy->attack()));
						std::cout << heroes[selectedAction]->getName() << " obrywa za " << dmgDealt << "\n\n";
						break;
					}
					break;

				case 2:
					enemy->defend();
					std::cout << enemy->getName() << " broni sie!\n\n";
					break;

				case 3:
					enemy->useItem();
					std::cout << enemy->getName() << " uzywa przedmiotu!\n\n";
					break;

				case 4:
					enemy->run();
					std::cout << std::endl << enemy->getName() << " ucieka z pola bitwy!\n\n";
					escapeEnemy = true;
					break;
				}

			}

			if (escapeEnemy)
			{
				enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Evil_Mob* otherEnemy) {return otherEnemy->getEscaped(); }), enemies.end());
				escapeEnemy = false;
			}

		}
		updateUnitState(heroes, enemies);
		turn = !turn;
	}
	while (!heroes.empty() && !enemies.empty());

	if (enemies.empty())
		std::cout << "\nBOHATEROWIE ZWYCIEZYLI!\n";
	if (heroes.empty())
		std::cout << "\nWROGOWIE ZWYCIEZYLI!\n";
}
