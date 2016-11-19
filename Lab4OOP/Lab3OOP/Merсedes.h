#pragma once

#include "Car.h"
#include <string>

class Mercedes : public Car
{
public:
	Mercedes() :model("no"), manufacturer("Germany"){ counter++; };
	Mercedes(int, float, Transmission, const std::string &);
	void setModel(const std::string &);
	void getModel() const;
	void MercManufact() const;
	static int getCounter();
	void ToConsole() const override;
	~Mercedes();

private:
	static int counter;
	std::string model;
	const std::string manufacturer;
};
