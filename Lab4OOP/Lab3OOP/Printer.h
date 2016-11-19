#pragma once

#include <iostream>
#include "vehicle.h"

class Printer
{
public:
	Printer();
	~Printer();
	void IAmPrinter(Vehicle* );

private:

};

Printer::Printer()
{
}

Printer::~Printer()
{
}

void Printer::IAmPrinter(Vehicle* object)
{
	object->ToConsole();
}