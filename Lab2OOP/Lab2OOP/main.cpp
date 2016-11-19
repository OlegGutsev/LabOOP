#include <iostream>
#include "stdafx.h"
#include"Airline.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int input = 0;
	int number = 0;	
	bool log = true;

	cout << "Enter the size of the array for the create objects: "; cin >> input;
	Airline *airline = new Airline[input];
	for (int i = 0; i < input; i++)
	{
		Airline::ShowCountCreateObject();
		airline[i].setDistanations();
		airline[i].setTypeAircraft();
		airline[i].setFnumber();
		airline[i].setTime();
		airline[i].setDayWeek();
	}		

	do
	{
		cout << endl << "Select action : ";
		cin >> number;
		switch (number)
		{
		case 1:	ShowDestination(airline, input, "Moscow"); break;
		case 2:	ShowDay(airline, input, friday); break;
		case 3:  log = false; break;
		default: exit(1);
		}
	} while (log);

	Airline::ShowCountCreateObject();
	Airline *line = Airline::Call("Moscow");
	line->ShowAirline();
	delete[] airline;
	delete line;
	return 0;
}

