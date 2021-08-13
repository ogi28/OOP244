#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>

using namespace std;

namespace sdds{
	class MotorVehicle{
		private:
			char plate[9];
			char address[64];
			int year;
		public:
			MotorVehicle(const char* plate,int year);
			void moveTo(const char* address);
            virtual ostream& write(ostream& os) const;
		    virtual	istream& read(istream& in);
};

ostream& operator<<(ostream& os, const MotorVehicle& rhs);
istream& operator>>(istream& in, MotorVehicle& rhs);



}










#endif
