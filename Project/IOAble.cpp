#include "IOAble.h"


namespace sdds{
   ostream& operator<<(ostream& os, const IOAble& rhs)
   {
      return rhs.write(os);
   }

   istream& operator>>(istream& in, IOAble& rhs)
   {
      return rhs.read(in);
   }
}
