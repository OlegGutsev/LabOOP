# include "stdafx.h"
# include "SteamShip.h"

class SteamShip::Cabin
{
public:
	explicit Cabin() : typeRoom(Standart){};
	void setTypeRoom(TypeRoom typeRoom_)
	{
		typeRoom = typeRoom_;
	}
	void getTypeRoom()const { std::cout << "Type Room( 1 - Standart, 2 - Suite, 3 - VIP): " << typeRoom << std::endl; }
private:
	TypeRoom typeRoom;
};

SteamShip::SteamShip(int capacity_, float speedMAX_) : Vehicle(capacity, speedMAX)
{
	capacity = capacity_;
	speedMAX = speedMAX_;
	cabin = new Cabin();
}

SteamShip::SteamShip(Captain const & captain_)
{
	captain = captain_;
}

SteamShip::~SteamShip()
{
	delete cabin;
}

void SteamShip::setRoom(TypeRoom type)
{
	cabin->setTypeRoom(type);
}

void SteamShip::getRoom()const
{
	cabin->getTypeRoom();
}

void SteamShip::setCaptainName(const std::string &captainName)
{
	captain.setName(captainName);
}

void SteamShip::getCaptainName() const{ std::cout << "Captain's name: " << captain.getName() << std::endl; }
