# include "stdafx.h"
# include"vehicle.h"
#include<fstream>
#include<iostream>

Vehicle::~Vehicle(){ }

	Vehicle::Vehicle(int capacity_, float speadMAX_) :
			capacity(capacity_), speedMAX(speadMAX_){};

	void Vehicle::setParamsFile(int capacity_, float speedMAX_)
	{
		std::ofstream *file = new std::ofstream("vehicle.txt", std::ios_base::out | std::ios_base::trunc);
		if (!file->is_open())
		{
			std::cout << "The file can't be opened" << std::endl;
		}
		*file << capacity_ << std::endl;
		*file << speedMAX_ << std::endl;
		file->close();
	}

	void Vehicle::getParamsFile()
	{
		std::ifstream *file = new std::ifstream("vehicle.txt", std::ios_base::in);
		if (!file->is_open())
		{
			std::cout << "The file can't be opened" << std::endl;
		}

		*file >> capacity;
		*file >> speedMAX;
		std::cout << "Capacity: " << capacity << std::endl;
		std::cout << "Max speed: " << speedMAX << std::endl;
		file->close();
	}
	

	void Vehicle::setCapacity(int capacity_)
	{
		capacity = capacity_;
	}

	void Vehicle::setSpeedMAX(float speedMAX_)
	{
		speedMAX = speedMAX_;
	}


