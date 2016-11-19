#pragma once

class Vehicle
{
public:
	Vehicle() : capacity(0), speedMAX(0){};
	Vehicle(int, float);
	
	void setCapacity(int);
	
	void setSpeedMAX(float);

	void setParamsFile(int, float);

	void getParamsFile();

	void getCapacity() const;

	void getSpeedMAX() const;

	~Vehicle();

protected:
	int capacity;
	float speedMAX;
};
