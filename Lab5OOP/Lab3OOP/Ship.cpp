# include "stdafx.h"
# include"Ship.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

Ship::Ship(int capacity_, float speedMAX_, const std::string& nameTransport_) : Vehicle(capacity, speedMAX)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	nameTransport = nameTransport_;
};

Ship::~Ship(){}

Ship::Ship(Captain const & captain_)
{
	captain = captain_;
}

void Ship::setNameTransport(const std::string& nameTransport_)
{
	nameTransport = nameTransport_;
}

void Ship::setCaptainName(std::string captainName)
{
	captain.setName(captainName);
}

void Ship::getCaptainName() const{ cout << "Captain's name: " << captain.getName() << endl; }

void Ship::setCaptainFile(const std::string& NameCaptain)
{
	std::ofstream *file = new std::ofstream("captain.txt", std::ios_base::out | std::ios_base::trunc);
	if (!file->is_open())
	{
		std::cout << "The file can't be opened" << std::endl;
	}
	*file << NameCaptain << std::endl;
	file->close();
}

void Ship::getCaptainFile()
{
	std::string name = "";
	std::ifstream *file = new std::ifstream("captain.txt", std::ios_base::in);
	if (!file->is_open())
	{
		std::cout << "The file can't be opened" << std::endl;
	}
	*file >> name;
	captain.setName(name);
	std::cout << "Captain's name: " << captain.getName() << std::endl;
	file->close();
}

void Ship::setCaptainAge(int age)
{
	captain.setAge(age);
}

int Ship::getCaptainAge() const{ return captain.getAge(); }

void Ship::getTransportName() const{ cout << "Transport's name: " << nameTransport << endl; }

int Ship::getCapacity() const { return capacity; }

void Ship::getSpeedMAX() const { std::cout << "Max speed: " << speedMAX << std::endl; }

void Ship::ToConsole() const
{
	std::cout << typeid(this).name() << " " << nameTransport << " " << captain.getName() << std::endl;
}