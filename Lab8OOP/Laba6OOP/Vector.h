#pragma once
#include "Captain.h"
#include <iostream>
#include <math.h>
#include <exception>

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
	int getSize() { return size_; };
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
	if (size_ == 0) throw ArrayEmpty();
	T sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += array_[i];
	return  sum;
}

template<class T, class UserType, int SIZE = 5>
Vector<T, UserType, SIZE> Vector<T, UserType, SIZE>::operator+(Vector obj)
{
	if (size_ == 0) throw ArrayEmpty();
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
	if (size_ == 0) throw ArrayEmpty();
	for (int i = 0; i < SIZE; i++)
		if (this->array_[i] != obj.array_[i])
			return false;
	return true;
}

template<class T, class UserType, int SIZE = 5>
T Vector<T, UserType, SIZE>::operator() (int number)
{
	if (number > SIZE) throw InvalidIndexBig();
	if (number < 0) throw InvalidIndexSmall();
		return this->array_[number];

}

template<class T, class UserType, int SIZE = 5>
void Vector<T, UserType, SIZE>::Show()
{
	if (size_ == 0) throw ArrayEmpty();
		std::cout << std::endl;
		for (int i = 0; i < SIZE; i++)
			std::cout << array_[i] << " ";
	std::cout << std::endl;
}

template<class T, class UserType, int SIZE = 5>
void Vector<T, UserType, SIZE>::AddElement(T number)
{
	if (number > 1000000) throw BigValue();
	if (size_ > SIZE) throw ArrayFull();
		array_[size_++] = number;
	
}

template<class T, class UserType, int SIZE = 5>
T Vector<T, UserType, SIZE>::Min()
{
	if (size_ == 0) throw ArrayEmpty();
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