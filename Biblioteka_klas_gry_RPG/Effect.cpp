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

bool Effect::passTime()
{
	if (timeOfEffect > 0)
	{
		timeOfEffect--;
		return false;
	}
	return true;
}