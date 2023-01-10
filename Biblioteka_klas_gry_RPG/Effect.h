#pragma once
#include <string>

class Effect
{
	std::string name;
	int posivite;
	int negative;
	// ? Timer timeOffEffect;

public:
	Effect(std::string name, int posivite, int negative);
	std::string getName();

	//??
	int getEffect();

	// ? Timer getTime();
};

