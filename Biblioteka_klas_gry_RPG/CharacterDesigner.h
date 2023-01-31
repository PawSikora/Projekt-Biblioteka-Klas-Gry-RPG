#pragma once
#include "MainGameCharacter.h"
#include "Parameters.h"
#include<iostream>
class CharacterDesigner
{
	GameCharacterRace raceChoice();
	GameCharacterClass classChoice();
	Alignment alignmentChoice();
	void statsDistribution(MainGameCharacter& temp) const;
	GameCharacterRace race;

public:

	MainGameCharacter createCharacter();




};
