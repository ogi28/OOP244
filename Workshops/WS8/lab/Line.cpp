#include "Line.h"
#include <cstring>

namespace sdds{

   Line::Line() : LblShape()
   {
      m_length = 0;
   }

   Line::Line(const char* cstr, unsigned length) : LblShape(cstr)
   {
      m_length = length;
   }

   void Line::getSpecs(istream& in)
   {
      LblShape::getSpecs(in);
      in >> m_length;
      in.clear();
      in.ignore(1000000000000, '\n');
   }

   void Line::draw(ostream & os)const
   {
      if (label() != nullptr && m_length > 0)
      {
         os << label() <<endl;
         unsigned i = 0;
         while(i < m_length)
         {
            os << '=';
            i++;
         }
      }
   }
}
