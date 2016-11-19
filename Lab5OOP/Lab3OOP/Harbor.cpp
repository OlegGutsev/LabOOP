#include "stdafx.h"
#include "vehicle.h"
#include "Harbor.h"
#include <iostream>

void Harbor::addObject(Vehicle* vehicle)
{
	if (size_ == maxSize_)
	{
		Vehicle** temp = new Vehicle*[maxSize_];
		for (int i = 0; i < size_; i++)
			temp[i] = array_[i];
		
		delete[] array_;
		
		maxSize_ += MASS_SIZE;
		
		Vehicle** array_ = new Vehicle*[maxSize_];
		for (int i = 0; i < size_; i++)
			array_[i] = temp[i];
		
		delete[] temp;

	}
	array_[size_++] = vehicle;
}

void Harbor::clearObject(int numberObject)
{
	if (numberObject > size_)
	{
		std::cout << "Exeption error!!" << std::endl;
		exit(1);
	}
	else if (numberObject == size_)
		array_[size_] = nullptr;
	else
		for (int i = numberObject, k = i + 1; i < size_; i++) 
			array_[i] = array_[k];
	size_--;
}

Vehicle* Harbor::getObject(int numberObject) const
{
	if (numberObject > size_)
	{
		std::cout << "Exeption error!!" << std::endl;
		exit(2);
	}
	else return array_[numberObject];
}

int Harbor::getSize() const
{
	return size_;
}

void Harbor::showObject() const
{
	for (int i = 0; i < size_; i++)
		array_[i]->ToConsole();
	std::cout << std::endl;
}

Vehicle** Harbor::getObject() const
{
	return array_;
}