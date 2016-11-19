#include "Vector.h"
#include <math.h>
#include <iostream>

Vector::Vector(int coordX1, int coordY1, int coordX2, int coordY2)
{
	coordX1_ = coordX1;
	coordY1_ = coordY1;
	coordX2_ = coordX2;
	coordY2_ = coordY2;
}

void Vector::Show()
{
	std::cout << "X1: " << coordX1_ << "Y1: " << coordY1_ << std::endl
		<< " X2: " << coordX2_ << " Y2: " << coordY2_ << std::endl << std::endl;
}

float Vector::LengthVector()
{
	return sqrt(float((coordX2_ - coordX2_) + (coordY2_ - coordY1_)));
}

Vector Vector::operator+(Vector obj)
{
	Vector temp;
	temp.coordX1_ = coordX1_ + obj.coordX1_;
	temp.coordY1_ = coordY1_ + obj.coordY1_;
	temp.coordX2_ = coordX2_ + obj.coordX2_;
	temp.coordY2_ = coordY2_ + obj.coordY2_;
	return temp;
}

Vector Vector::operator=(Vector& obj)
{
	if (this == &obj)
		return *this;
	coordX1_ = obj.coordX1_;
	coordY1_ = obj.coordY1_;
	coordX2_ = obj.coordX2_;
	coordY2_ = obj.coordY2_;
}

bool Vector::operator>(Vector obj)
{

	return this->LengthVector() > obj.LengthVector();
}

bool Vector::operator==(Vector obj)
{
	return (coordX1_ == obj.coordX1_) && (coordX2_ == obj.coordX2_) && (coordY1_ == obj.coordY1_) && (coordY2_ == obj.coordY2_);
}

Vector Vector::operator () (int coordX1, int coordY1, int coordX2, int coordY2)
{
	Vector temp;
	temp.coordX1_ = coordX1;
	temp.coordY1_ = coordY1;
	temp.coordX2_ = coordX2;
	temp.coordY2_ = coordY2;
	return temp;
}