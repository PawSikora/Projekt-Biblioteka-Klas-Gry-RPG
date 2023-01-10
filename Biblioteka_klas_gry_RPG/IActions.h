#pragma once
class IActions
{
public:
	virtual bool run() = 0;
	virtual bool attack() = 0;
	virtual bool defend() = 0;
	virtual void useItem() = 0;
	virtual ~IActions() {}
};