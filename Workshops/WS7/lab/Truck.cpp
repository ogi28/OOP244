#include "Truck.h"



namespace sdds{

	Truck::Truck(const char* plate, int year, double cap, const char* address) : MotorVehicle(plate, year)
	{
		this->cap = cap;
		load = 0;
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool ret = cargo+load <= cap ? 1 : 0;
		load = ret ? load+cargo : cap;

		return ret;
	}

	bool Truck::unloadCargo()
	{
		bool ret = load > 0 ? 1 : 0;
		load = 0; 

		return ret;
	}

	
	ostream& Truck::write(ostream &os) const
	{
		MotorVehicle::write(os);
		os << " | " << load << "/" << cap;
		
		return os;
	}

	istream& Truck::read(istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> cap;
		cout << "Cargo: ";
		in >> load;

		return in;
	}

	ostream& operator<<(ostream& os, const Truck& rhs)
	{
		return rhs.write(os);
	}
	
	istream& operator>>(istream& in, Truck& rhs)
	{
		return rhs.read(in);
	}

}
