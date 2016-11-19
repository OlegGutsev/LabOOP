#pragma once
# include "Ship.h"

class SailingShip: public Ship
{
public:
	SailingShip() : numberOfMasts(0), displacement(0.f){};
	SailingShip(int, float, const std::string&, int, float);
	void setNumberOfMasts(int);
	void getNumberOfMasts() const;
	void setDisplacement(float);
	void getDisplacement() const;
	~SailingShip();
	void ToConsole() const override;

private:
	int numberOfMasts;
	float displacement;
};
