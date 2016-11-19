#include "Captain.h"
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

bool myfunction(Captain i, Captain j) { return ( i.getName() < j.getName()); }

std::ostream &operator<<(std::ostream &stream, vector<Captain>& obj)
{
	for (int i = 0; i < obj.size(); i++)
		stream << obj[i].getName() << endl;
	return stream;
}

void One(map<int, Captain> myMap)
{
	map<int, Captain>::const_iterator it;

	cout << "First sort: " << endl;
	for (auto& elem : myMap)
		cout << (elem).first << " : " << (elem).second.getName() << endl;

	cout << endl << "Second sort (reverse) " << endl;
	it = myMap.cend();
	while (it != myMap.cbegin())
	{
		it--;
		cout << endl << (*it).first << " : " << (*it).second.getName();
	}
}

void Two(map<int, Captain> myMap)
{
	cout << endl << "Use Find: " << endl;
	cout << endl << myMap.find(2)->second.getName() << endl;

	auto low = myMap.lower_bound(3),
		 up = myMap.upper_bound(4);
	myMap.erase(low, up);

	cout << endl << "Use Low and Up: " << endl;
	for (auto elem : myMap)
		cout << elem.first << " : " << elem.second.getName() << endl;
}

void Three(map<int, Captain> myMap, set<Captain>& mySet)
{
	for (auto itMyMap = myMap.cbegin(); itMyMap != myMap.cend(); ++itMyMap)
		mySet.insert(itMyMap->second);

	cout << endl << "Show set: " << endl;
	set<Captain>::const_iterator itSet = mySet.cend();
	while (itSet != mySet.cbegin())
	{
		itSet--;
		cout << itSet->getName() << endl;
	}
}

void Four(map<int, Captain> myMap, set<Captain> mySet)
{
	cout << endl << "Map: " << endl;
	for (auto& elem : myMap)
		cout << elem.first << " : " << elem.second.getName() << endl;

	cout << endl << "Set: " << endl;
	for (auto& elem : mySet)
		cout << elem.getName() << endl;
}

void Five(map<int, Captain> myMap, set<Captain> mySet, vector<Captain>& myVector)
{
	for (auto& elem : myMap)
		myVector.push_back(elem.second);

	for (auto& elem : mySet)
		myVector.push_back(elem);

	cout << endl << "Vector: ";
	cout << endl << myVector;
	nth_element(myVector.begin(), myVector.begin() + 2, myVector.end(), myfunction);
	cout << endl << myVector;
}

void Six(vector<Captain> myVector)
{
	set<int> myTestSet{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, myTestSet2;
	string nameV = "Bob";
	int countElements = 0;

	for (auto& elem : myVector)
		if (elem.getName() == nameV)
			countElements++;
	cout << endl << "Amount the elements with name " << nameV << " = " << countElements << endl;

	if (find(myVector.begin(), myVector.end(), "Bob") != myVector.end())
		cout << endl << "The element " << nameV << " found" << endl;
	else cout << endl << "The element " << nameV << " not found!!!" << endl;
	for_each(myTestSet.begin(), myTestSet.end(), [](int _n)
	{
		cout << _n * _n << " ";
	});
	int count = 0;
	set<int>::iterator TestIt;
	transform(myTestSet.begin(), myTestSet.end(), inserter(myTestSet2, myTestSet2.begin()), [&count](int a) mutable -> int
	{
		count++;
		if (a % 2 == 0)
			return 0;
		else return a * a;

	});

	cout << endl << "Amount of elements myTestSet: " << count << ".\nAlso myTestSet2 : " << endl;
	for (auto elem : myTestSet2)
		cout << elem++ << " ";
	cout << endl;
}

void Seven()
{
	string s1("Olezha");
	cout << endl << "s1: " << s1;
	string s2;
	string s3(s1);
	string s4(move(s1));
	cout << endl <<  "s2: " << s2 << " s3: " << s3 << " s4: " << s4
		<< " after move s1: " << s1 << endl;

	s2 = " Olezha go to sleep and he is nice!";
	s3 = s2.substr(1, 6);
	int pos = s2.find(" is");
	s3 += s2.substr(pos);
	cout << endl << "New s3: " << s3 << endl;
}

void Eight()
{
	int A[] = { 3, 2, 5 };
	set<int> myTestSet{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, myTestSet2;

	cout << endl << "Amount of elements more than number 2 : " <<
		count_if(A, A + 3, bind2nd(greater<int>(), 2));
	cout << endl << "Amount of elements less than number 2 : " <<
		count_if(A, A + 3, not1(bind2nd(greater<int>(), 2)));
	cout << endl;
	struct Aa
	{
		bool operator()(int number)
		{
			return (number % 7) == 0;
		}
	};
	auto it = find_if(myTestSet.begin(), myTestSet.end(), Aa());
	cout << "The first odd value is " << *it << endl;
	for (auto elem : myTestSet2)
		cout << elem++ << " ";
	cout << endl;
}

int main()
{
	Captain obj1("Lack");
	Captain obj2("Bob");
	Captain obj3("Oleg");
	Captain obj4("Jack");
	Captain obj5("Karat");
	Captain obj6("Sim");

	map<int, Captain> myMap = { { 1, obj1 }, { 2, obj2 }, { 3, obj3 }, { 4, obj4 }, { 5, obj5 }, { 6, obj6 } };
	set<Captain> mySet;
	vector<Captain> myVector;

	One(myMap);
	Two(myMap);
	Three(myMap, mySet);
	Four(myMap, mySet);
	Five(myMap, mySet, myVector);
	Six(myVector);
	Seven();
	Eight();
	system("pause");
	return 0;
}