#pragma once
#include <iostream>
#include <math.h>
#include "Captain.h"

template<class T, class UserType, int SIZE = 5 >
class Vector
{
public:
	Vector() 
	{
		size_ = 0;
		for (int i(0); i < SIZE; i++)
			array_[i] = 0;
	};
	~Vector(){};

	T LengthVector();
	void Show();
	void AddElement(T number);
	T Min();
	std::string getNameCaptain();
	void setNameCaptain(const std::string& name);

	Vector<T, UserType, SIZE>  operator + (Vector obj);
	T operator () (int);
	bool operator > (Vector obj);
	Vector<T, UserType, SIZE> operator = (Vector &obj);
	
	bool operator == (Vector obj);

private:
	T array_[SIZE];
	int size_;
	UserType captain;
};

template<class T, class UserType, int SIZE = 5>
T Vector<T, UserType, SIZE>::LengthVector()
{
	T sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += array_[i];
	return  sum;
}

template<class T, class UserType, int SIZE = 5>
Vector<T, UserType, SIZE> Vector<T, UserType, SIZE>::operator+(Vector obj)
{
	Vector temp;
	for (int i = 0; i < SIZE; i++)
	{
		temp.array_[i] = this->array_[i] + obj.array_[i];
	}
	return temp;
}

template<class T, class UserType, int SIZE = 5>
Vector<T, UserType, SIZE> Vector<T, UserType, SIZE>::operator= (Vector& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < SIZE; i++)
		array_[i] = obj.array_[i];
	return *this;
}

template<class T, class UserType, int SIZE = 5>
bool Vector<T, UserType, SIZE>::operator>(Vector obj)
{

	return this->LengthVector() > obj.LengthVector();
}

template<class T, class UserType, int SIZE = 5>
bool Vector<T, UserType, SIZE>::operator==(Vector obj)
{
	for (int i = 0; i < SIZE; i++)
		if (this->array_[i] != obj.array_[i])
			return false;
	return true;
}

template<class T, class UserType, int SIZE = 5>
T Vector<T, UserType, SIZE>::operator() (int number)
{
	if (array_)
		return this->array_[number];
	else exit(2);
}

template<class T, class UserType, int SIZE = 5>
void Vector<T, UserType, SIZE>::Show()
{
	if (array_)
	{
		std::cout << std::endl;
		for (int i = 0; i < SIZE; i++)
			std::cout << array_[i] << " ";
	}
	else exit(1);
	std::cout << std::endl;
}

template<class T, class UserType, int SIZE = 5>
void Vector<T, UserType, SIZE>::AddElement(T number)
{
	if (size_ <= SIZE)
		array_[size_++] = number;
	else exit(3);
}

template<class T, class UserType, int SIZE = 5>
T Vector<T, UserType, SIZE>::Min()
{
	T min = 0;
	for (int i = 0; i < SIZE; i++)
		if (this->array_[i] < min)
			min = this->array_[i];
	return min;
};

template<class T, class UserType, int SIZE = 5>
std::string Vector<T, UserType, SIZE>::getNameCaptain()
{
	return dynamic_cast<Captain&>(captain).getName();
}

template<class T, class UserType, int SIZE = 5>
void Vector<T, UserType, SIZE>::setNameCaptain(const std::string& name)
{
	dynamic_cast<Captain&>(captain).setName(name);
}