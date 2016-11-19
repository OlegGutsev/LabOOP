#pragma once

#include "vehicle.h"

enum Transmission{ automatic = 0, mechanics };

class Car : protected Vehicle
{
public:
	explicit Car() :transmission(automatic){};
	Car(int, float, Transmission);
	~Car();
	void setTransmission(Transmission);
	void getTransmission() const;
	int getCapacity() const override;
	void getSpeedMAX() const override;
	virtual void ToConsole() const override;
protected:
	Transmission transmission;
};