#include "stdafx.h"
#include "Merñedes.h"
#include <iostream>
#include <string>

Mercedes::Mercedes(int capacity_, float speedMAX_, Transmission transmission_, const std::string & model_)
	: Car(capacity, speedMAX, transmission)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	transmission = transmission_;
	model = model_;
}

void Mercedes::setModel(const std::string& model_)
{
	model = model_;
}

void Mercedes::getModel() const
{
	std::cout << "Model: " << model << std::endl;
}

void Mercedes::MercManufact()const
{
	std::cout << "Mercedec was Manufacturer in: " << manufacturer << std::endl;
}

Mercedes::~Mercedes(){ counter--; }

int Mercedes::counter = 0;

int Mercedes::getCounter(){ return counter; };

void Mercedes::ToConsole() const
{
		std::cout << typeid(this).name() << " " << counter << " " << model << " " << manufacturer << std::endl;
}