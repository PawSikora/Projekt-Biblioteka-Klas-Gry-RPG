#pragma once
class Statistics
{
	int strength;
	int dexterity;
	int consitution;
	int intelligence;
	int wisdom;
	int charisma;

public:
	Statistics(int strength, int dexterity, int consitution, int intelligence, int wisdom, int charisma);
	int getStrength();
	int getDexterity();
	int getConsitution();
	int getIntelligence();
	int getWisdom();
	int getCharisma();
	void setStrength(int strength);
	void setDexterity(int dexterity);
	void setConsitution(int consitution);
	void setIntelligence(int intelligence);
	void setWisdom(int wisdom);
	void setCharisma(int charisma);
};

