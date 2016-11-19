#pragma once
#include <string>
#include <iostream>
using namespace std;

enum dayOfTheWeek
{
	monday = 1,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
	sunday,
};

class Airline
{
public:
	Airline() :destinations("no"), typeOfAircraft("no"), flightNumber(0), hours(0), minutes(0), seconds(0), dayWeek(monday){};
	Airline(const std::string & destinations_, const std::string & typeOfAircraft_, int flightNumber_, int hours_, int minutes_, int seconds_, dayOfTheWeek dayWeek_);
	Airline(const Airline &);
	void ShowAirline() const;
	void setDistanations();
	void setTypeAircraft();
	void setFnumber();
	void setTime();
	void setDayWeek();
	dayOfTheWeek getdayWeek() const;
	string getDestinations() const;
	string getTypeAircraft() const;
	int getFnumber() const;
	bool Validation(int, int, int);
	static void ShowCountCreateObject();  // Show count Creating a number of objects
	~Airline();
	static Airline* Call(std::string);
private:
	static int countCreateObject; // count Creating a number of objects
	std::string destinations;
	std::string typeOfAircraft;
	int flightNumber;
	int hours,
		minutes,
		seconds;
	dayOfTheWeek dayWeek;
	Airline(string);
};

void ShowDestination(Airline *, int, std::string nameDestination); // show on the destination
void ShowDay(Airline *, int, dayOfTheWeek); // show day of the week

