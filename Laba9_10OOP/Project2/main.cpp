#include "stdafx.h"
#include "Captain.h"
#include <vector>
#include <set>
#include <initializer_list>
#include <memory>
#include <iostream>

std::ostream &operator<<(std::ostream &stream, std::vector<std::shared_ptr<Captain>>& obj)
{
	for (int i = 0; i < obj.size(); i++)
		stream << obj[i]->getName() << std::endl;
	return stream;
};

typedef std::vector<std::shared_ptr<Captain>> VecPTr;
typedef std::set<std::unique_ptr<Captain>> SetPTr;

int _tmain(int argc, _TCHAR* argv[])
{
	VecPTr myVector;
	std::shared_ptr<Captain> obj1 = std::make_shared<Captain>("Jack");
	std::shared_ptr<Captain> obj2 = std::make_shared<Captain>("Bob");
	std::shared_ptr<Captain> obj3 = std::make_shared<Captain>("Oleg");

	myVector.push_back(obj1);
	myVector.push_back(obj2);
	myVector.push_back(obj3);

	std::cout << myVector;
	std::cout << std::endl;
	myVector.pop_back();

	std::cout << std::endl << "Show Vector: " << std::endl;
	VecPTr::const_iterator it = myVector.cbegin();
	for (it; it != myVector.cend(); ++it)
		std::cout << **it ;

	std::cout << std::endl << "After reverse: " << std::endl;
	VecPTr::reverse_iterator rit = myVector.rbegin();
	for (rit; rit != myVector.rend(); ++rit)
		std::cout << **rit ;

	std::cout << std::endl;

	SetPTr mySet;
	std::unique_ptr<Captain> Uobj1 = std::make_unique<Captain>("Nick");
	std::unique_ptr<Captain> Uobj2 = std::make_unique<Captain>("Mike");
	std::unique_ptr<Captain> Uobj3 = std::make_unique<Captain>("Josh");

	mySet.insert(std::move(Uobj1));
	mySet.insert(std::move(Uobj2));
	mySet.insert(std::move(Uobj3));

	std::cout << std::endl << "Show: " << std::endl;
	SetPTr::const_iterator setIt;
	for (setIt = mySet.cbegin(); setIt != mySet.cend(); ++setIt)
		std::cout << **setIt;

	const int del = 1, n = 2;
	myVector.erase(myVector.begin() + del, myVector.begin() + n);
	std::cout << std::endl << "After erase: " << std::endl;
	std::cout << myVector;

	std::shared_ptr<Captain> temp;
	for (setIt = mySet.begin(); setIt != mySet.end(); ++setIt) {
		temp = std::make_shared<Captain>(std::move(**setIt));
		myVector.push_back(temp);
	}

	std::cout << "Vector : " << std::endl;
	for (it = myVector.cbegin(); it != myVector.end(); ++it)
		std::cout << **it;

	std::cout << std::endl;

	std::cout << "Set : " << std::endl;
	for (setIt = mySet.begin(); setIt != mySet.end(); ++setIt)
		std::cout << **setIt;
	
	return 0;
}