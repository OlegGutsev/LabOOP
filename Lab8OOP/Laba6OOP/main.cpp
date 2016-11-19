#include "Vector.h"
#include "Captain.h"
#include "Exeptions.h"
#include <iostream>
#include <time.h>
#define NDEBUG 
#include <cassert>   


void TestAssert(Vector<int, Captain, 5>& test_);

int main()
{
	const int number = 5;
	Vector<int, Captain, number> one;
	Vector<int, Captain, number> two;
	Vector<int, Captain, number> three;
	Vector<float, Captain> four;
	
	try
	{
		for (int i = 0; i < number; i++)
		{
			one.AddElement((rand() % 20) - 8);
			two.AddElement((rand() % 40) - 18);
		}
		one.AddElement(5);
		//four.AddElement(1.23f);
		//four.AddElement(2.2f);
		//four.AddElement(-2.2f);
	}
	catch (ArrayFull& error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		one.AddElement(10000000);
	}
	catch (BigValue& error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		three = one + two;
		one.Show();
		two.Show();
		three.Show();
		four.Show();
	}
	catch (ArrayEmpty& error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << four(6) << std::endl;
	}
	catch (InvalidIndexBig& error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << four(-5) << std::endl;
	}
	catch (InvalidIndexSmall& error)
	{
		std::cout << error.what() << std::endl;
	}
	try
	{
		two = one;
		two.Show();
		if (one > two)
			std::cout << std::endl << "one > two" << std::endl;
		else if (one == two)
			std::cout << std::endl << "one == two" << std::endl;
		else
			std::cout << std::endl << "one <  two" << std::endl;
		std::cout << std::endl << "Minimum: " << one.Min() << std::endl;
		one.setNameCaptain("Oleg");
		std::cout << std::endl << "Captain name: " << one.getNameCaptain() << std::endl;
		std::cout << std::endl << "Minimum: " << one.Min() << std::endl;
		one.setNameCaptain("Oleg");
		std::cout << std::endl << "Captain name: " << one.getNameCaptain() << std::endl;
	}
	catch (ArrayEmpty& error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error!" << std::endl;
	}

	Vector<int, Captain, 5> test;
	TestAssert(test);
	test.AddElement(5);
	TestAssert(test);
	system("pause");
	return 0;
}

void TestAssert(Vector<int, Captain, 5>& test_)
{
	assert(test_.getSize() != 0);
	std::cout << "Array is not empty!!!" << std::endl;
}