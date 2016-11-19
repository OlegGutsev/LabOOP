# include "stdafx.h"
  
# include "vehicle.h"
# include "Ship.h"
# include "Corvette.h"
# include "Captain.h"
# include "SailingShip.h"
# include "SteamShip.h"
# include "Car.h"
# include "Merñedes.h"
# include "Printer.h"
# include "Harbor.h"
# include "Controller.h"

#include <iostream>
#include <string>

void f(const int *);

int _tmain(int argc, _TCHAR* argv[])
{
	//Vehicle *p;
	//Ship ship{ 20, 22.f, "BSTU" };
	//p = &ship;
	//p->getCapacity();
	//p->getSpeedMAX();
	//ship.setCaptainFile("Jeck");
	//ship.getCaptainFile();
	//ship.getCapacity();
	//ship.getSpeedMAX();
	//ship.getTransportName();
	//std::cout << std::endl;
	//
	//Corvette *corvette = new Corvette{ 35, 21.3f, "Tiger", 18 };
	//corvette->setCaptainName("James");
	//corvette->getCaptainName();
	//corvette->getCapacity();
	//corvette->getSpeedMAX();
	//corvette->getTransportName();
	//corvette->getNumberOfGuns();
	//
	//std::cout << std::endl;
	//
	//SailingShip *sailingShip = new SailingShip{ 40, 23.4f, "Wolf", 4, 113.5f };
	//sailingShip->setCaptainName("Bob");
	//sailingShip->getCaptainName();
	//sailingShip->getCapacity();
	//sailingShip->getSpeedMAX();
	//sailingShip->getTransportName();
	//sailingShip->getNumberOfMasts();
	//
	//std::cout << std::endl;
	//
	//SteamShip *steamShip = new SteamShip{ 77, 8.5f };
	//steamShip->setCaptainName("Jok");
	//steamShip->setRoom(VIP);
	//steamShip->getCaptainName();
	//steamShip->getRoom();
	//steamShip->getCapacity();
	//steamShip->getSpeedMAX();
	//
	//std::cout << std::endl;
	//
	//Car *car = new Car();
	//car->getCapacity();
	////car->setCapacity(8) - ERROR!
	//
	//std::cout << std::endl;
	//
	//Mercedes *merc = new Mercedes(); //1
	//merc->MercManufact();
	//merc->setTransmission(automatic);
	////merc->setCapacity(8) - ERROR!
	//merc->getCapacity();
	//
	//std::cout << std::endl;
	//
	//Mercedes *merc1 = new Mercedes[3]; //2 3 4
	//std::cout << "Count create object: " << merc->getCounter() << std::endl;
	//
	//std::cout << std::endl;
	//
	//Printer alluse;
	//alluse.IAmPrinter(corvette);
	//alluse.IAmPrinter(sailingShip);
	//alluse.IAmPrinter(steamShip);
	//
	//std::cout << std::endl;

/////////////////////////////////////////////////////////////////
	//Car ccar;
	//car = dynamic_cast <Car*>(merc);
	//if (car)
	//	std::cout << "OK Mercedes in Car!!" << std::endl;
	//else
	//	std::cout << "Error!" << std::endl;
	//
	//merc = dynamic_cast <Mercedes*>(car);
	//if (merc)
	//	std::cout << "OK Car in Mercedes!!" << std::endl;
	//else
	//	std::cout << "Error!" << std::endl;
	//car = &ccar;
	//
	//merc = dynamic_cast<Mercedes*>(car);
	//if (merc)
	//	std::cout << "OK Car in Mercedes!!" << std::endl;
	//else
	//	std::cout << "Error!" << std::endl;
	//
	//int i = 5;
	//f(&i); // const_cast
	//std::cout << std::endl << i << std::endl;
	//
	//int m;
	//float f = 199.22F;
	//m = static_cast<int> (f); //static_const
	//std::cout << std::endl << m << std::endl;

    ////////////////////////////////////////////////////////
   //                                                    //
  //			RELEASE          CONTAINER              //
 //                                                    //
////////////////////////////////////////////////////////

SailingShip ship{ 25, 30.f, "Kar", 3, 20.5f };
ship.setCaptainAge(35);
SailingShip ship1{ 35, 24.f, "KKKar", 5, 29.5f };
ship1.setCaptainAge(30);
SteamShip steamShip{ 40, 40.5f };
steamShip.setCaptainName("Alex");
steamShip.setCaptainAge(25);
SteamShip steamShip1{ 60, 30.5f };
steamShip1.setCaptainName("Jhon");
steamShip1.setCaptainAge(50);

Harbor harbor;
harbor.addObject(&ship);
harbor.addObject(&ship1);
harbor.addObject(&steamShip);
harbor.addObject(&steamShip);
harbor.addObject(&steamShip1);

harbor.showObject();
harbor.clearObject(3);
harbor.showObject();
(harbor.getObject(2))->ToConsole();

Controller controller;

std::cout << std::endl << "Average displacement SailingShip's: " << controller.getAverageDisplacment(&harbor) << std::endl << std::endl;
std::cout << "Average capacity SteamShip's: " << controller.getAverageCapacity(&harbor) << std::endl << std::endl;
std::cout << "Vehicle where, which have age 35 and more: "; controller.getQualityCaptain(&harbor, 35);
std::cout << std::endl << std::endl;


	//delete [] merc1;
	//delete merc;
	//delete corvette;
	//delete sailingShip;
	//delete steamShip;
	return 0;
}

void f(const int *p)
{
	int *v;
	v = const_cast<int*>(p);
	*v = 6;
}