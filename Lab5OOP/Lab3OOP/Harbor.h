#pragma once
#include "vehicle.h"

#define MASS_SIZE 100;

class Harbor
{
public:
	void addObject(Vehicle*);
	void showObject() const;
	void clearObject(int);
	Vehicle* getObject(int) const;
	Vehicle** getObject() const;
	int getSize() const;

	Harbor()
	{
		maxSize_ = MASS_SIZE;
		size_ = 0;
		array_ = new Vehicle*[maxSize_];
	}

private:
	Vehicle** array_;
	int size_;
	int maxSize_;
};
