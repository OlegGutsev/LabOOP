#pragma once
# include "vehicle.h"
# include "Captain.h"
#include <iostream>
enum TypeRoom{ Standart = 1, Suite, VIP } ;

class SteamShip : public Vehicle
{
public:
	SteamShip() : cabin(nullptr){};
	SteamShip(int, float);
	SteamShip(Captain const &);
	~SteamShip();
	void setRoom(TypeRoom);
	void getRoom()const;
	void setCaptainName(const std::string&);
	void getCaptainName() const;
private:
	Captain captain;
	class Cabin;
	Cabin *cabin;
};
