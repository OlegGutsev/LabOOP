#pragma once
#include<string>
#include<iostream>

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


