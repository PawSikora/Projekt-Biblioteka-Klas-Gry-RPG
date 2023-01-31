#pragma once
#include <string>
#include "Parameters.h"

class Effect
{
	std::string name;
	EffectType effectType;
	int valueOfEffect;
	int timeOfEffect;

public:
	Effect(std::string name, EffectType effect, int valueOfEffect, int timeOfEffect);

	std::string getName();
	EffectType getType() const;
	int getEffect() const;
	int getTime() const;
	void setTime(int time_of_effect);
	bool passTime();

};

