# include "stdafx.h"
  
# include "vehicle.h"
# include "Ship.h"
# include "Corvette.h"
# include "Captain.h"
# include "SailingShip.h"
# include "SteamShip.h"

#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	Vehicle *vehicle = new Vehicle{ 10, 20.1f };
	vehicle->setParamsFile(9, 15.4f);
	vehicle->getParamsFile();
	
	std::cout << std::endl;

	Ship *ship = new Ship{ 20, 22.f, "BSTU" };
	ship->setCaptainFile("Jeck");
	ship->getCaptainFile();
	ship->getCapacity();
	ship->getSpeedMAX();
	ship->getTransportName();

	std::cout << std::endl;

	Corvette *corvette = new Corvette{ 35, 21.3f, "Tiger", 18 };
	corvette->setCaptainName("James");
	corvette->getCaptainName();
	corvette->getCapacity();
	corvette->getSpeedMAX();
	corvette->getTransportName();
	corvette->getNumberOfGuns();

	std::cout << std::endl;

	SailingShip *sailingShip = new SailingShip{ 40, 23.4f, "Wolf", 4 };
	sailingShip->setCaptainName("Bob");
	sailingShip->getCaptainName();
	sailingShip->getCapacity();
	sailingShip->getSpeedMAX();
	sailingShip->getTransportName();
	sailingShip->getNumberOfMasts();

	std::cout << std::endl;

	SteamShip *steamShip = new SteamShip{ 77, 8.5f };
	steamShip->setCaptainName("Jok");
	steamShip->setRoom(VIP);
	steamShip->getCaptainName();
	steamShip->getRoom();
	steamShip->getCapacity();
	steamShip->getSpeedMAX();

	std::cout << std::endl;

	delete vehicle;
	delete ship;
	delete corvette;
	delete sailingShip;
	delete steamShip;
	return 0;
}

