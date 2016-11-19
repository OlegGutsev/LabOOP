# include "stdafx.h"
# include "Corvette.h"
#include<string>
using namespace std;

Corvette::Corvette(int capacity_, float speedMAX_, const string& nameTransport_, int numberOfGuns_ ) 
		: Ship(capacity, speedMAX, nameTransport)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	nameTransport = nameTransport_;
	numberOfGuns = numberOfGuns_;
}

Corvette::~Corvette(){}

void Corvette::setNumberOfGuns(int numberOfGuns_)
{
	numberOfGuns = numberOfGuns_;
}

void Corvette::getNumberOfGuns() const
{
	cout << "Number of guns: " << numberOfGuns << endl;
}