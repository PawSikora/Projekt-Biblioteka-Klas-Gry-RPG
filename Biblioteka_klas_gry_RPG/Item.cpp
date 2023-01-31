#include "Item.h"

#include <stdexcept>

void Item::setValue(int value)
{
	if (value < 0) throw std::invalid_argument("Cena nie moze byc ujemna");
	this->value = value;
}

Item::Item(std::string name, int value)
	:name(name)
{
	setValue(value);
}

std::string Item::getName()
{
	return name;
}

int Item::getValue() const
{
	return value;
}
