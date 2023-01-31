#include "Effect.h"

Effect::Effect(std::string name, EffectType effect, int valueOfEffect, int timeOfEffect)
	:name(name), effectType(effect), valueOfEffect(valueOfEffect), timeOfEffect(timeOfEffect)
{}

std::string Effect::getName()
{
	return name;
}

EffectType Effect::getType() const
{
	return effectType;
}


int Effect::getEffect() const
{
	return valueOfEffect;
}

int Effect::getTime() const
{
	return timeOfEffect;
}

void Effect::setTime(int time_of_effect)
{
	if (time_of_effect < 0) throw std::invalid_argument("Czas musi byc liczba dodatnia");
	timeOfEffect = time_of_effect;
}

bool Effect::passTime()
{
	if (timeOfEffect > 0)
	{
		timeOfEffect--;
		return false;
	}
	return true;
}
