#pragma once
class Resistances
{
	int fireResistance;
	int coldResistance;
	int poisonResistance;
	int magicResistance;

public:
	Resistances(int fireResistance, int coldResistance, int poisonResistance, int magicResistance);
	void setFireResistance(int fireResistance);
	void setColdResistance(int coldResistance);
	void setPoisonResistance(int poisonResistance);
	void setMagicResistance(int magicResistance);

	int getFireResistance();
	int getColdResistance();
	int getPoisonResistance();
	int getMagicResistance();
};

