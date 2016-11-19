#pragma once
#include<string>
#include<iostream>

class Captain
{
public:
	Captain() : nameCaptain(""){};
	Captain(const std::string& name) { nameCaptain = name; }
	~Captain(){};
	void setName(const std::string& name) { nameCaptain = name; }
	std::string Captain::getName()const{ return nameCaptain; }
	friend std::ostream &operator<<(std::ostream &stream, Captain& obj)
	{
		stream << obj.getName() << std::endl;
		return stream;
	}
private:
	std::string nameCaptain;
};



