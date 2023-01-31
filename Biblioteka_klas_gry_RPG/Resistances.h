#pragma once
class Resistances
{
	int fireResistance;
	int coldResistance;
	int poisonResistance;
	int magicResistance;
	int bleedResistance;

public:
	Resistances(int fireResistance, int coldResistance, int poisonResistance, int magicResistance, int bleedResistance);
	void setFireResistance(int fireResistance);
	void setColdResistance(int coldResistance);
	void setPoisonResistance(int poisonResistance);
	void setMagicResistance(int magicResistance);
	void setBleedResistance(int bleedResistance);
	void setPhysicalResistance(int physicalResistance);
	

	int getFireResistance() const;
	int getColdResistance() const;
	int getPoisonResistance() const;
	int getMagicResistance() const;
	int getBleedResistance() const;
};

