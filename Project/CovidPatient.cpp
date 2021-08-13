#include "CovidPatient.h"

namespace sdds {
   int nextCovidTicket = 1;

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }

   char CovidPatient::type() const
   {
      return 'C';
   }
   
   istream& CovidPatient::csvRead(istream& in)
   {
      Patient::csvRead(in);
      nextCovidTicket = Patient::number() + 1;
      in.ignore(); // does this ignore '\n' ?
      
      return in;
   }

   ostream& CovidPatient::write(ostream& os) const
   {
      if (fileIO())
      {
         Patient::csvWrite(os);
      }
      else 
      {
         os << "COVID TEST" << endl;
         Patient::write(os);
      }

      return os;
   }

   istream& CovidPatient::read(istream & in)
   {
      fileIO() ? csvRead(in) : Patient::read(in);

      return in;
   }
}
