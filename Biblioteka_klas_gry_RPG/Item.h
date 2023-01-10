#pragma once
#include <string>

class Item
{
	std::string name;
	int value;

	void setValue(int value);
protected:
	Item(std::string name, int value);
public:
	std::string getName();
	int getValue();
};

