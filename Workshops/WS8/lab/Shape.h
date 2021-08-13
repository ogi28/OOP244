#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

using namespace std;


namespace sdds{
   class Shape{
      public:
        virtual void draw(ostream&) const = 0;
        virtual void getSpecs(istream&) = 0;
        virtual ~Shape() {};

   };

   ostream& operator<<(ostream&, const Shape&);
   istream& operator>>(istream&, Shape&);

}



#endif
