#include "stdafx.h"
#include"Captain.h"
#include<string>
#include<iostream>

Captain::~Captain()
{
}

void Captain::setName(const std::string& name)
{
	nameCaptain = name;
}

void Captain::setAge(int age_)
{
	age = age_;
}

int Captain::getAge() const{ return age; }

std::string Captain::getName()const{ return nameCaptain; }