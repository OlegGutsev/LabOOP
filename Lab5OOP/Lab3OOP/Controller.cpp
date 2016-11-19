#include "stdafx.h"
#include "Controller.h"
#include "SailingShip.h"
#include "SteamShip.h"
#include "vehicle.h"

float Controller::getAverageDisplacment(Harbor* harbor)
{
	float sum = 0;
	int countSailingShip = 0;
	Vehicle** array = harbor->getObject();
	int sizeArray = harbor->getSize();

	for (int i = 0; i < sizeArray; i++)
		if (SailingShip *temp = dynamic_cast<SailingShip*>(harbor->getObject(i)))
		{
			sum += temp->getDisplacement();
			countSailingShip++;
		}
	if (countSailingShip == 0)
	{
		std::cout << "ERROR!!";
		exit(3);
	}
	return sum / (float)countSailingShip;
}

float Controller::getAverageCapacity(Harbor* harbor)
{
	int sum = 0;
	int countSteamShip = 0;
	Vehicle** array = harbor->getObject();
	int sizeArray = harbor->getSize();
	for (int i = 0; i < sizeArray; i++)
		if (SteamShip *temp = dynamic_cast<SteamShip*>(harbor->getObject(i)))
		{
			sum += temp->getCapacity();
			countSteamShip++;
		}
	if (countSteamShip == 0)
	{
		std::cout << "ERROR!!";
		exit(3);
	}
	return sum / (float)countSteamShip;
}

void Controller::getQualityCaptain(Harbor* harbor, int age)
{
	Vehicle** array = harbor->getObject();
	int sizeArray = harbor->getSize();
	for (int i = 0; i < sizeArray; i++)
	{
		Ship *temp = dynamic_cast<Ship*>(harbor->getObject(i));
		if (temp != NULL && temp->getCaptainAge() < age)
			temp->ToConsole();
		SteamShip *temp1 = dynamic_cast<SteamShip*>(harbor->getObject(i));
		if (temp1 != NULL && temp1->getCaptainAge() < age)
			temp1->ToConsole();
		std::cout << std::endl;
	}
}