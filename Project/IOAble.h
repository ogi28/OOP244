#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
using namespace std;


namespace sdds{

   class IOAble{
      public:
         virtual ostream& csvWrite(ostream&)const = 0;
         virtual istream& csvRead(istream&) = 0;
         virtual ostream& write(ostream&)const = 0;
         virtual istream& read(istream&) = 0;
         virtual ~IOAble() {};
   };

   ostream& operator<<(ostream&, const IOAble&);
   istream& operator>>(istream&, IOAble&);

}






#endif
