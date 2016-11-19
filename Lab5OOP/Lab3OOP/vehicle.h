#pragma once

class Vehicle
{
public:
	Vehicle() : capacity(0), speedMAX(0){};
	Vehicle(int, float);
	void  setCapacity(int);				  
	void  setSpeedMAX(float);
	void setParamsFile(int, float);
	void getParamsFile();
	virtual int getCapacity() const = 0;
	virtual void getSpeedMAX() const = 0;
	virtual void ToConsole() const = 0;
	virtual ~Vehicle();

protected:
	int capacity;
	float speedMAX;
};
