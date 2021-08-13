#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include "Patient.h"

namespace sdds {
   class CovidPatient : public Patient
   {
      private:
     //    static int nextCovidTicket;
      public:
         CovidPatient();
         char type() const override;
         istream & read(istream &) override;
         istream & csvRead(istream &) override;
         ostream & write(ostream &) const override;
   };
}
#endif // !SDDS_COVIDPATIENT_H_



