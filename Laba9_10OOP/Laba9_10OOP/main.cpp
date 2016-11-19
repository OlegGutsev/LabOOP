#include "stdafx.h"
#include <vector>
#include <set>
#include <initializer_list>
#include <iostream>

class A{
public:
	A(int a, int b)
	{
		std::cout << "A() " << a << " " << b << " " << std::endl;
	};
	A(std::initializer_list<int> value)
	{
		for (auto p = value.begin(); p != value.end(); p++)
			std::cout << *p << " ";
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
//////////initializer_list<>/////////////////
	A a(53, 6); // A(int, int)
	A b{ 56, 66 };
	//A c{ 2.3, 4, 5 }; // error double in int
	std::cout << std::endl;
	A d(2.3, 4); //OK
	std::cout << std::endl;
////////////////////////////////////////////

	std::vector<long> myVector{ 1, 2, 3, 4, 5, 6 };
	std::set<long> myset;
	std::cout << "Vector : ";
	for (int i = 0; i < myVector.size(); i++)
		std::cout << myVector[i] << " ";

	std::cout << std::endl;
	myVector.pop_back();
	myVector.pop_back();
	myVector.push_back(7);
	myVector.push_back(8);

	//std::vector<long>::const_iterator it;
	std::vector<long>::reverse_iterator it_r;
	std::cout << "Vector : ";
	for (auto it = myVector.cbegin(); it != myVector.cend(); ++it)
		std::cout << *it << " "; 

	std::cout << std::endl;

	std::cout << "Vector reverse : ";
	for (it_r = myVector.rbegin(); it_r != myVector.rend(); ++it_r)
		std::cout << *it_r << " ";
	std::cout << std::endl;

	myset.insert(myVector.begin(), myVector.end());
	std::cout << "Set : ";
	for (auto it = myset.cbegin(); it != myset.cend(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;

	const int del = 3, n = 5;
	myVector.erase(myVector.begin() + del, myVector.begin() + n);
	for (auto it_r = myVector.begin(); it_r != myVector.end(); ++it_r)
		std::cout << *it_r << " ";

	std::cout << std::endl;

	myVector.insert(myVector.end(), myset.begin(), myset.end());
	for (auto it_r = myVector.begin(); it_r != myVector.end(); ++it_r)
		std::cout << *it_r << " ";
	std::cout << std::endl;
	return 0;
}