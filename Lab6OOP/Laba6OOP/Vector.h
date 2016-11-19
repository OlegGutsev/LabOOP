#pragma once

class Vector
{
public:
	Vector() : coordX1_(0), coordY1_(0), coordX2_(0), coordY2_(0) {};
	Vector(int coordX1, int coordY1, int coordX2, int coordY2);
	~Vector(){};

	float LengthVector();
	void Show();

	Vector operator + (Vector obj);
	Vector operator () (int, int, int, int);
	bool operator > (Vector obj);
	Vector operator = (Vector &obj);
	bool operator == (Vector obj);

private:
	int coordX1_;
	int coordY1_;
	int coordX2_;
	int coordY2_;
};
