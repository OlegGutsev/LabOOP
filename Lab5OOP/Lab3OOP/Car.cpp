#include "stdafx.h"
#include "Car.h"
#include <iostream>

Car::Car(int capacity_, float speedMAX_, Transmission transmission_) : Vehicle(capacity, speedMAX)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	transmission = transmission_;
}

void Car::setTransmission(Transmission transmission_)
{
	transmission = transmission_;
}

void Car::getTransmission() const
{
	std::cout << "Transmission: " << transmission << std::endl;
}

int Car::getCapacity() const { return capacity; }
	 
void Car::getSpeedMAX() const { std::cout << "Max speed: " << speedMAX << std::endl; }

void Car::ToConsole() const
{
	std::cout << typeid(this).name() << " " << transmission << std::endl;
}

Car::~Car(){};