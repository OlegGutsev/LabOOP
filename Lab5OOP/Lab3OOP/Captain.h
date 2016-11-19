#pragma once
#include<string>
#include<iostream>

class Captain
{
public:
	Captain() : nameCaptain(""), age(0) {};
	~Captain();
	void setName(const std::string&);
	void setAge(int);
	int getAge() const;
	std::string getName()const;
private:
	std::string nameCaptain;
	int age;
};


