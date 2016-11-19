# include "stdafx.h"
# include "SailingShip.h"
#include<string>
using namespace std;

SailingShip::SailingShip(int capacity_, float speedMAX_, const string &nameTransport_, int numberOfMasts_)
	: Ship(capacity, speedMAX, nameTransport)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	nameTransport = nameTransport_;
	numberOfMasts = numberOfMasts_;
}

SailingShip::~SailingShip(){}

void SailingShip::setNumberOfMasts(int numberOfMasts_)
{
	numberOfMasts = numberOfMasts_;
}

void SailingShip::getNumberOfMasts() const
{
	cout << "Number of masts: " << numberOfMasts << endl;
}

