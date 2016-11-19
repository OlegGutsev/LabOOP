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
	bool operator < (const Captain & x) const 
	{
		if (nameCaptain < x.nameCaptain)
			return true;
		else
			return false;
	}

	friend std::ostream &operator<<(std::ostream &stream, Captain& obj)
	{
		stream << obj.getName() << std::endl;
		return stream;
	}
	bool operator ==(const std::string & str) const
	{
		return nameCaptain == str;
	}
private:
	std::string nameCaptain;
};



