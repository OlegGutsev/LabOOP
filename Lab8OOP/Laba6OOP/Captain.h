#pragma once
#include <iostream>
#include <string>

class Captain
{
public:
	Captain() : nameCaptain(""){};
	~Captain();
	void setName(const std::string&);
	std::string getName()const;
private:
	std::string nameCaptain;
};

Captain::~Captain()
{
}

void Captain::setName(const std::string& name)
{
	nameCaptain = name;
}

std::string Captain::getName()const{ return nameCaptain; }