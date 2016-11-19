#pragma once 
#include <exception>
#include <iostream>

class InvalidIndexBig : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return " ERROR!! Invalid index is big.";
	}
};

class InvalidIndexSmall : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return " ERROR!! Invalid index is small.";
	}
};

class ArrayEmpty : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "ERROR!! The Array is empty.";
	}
};

class ArrayFull : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "ERROR!! The Array is full.";
	}
};

class BigValue : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return " ERROR!! Invalid index is small.";
	}
};