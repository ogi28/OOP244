#include <iostream>
#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds{

	MotorVehicle::MotorVehicle(const char* plate, int year)
	{
		strCpy(this->plate, plate);
		strCpy(address, "Factory");
		this->year = year;
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(this->address, address))
		{
			cout << "|" << right << setw(8) << plate << "|";
			cout << " |" << right << setw(20) << this->address;
			cout << " ---> ";
			cout << left << setw(20) << address << "|" << endl;
			strCpy(this->address, address);
		}
	}

	ostream& MotorVehicle::write(ostream& os) const
	{
		os << "| " << year << " | " << plate << " | " << address;
		return os;
	}

	istream& MotorVehicle::read(istream& in)
	{
		cout << "Built year: ";
		in >> year;
		cout << "License plate: ";
		in >> plate;
		cout << "Current location: ";
		in >> address;

		return in;
	}
	
	ostream& operator<<(ostream& os, const MotorVehicle& rhs)
	{
		return rhs.write(os);
	}
	
	istream& operator>>(istream& in, MotorVehicle& rhs)
	{
		return rhs.read(in);
	}

}



