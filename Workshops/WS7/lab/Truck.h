#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include "MotorVehicle.h"
#include <iostream>

namespace sdds{
	class Truck : public MotorVehicle {
		private:
			double cap; 
			double load;
		public:
			Truck(const char* plate, int year, double cap, const char* address);

			bool addCargo(double cargo);
			bool unloadCargo();
			ostream& write(ostream &os) const override; //overriding functions
			istream& read(istream &in) override; // because they are already in the parent class
	};


ostream& operator<<(ostream& os, const Truck& rhs) ;
istream& operator>>(istream& in, Truck& rhs);

}







#endif

