#pragma once

class IActions
{
public:
	virtual bool run() = 0;
	virtual int attack() = 0;
	virtual void defend() = 0;
	virtual void useItem() = 0;
	virtual ~IActions() {}

};