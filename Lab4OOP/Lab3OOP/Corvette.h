#pragma once
# include "Ship.h"

class Corvette : public Ship
{
public:
	Corvette() : numberOfGuns(0){};
	Corvette(int, float, const std::string&, int);
	void setNumberOfGuns(int);
	void getNumberOfGuns() const;
	void ToConsole() const override;
	~Corvette();

private:
	int numberOfGuns;
};
