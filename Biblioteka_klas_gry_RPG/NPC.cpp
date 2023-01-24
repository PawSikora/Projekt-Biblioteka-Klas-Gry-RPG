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
		return "Platnerz ";

	case Role::WeponSmith:
		return "Zbrojmistrz";

	case Role::SpellSeller:
		return "Sprzedawca zaklec";

	case Role::MiscSeller:
		return "Hadlarze roznosciami";

	case Role::PotionSeller:
		return "Alchemikiem ";

	case Role::InnKeeper:
		return "Karczmarzem ";

	  default: throw std::runtime_error("Unsupported Role type");
	}
}

void NPC::printItems(std::vector<Item*> items)
{
	std::cout << "Oto moja oferta :" << std::endl;
	int i = 1;
	for(auto x : items)
	{
		std::cout<<i <<" " << x->getName() << " " << " Za : " << x->getValue() << std::endl;
		i++;
	}
}

void NPC::greet()
{
	std::cout << "Nazwam sie  " << this->getName() << " i jestem " << myRole() << std::endl; 
}

void NPC::SellItem(MainGameCharacter &character)
{
	Item *selectedItem = nullptr;
	int selectedItemId;
	std::string answer;
	printItems(itemList);
	std::cout << "Co chcialbys kupic ? (Jesli chcesz cos kupic napisz numer obok przedmiotu, jezeli nic nie chcesz sprzedawac napisz zegnaj)" << std::endl;
	std::cin >> answer;
	if (answer.find("zegnaj") == 0)
	{
		std::cout << "Wiec zegnaj" << std::endl;
		
	}
	else
	{
		selectedItemId = forceNumberInput(answer);
		while(selectedItemId > itemList.size() || selectedItemId < 1)
		{
			std::cout << "Latarnia twojego intelektu nie swieci zbyt jasno ?" << std::endl;
			std::cout << "(Jesli chcesz cos kupic napisz numer obok przedmiotu, jezeli nic nie chcesz sprzedawac napisz zegnaj)" << std::endl << '\n' << '\n';
			printItems(itemList);
			std::cin >> answer;
			selectedItemId = forceNumberInput(answer);

		}
		selectedItemId--;
		
		selectedItem = itemList[selectedItemId];
		if (character.getGold() < selectedItem->getValue())
		{
			std::cout << "Wroc kiedy bedziesz miec troche zlota!";

		}
		else
		{
			std::cout << "Interesy z toba to przyjemnosc" << std::endl;
			character.setGold(character.getGold() - selectedItem->getValue());
			this->deleteItem(selectedItemId);
			character.addItem(selectedItem);


		}
	}

}
void NPC::BuyItem(MainGameCharacter &character)
{
	Item* selectedItem = nullptr;
	std::string answer;
	int selectedItemId;
	printItems(character.getItems());
	std::cout << "Chcesz cos sprzedac ? (Jesli chcesz cos sprzedac napisz numer obok przedmiotu, jezeli nic nie chcesz sprzedawac napisz zegnaj)" << std::endl;
	std::cin >> answer;
	if (answer.find("zegnaj") == 0)
	{
		std::cout << "Wiec zegnaj." << std::endl;
	
	}
	else
	{
		selectedItemId=forceNumberInput(answer);
		while ( selectedItemId > itemList.size() || selectedItemId < 1 )
		{
			
			std::cout << "Latarnia twojego intelektu nie swieci zbyt jasno?" << std::endl<<'\n';
			std::cout << "(Jesli chcesz cos sprzedac napisz numer obok przedmiotu, jezeli nic nie chcesz sprzedawac napisz zegnaj)" << std::endl<<'\n'<<'\n';
			printItems(itemList);
			std::cin >> answer;
			selectedItemId = forceNumberInput(answer);

		}
		selectedItemId--;
		selectedItem = itemList[selectedItemId];
		if (this->getGold() < selectedItem->getValue())
		{
			std::cout << "Wybacz nie mam wystarczajacej ilosci zlota " << std::endl;
		
		}
		else
		{
			std::cout << "Interesy z toba to przyjemnosc" << std::endl;
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
	
	while (anwser.find("tak") != 0 && anwser.find("zegnaj") != 0)
	{
		std::cout << "Nie zrozumialem czy mozesz powtorzyc ? (napisz tak lub zegnaj zeby przejsc dalej)"; 
		
		std::cin >> anwser;
	}
	if (anwser.find("zegnaj") == 0)
	{
		std::cout << "Wiec zegnaj." << std::endl;
		

	}
	else
	{
		std::cout << "Chcesz cos kupic czy sprzedac?";
		std::cin >> anwser;
		if (anwser.find("sprzedac") == 0)
		{
			BuyItem(character);
		}
		else if (anwser.find("kupic") == 0)
		{
			SellItem(character);
		}
		else
		{
			std::cout << "Wiec zegnaj." << std::endl;

		}
	}

	
}

void NPC::DialogInnKeeper(MainGameCharacter& character)
{
	std::string anwser;
	std::cin >> anwser;
	while (anwser.find("nocleg") != 0 && anwser.find("handel") != 0 && anwser.find("zegnaj") != 0)
	{
		std::cout << "Nie zrozumialem czy mozesz powtorzyc ? (napisz tak lub zegnaj zeby przejsc dalej)"; //zlleeeeee
		std::cin >> anwser;
	}
	if (anwser.find("zegnaj") == 0)
	{
		std::cout << "Wiec zegnaj." << std::endl;


	}
	else
	{

		if(anwser.find("nocleg")==0)
		{
			std::cout << "To bedziesz cie kosztowac 50 sztuk zlota [tak/zegnaj]" << std::endl;
			std::cin >> anwser;
			if (anwser.find("tak")==0)
			{
				if(character.getGold()>50)
				{
					character.setGold(character.getGold() - 50);//zaimplementowac resest hp i innych punktów
					
				}
				else
				{
					std::cout << "Wroc kiedy bedziesz miec troche zlota !";
				}
				
			}
			else
			{
				std::cout << "Wiec zegnaj." << std::endl;
			}
			
		}
		else if (anwser.find("handel")==0)
		{
			std::cout << "Chcesz cos kupic czy sprzedac?";
			std::cin >> anwser;
			if (anwser.find("sprzedac") == 0)
			{
				BuyItem(character);
			}
			else if (anwser.find("kupic") == 0)
			{
				SellItem(character);
			}
			else
			{
				std::cout << "Wiec zegnaj." << std::endl;

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
		std::cout << "Szukasz moze porzadnej zbroji ? "<< " [tak,zegnaj] " << std::endl;
		Dialog(character);
			break;
	case Role::WeponSmith:
		greet();
		std::cout << "Miecze, luki, sztylety? Mam wszystko czym mozna zabic. " << " [tak,zegnaj] " << std::endl;
		Dialog(character);
		break;
	case Role::SpellSeller:
		greet();
		std::cout << "Poszkujesz pradawnej wiedzy? A moze poteznych zaklec ? " << " [tak,zegnaj] " << std::endl;
		Dialog(character);
		break;
	case Role::MiscSeller:
		greet();
		std::cout << "Kielichy, skory i inne roznosci! Nigdzie nie znajdziesz lepszych cen ! " << " [tak,zegnaj] " << std::endl;
		Dialog(character);
		break;
	case Role::PotionSeller:
		greet();
		std::cout << "Tajemnicze wywary i sekrety alchemi na wyciagniecie dloni. Oczywiscie za oplata... " << " [tak,zegnaj] " << std::endl;
		Dialog(character);
		break;
	case Role::InnKeeper:
		greet();
		std::cout << "Przyszedles sie napic ? Czy moze szukasz nocelgu ? " << " [nocleg,handel,zegnaj] " << std::endl;
		DialogInnKeeper(character);
		break;

	}


}
