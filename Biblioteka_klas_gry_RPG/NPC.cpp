#include "NPC.h"

#include <iostream>

NPC::NPC(std::string name, GameCharacterRace race, GameCharacterClass characterClass, Statistics stats, int health, int mana, std::vector<Item*> items, unsigned lvl, Role role)
	: Mob(name, race, characterClass, stats, Alignment::Neutral, health, mana, items, lvl),
	itemList(items), role_(role)
{
}
std::string NPC::myRole()
{
	switch (role_)
	{
	case Role::ArmorSmith:
		return "Armorsmith";

	case Role::WeponSmith:
		return "Weaponsmith";

	case Role::SpellSeller:
		return "Spellsmith";

	case Role::MiscSeller:
		return "Miscsmith";

	case Role::PotionSeller:
		return "Potionsmith";

	case Role::InnKeeper:
		return "Innkeeper";

	  default: throw std::runtime_error("Unsupported Role type");
	}
}

void NPC::printItems(std::vector<Item*> items)
{
	std::cout << "this is what i got :" << std::endl;
	int i = 0;
	for(auto x : items)
	{
		std::cout<<i <<" " << x->getName() << " " << " For : " << x->getValue() << std::endl;
		i++;
	}
}

void NPC::greet()
{
	std::cout << "Hi my name is " << this->getName() << " i'm " << myRole() << std::endl; 
}

void NPC::SellItem(MainGameCharacter &character)
{
	Item *selectedItem = nullptr;
	int selectedItemId;
	std::string anwser;
	printItems(itemList);
	std::cout << "Do you wish to buy anything ? (if you want to buy something type number next to it, else type bye" << std::endl;
	std::cin >> anwser;
	if (anwser.find("bye") == 0)
	{
		std::cout << "Bye then." << std::endl;
		
	}
	else
	{
		selectedItemId = std::stoi(anwser);
		selectedItem = itemList[selectedItemId];
		if (character.getGold() < selectedItem->getValue())
		{
			std::cout << "Come back when you have some money !";

		}
		else
		{
			std::cout << "Nice to do business with you" << std::endl;
			character.setGold(character.getGold() - selectedItem->getValue());
			this->deleteItem(selectedItemId);
			character.addItem(selectedItem);


		}
	}

}
void NPC::BuyItem(MainGameCharacter &character)
{
	Item* selectedItem = nullptr;
	std::string anwser;
	int selectedItemId;
	printItems(character.getItems());
	std::cout << "Do you wish to sell anything ? (if you want to buy something type number next to it, else type bye" << std::endl;
	std::cin >> anwser;
	if (anwser.find("bye") == 0)
	{
		std::cout << "Bye then." << std::endl;
	
	}
	else
	{
		selectedItemId = std::stoi(anwser);
		selectedItem = itemList[selectedItemId];
		if (this->getGold() < selectedItem->getValue())
		{
			std::cout << "Sorry i don't have enough money " << std::endl;
		
		}
		else
		{
			std::cout << "Nice to do business with you" << std::endl;
			character.setGold(int(((double)character.getGold() + double(selectedItem->getValue())) * 0.8));
			this->addItem(selectedItem);
			character.deleteItem(selectedItemId);
		
		}

	}

	
}
void NPC::Dialog(MainGameCharacter &character)
{
	std::string anwser;
	std::cin >> anwser;
	std::cerr << anwser;
	
	while (anwser.find("yes") != 0 && anwser.find("bye") != 0)
	{
		std::cout << "I didn't catch that out. Can you repeat? (use statement yes or bye to advance)"; 
		
		std::cin >> anwser;
	}
	if (anwser.find("bye") == 0)
	{
		std::cout << "Bye then." << std::endl;
		

	}
	else
	{
		std::cout << "Do you wish to sell or buy ?";
		std::cin >> anwser;
		if (anwser.find("sell") == 0)
		{
			BuyItem(character);
		}
		else if (anwser.find("buy") == 0)
		{
			SellItem(character);
		}
		else
		{
			std::cout << "Bye then." << std::endl;

		}
	}

	
}

void NPC::DialogInnKeeper(MainGameCharacter& character)
{
	std::string anwser;
	std::cin >> anwser;
	while (anwser.find("sleep") == 0 && anwser.find("drink") == 0 && anwser.find("bye") == 0)
	{
		std::cout << "I didn't catch that out. Can you repeat? (use statement yes or bye to advance)"; //zlleeeeee
		std::cin >> anwser;
	}
	if (anwser.find("bye") == 0)
	{
		std::cout << "Bye then." << std::endl;


	}
	else
	{
		if(anwser.find("sleep")==0)
		{
			std::cout << "This will cost you about 50 gold [yes/bye]" << std::endl;
			std::cin >> anwser;
			if (anwser.find("yes")==0)
			{
				if(character.getGold()>50)
				{
					character.setGold(character.getGold() - 50);//zaimplementowac resest hp i innych punktów
					
				}
				else
				{
					std::cout << "Come back when you have some money !";
				}
				
			}
			else
			{
				std::cout << "Bye then." << std::endl;
			}
			
		}
		else
		{
			std::cout << "Do you wish to sell or buy ?";
			std::cin >> anwser;
			if (anwser.find("sell") == 0)
			{
				BuyItem(character);
			}
			else if (anwser.find("buy") == 0)
			{
				SellItem(character);
			}
			else
			{
				std::cout << "Bye then." << std::endl;

			}
		}
		
	}
}



void NPC::whatCanIDo(MainGameCharacter &character)
{
	std::string anwser;
	switch(role_)
	{
	case Role::ArmorSmith:
		greet();
		std::cout << "Perhaps you are looking for a fine piece of armor ? "<< " [yes,bye] " << std::endl;
		Dialog(character);
			break;
	case Role::WeponSmith:
		greet();
		std::cout << "Perhaps you are looking for a deadly weapon ? " << " [yes,bye] " << std::endl;
		Dialog(character);
		break;
	case Role::SpellSeller:
		greet();
		std::cout << "Perhaps you are looking for a powerful spells ? " << " [yes,bye] " << std::endl;
		Dialog(character);
		break;
	case Role::MiscSeller:
		greet();
		std::cout << "Perhaps you are looking for a various items ? " << " [yes,bye] " << std::endl;
		Dialog(character);
		break;
	case Role::PotionSeller:
		greet();
		std::cout << "Perhaps you are looking for a good potions ? " << " [yes,bye] " << std::endl;
		Dialog(character);
		break;
	case Role::InnKeeper:
		greet();
		std::cout << "Are u here for a drink or too sleep in one of my rooms ? " << " [sleep,drink,bye] " << std::endl;
		DialogInnKeeper(character);
		break;

	}


}
