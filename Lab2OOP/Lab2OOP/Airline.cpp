#include <iostream>
#include "stdafx.h"
#include "Airline.h"
#include <string>

using namespace std;

int Airline::countCreateObject = 0;

			// CONSTRUCTURS

Airline::Airline(const string & destinations_, const string & typeOfAircraft_,
				 int flightNumber_, int hours_, int minutes_, int seconds_, dayOfTheWeek dayWeek_) :
				 destinations(destinations_), typeOfAircraft(typeOfAircraft_), flightNumber(flightNumber_)
{
	if (!Validation(hours_, minutes_, seconds_)) // check correct
	{
		hours = hours_;
		minutes = minutes_;
		seconds = seconds_;
	}
	else
	{
		hours = 0; minutes = 0; seconds = 0;
	}
	dayWeek = dayWeek_;
};

Airline::Airline(const Airline &object)
{
	destinations = object.destinations;
	typeOfAircraft = object.typeOfAircraft;
	flightNumber = object.flightNumber;
	hours = object.hours;
	minutes = object.minutes;
	seconds = object.seconds;
	dayWeek = object.dayWeek;
}

Airline::~Airline(){};

bool Airline::Validation(int hours_, int minutes_, int seconds_) // Validation
{
	return hours_ < 0 || minutes_ < 0 || seconds_ < 0
			|| hours_ > 23 || minutes_ >= 60 || seconds_ >= 60;
}

			// INPUT METHODS

void Airline::setDistanations()
{
	cout << endl << "destinations : ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, destinations);
}

void Airline::setTypeAircraft()
{
	cout << endl << "typeOfAircraft : ";
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, typeOfAircraft);
}

void Airline::setFnumber()
{
	cout << endl << "flightNumber : ";
	cin >> flightNumber;
}

void Airline::setTime()
{
	cout << endl << "departureTime(hours,min,sec) : ";
	cin >> hours; cin >> minutes; cin >> seconds;
	if (Validation(hours, minutes, seconds)) // check correct
	{
		hours = 0; minutes = 0; seconds = 0;
	}
}

void Airline::setDayWeek()
{
	short day = 1;
	cout << endl << "dayOfTheWeek(number) : ";
	cin >> day;
	if (day < 1 || day > 7)
		day = 1;
	dayWeek = (dayOfTheWeek)day;
}

				// OUTPUT METHODS

void Airline::ShowAirline() const //Show
{
	cout << endl << "destinations : " << destinations << endl <<
					"typeOfAircraft : " << typeOfAircraft << endl <<
					"flightNumber : " << flightNumber << endl <<
					"departureTime : " << hours << ":" << minutes << ":" << seconds << endl <<
					"dayOfTheWeek(number) : " << dayWeek << endl;
}

void Airline::ShowCountCreateObject() 
{
	cout << endl << endl << "Creating a number of objects = " << ++countCreateObject << endl;
}

void ShowDestination(Airline *object, int count, string nameDestination)
{	
	int num = 0;
	cout << endl << endl << "The list of flights to a given destination";
	for (int i(0); i < count; i++)
	{
		if (object[i].getDestinations() == nameDestination)
		{
			object[i].ShowAirline();
			num++;
		}
	}
	if (num == 0)
		cout << endl << "The list empty!!";
}

void ShowDay(Airline *object, int count, dayOfTheWeek day) 
{
	int num = 0;
	cout << endl << endl << "The list of flights to a given day of the week";
	for (int i(0); i < count; i++)
	{
		if (object[i].getdayWeek() == day)
		{
			object[i].ShowAirline();
			num++;
		}
	}
	if (num == 0)
		cout << endl << "The list empty!!";
}

dayOfTheWeek Airline::getdayWeek() const{ return dayWeek; }

string Airline::getDestinations() const { return destinations; }

string Airline::getTypeAircraft() const { return typeOfAircraft; }

int Airline::getFnumber() const { return flightNumber; }

Airline::Airline(string destinations_)
{
	destinations = destinations_;
	typeOfAircraft = "";
	flightNumber = 0;
	hours = 0; 
	minutes = 0;
	seconds = 0;
	dayWeek = monday;
}

Airline* Airline::Call(string Name)
{
	return new Airline(Name);
}