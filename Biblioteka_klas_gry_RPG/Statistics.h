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
	int getStrength() const;
	int getDexterity() const;
	int getConsitution() const;
	int getIntelligence() const;
	int getWisdom() const;
	int getCharisma() const;
	void setStrength(int strength);
	void setDexterity(int dexterity);
	void setConsitution(int consitution);
	void setIntelligence(int intelligence);
	void setWisdom(int wisdom);
	void setCharisma(int charisma);
};

