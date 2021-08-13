#include "Patient.h"
#include "utils.h"
#include <cstring>

namespace sdds{
   Patient::Patient(int ticketNo, bool IO) : m_ticket(ticketNo)
   {
      m_pName = nullptr;
      this->IO = IO;
      m_OHIP = 0;
   }

   Patient::~Patient()
   {
      if (m_pName != nullptr)
      {
         delete[] m_pName;
         m_pName = nullptr;
      }
   }

   bool Patient::fileIO()const
   {
      return IO;
   }

   void Patient::fileIO(bool IO)
   {
      this->IO = IO;
   }

   bool Patient::operator==(char c)const
   {
      return type() == c;
   }

   bool Patient::operator==(const Patient& P)const
   {
      return P.type() == this->type();
   }

   void Patient::setArrivalTime()
   {
      m_ticket.resetTime(); 
   }

   Patient::operator Time() const
   {
      return Time(m_ticket);
   }

   int Patient::number() const
   {
      return m_ticket.number();
   }

   ostream& Patient::csvWrite(ostream& os) const
   {
      os << type() << ',' << m_pName << ',' << m_OHIP << ',';
      m_ticket.csvWrite(os);

      return os;
   }

   istream& Patient::csvRead(istream& in)
   {
      if (m_pName != nullptr)
      {
         delete[] m_pName;
         m_pName = nullptr;
      }
      m_pName = getcstr(nullptr, in, ','); // fixed to use getcstr;
      in >> m_OHIP;
      in.ignore();
      //in.clear();
      //in.ignore(80085, '\n');
      m_ticket.csvRead(in);

      return in;
   }

   ostream& Patient::write(ostream& os)const
   {
      os << m_ticket << endl;
      string name(m_pName);
      os << name.substr(0, 25) << ", OHIP: " << m_OHIP << endl; // added endl

      return os;
   }

   istream& Patient::read(istream& in)
   {
      if (m_pName != nullptr)
      {
         delete[] m_pName;
         m_pName = nullptr;
      }
      char* temp = getcstr("Name: ", in);
      m_pName = new char[strlen(temp) + 1];
      strcpy(m_pName, temp);
      delete[] temp;
      m_OHIP = getInt(100000000, 999999999, "OHIP: ");

      return in;
   }

   

   







}
