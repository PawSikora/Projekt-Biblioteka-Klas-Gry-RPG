#include "Effect.h"

Effect::Effect(std::string name, EffectType effect, int valueOfEffect, int timeOfEffect)
	:name(name), effectType(effect), valueOfEffect(valueOfEffect), timeOfEffect(timeOfEffect)
{}

std::string Effect::getName()
{
	return name;
}

EffectType Effect::getType()
{
	return effectType;
}


int Effect::getEffect()
{
	return valueOfEffect;
}

int Effect::getTime()
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