#include "Shape.h"


namespace sdds{

   ostream& operator<<(ostream& os, const Shape& rhs)
   {
       rhs.draw(os);
       return os;
   }

   istream& operator>>(istream& in, Shape& rhs)
   {
      rhs.getSpecs(in);
      return in;
   }

}
