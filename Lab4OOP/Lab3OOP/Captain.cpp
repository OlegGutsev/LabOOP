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

std::string Captain::getName()const{ return nameCaptain; }