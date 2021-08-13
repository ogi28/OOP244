#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

   Time& Time::setToNow()
   {
      m_min = getTime();
      return *this;
   }

   Time::Time(unsigned min)
   {
      m_min = min;
   }


   ostream& Time::write(ostream& ostr) const
   {
      unsigned hour = m_min/60;
      unsigned min = m_min%60;

      if (hour <= 9)
         ostr << 0;
      ostr << hour << ":";
      if (min <= 9)
         ostr << 0;
      ostr << min;

      return ostr;
   }


   istream& Time::read(istream& istr)
   {
      int hour = 0, min = 0; 
      char colon = 'x';
      istr >> hour;

      //istr won't be good by default if they don't enter an int to hour
      if (hour < 0)
      {
         istr.setstate(ios::failbit); // read at http://www.cplusplus.com/reference/ios/ios_base/iostate/ 
      }

      istr >> colon;

      if (colon != ':')
      {
         istr.setstate(ios::failbit); // read at http://www.cplusplus.com/reference/ios/ios_base/iostate/ 
      }

      istr >> min;

      if (min < 0)
      {
         istr.setstate(ios::failbit); // read at http://www.cplusplus.com/reference/ios/ios_base/iostate/ 
      }

      if (istr.good())
      {
         m_min = (hour * 60) + min;
      }

      return istr;
   }


   Time& Time::operator-=(const Time& D)
   {
      while (m_min < D.m_min)
      {
         m_min += (24 * 60);
      }

      m_min -= D.m_min;

      return *this;

   }

   Time Time::operator-(const Time& D)const
   {

      Time temp;

      temp.m_min = this->m_min;

      temp -= D;

      return temp;

   }
      


   Time& Time::operator+=(const Time& D)
   {
      m_min += D.m_min;

      return *this;
   }

   Time Time::operator+(const Time& D)const
   {
      Time temp;
      temp.m_min = m_min + D.m_min;
      return temp;
   }

   Time& Time::operator=(unsigned val)
   {
      m_min = val;
      return *this;
   }

   Time& Time::operator*=(unsigned val)
   {
      m_min *= val;
      return *this;
   }

   Time Time::operator*(unsigned val)const
   {
      Time temp;
      temp.m_min = m_min * val;
      return temp;
   }

   
   Time& Time::operator /= (unsigned int val)
   {
      m_min /= val;
      return *this;
   }

   Time Time::operator/(unsigned val)const
   {
      Time temp;
      temp.m_min = m_min / val;
      return temp;
   }


   Time::operator int()const
   {
      return (int)m_min;
   }

   Time::operator unsigned int()const
   {
      return m_min;
   }


   std::ostream& operator<<(std::ostream& ostr, const Time& D)
   {
      return D.write(ostr);
   }

   std::istream& operator>>(std::istream& istr, Time& D)
   {
      return D.read(istr);
   }

}
