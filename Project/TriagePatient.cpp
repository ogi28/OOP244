#include "TriagePatient.h"
#include "utils.h"
#include <cstring>
#include <sched.h>

namespace sdds {
   int nextTriageTicket = 1;

   void TriagePatient::clearSymptoms()
   {
      if (symptom != nullptr)
      {
         delete[] symptom;
         symptom = nullptr;
      }
   }

   istream& TriagePatient::getSymptoms(istream& in)
   {
      clearSymptoms();
      symptom = getcstr(nullptr, in); // fixed to call getcstr

      return in;
   }

   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
      symptom = nullptr;
      nextTriageTicket++;
   }

   char TriagePatient::type() const
   {
      return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& os)const
   {
      Patient::csvWrite(os);
      os << ',' << (symptom != nullptr ? symptom : " ");

      return os;
   }

   istream& TriagePatient::csvRead(istream & in)
   {
      Patient::csvRead(in);
      in.ignore();
      getSymptoms(in);
      nextTriageTicket = Patient::number() + 1;

      return in;
   }

   ostream& TriagePatient::write(ostream& os)const
   {
      if (fileIO())
      {
         csvWrite(os);
      }
      else 
      {
         os << "TRIAGE" << endl;
         Patient::write(os);
         os << "Symptoms:" << (symptom != nullptr ? symptom : " ") << endl;
      }

      return os;
   }

   istream& TriagePatient::read(istream & in)
   {
      if (fileIO())
      {
         csvRead(in);
      }
      else 
      {
         Patient::read(in);
         cout << "Symptoms: ";
         getSymptoms(in);
      }
      return in;
   }

   TriagePatient::~TriagePatient()
   {
      clearSymptoms();
   }
}
