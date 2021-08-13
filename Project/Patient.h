#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H

//#include "IOAble.h"
#include "Ticket.h"

namespace sdds{
   class Patient : public IOAble
   {
      private:
         char* m_pName;
         int m_OHIP;
         Ticket m_ticket;
         bool IO;
      public:
         Patient(int ticketNo = 0, bool IO = false);
         Patient(const Patient&) = delete;
         Patient& operator=(const Patient&) = delete;
         ~Patient();
         virtual char type()const = 0;
         bool fileIO ()const;
         void fileIO (bool IO);
         bool operator==(char c) const;
         bool operator==(const Patient& P) const;
         void setArrivalTime();
         operator Time() const; 
         int number()const;
         ostream & csvWrite(ostream &) const override;
         istream & csvRead(istream &) override;
         ostream & write(ostream &) const override;
         istream & read(istream &) override;






         
   };
}


#endif
