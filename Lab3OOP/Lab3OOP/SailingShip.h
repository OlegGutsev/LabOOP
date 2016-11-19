#pragma once
# include "Ship.h"

class SailingShip: public Ship
{
public:
	SailingShip() : numberOfMasts(0){};
	SailingShip(int, float, const std::string&, int);
	void setNumberOfMasts(int);
	void getNumberOfMasts() const;
	~SailingShip();

private:
	int numberOfMasts;
};
