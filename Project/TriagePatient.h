#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include "Patient.h"

namespace sdds {
   class TriagePatient : public Patient
   {
      private:
         char* symptom;
      public:
         TriagePatient();
         char type() const override;
         istream & read(istream &) override;
         istream & csvRead(istream &) override;
         ostream & write(ostream &) const override;
         ostream & csvWrite(ostream &) const override;
         void clearSymptoms();
         istream& getSymptoms(istream&);
         ~TriagePatient();

   };

}
#endif // !SDDS_TRIAGEPATIENT_H


