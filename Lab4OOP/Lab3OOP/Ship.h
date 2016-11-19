#pragma once
# include"vehicle.h"
# include"Captain.h"
#include<string>

class Ship : public Vehicle
{
public:
	Ship() : nameTransport("no"){};
	Ship(int, float, const std::string&);
	Ship(Captain const &);
	void setNameTransport(const std::string&);
	void setCaptainName(std::string);
	void getCaptainName() const;
	void setCaptainFile(const std::string&);
	void getCaptainFile();
	void getTransportName() const;
	void getCapacity()const override;
	void getSpeedMAX()const override;
	virtual void ToConsole()const override;
	~Ship();
	
protected:
	std::string nameTransport;
	Captain captain;
};
