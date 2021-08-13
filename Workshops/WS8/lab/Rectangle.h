#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds{
   class Rectangle : public LblShape
   {
      private:
         unsigned m_width, m_height;
      public:
         Rectangle();
         Rectangle(const char*, unsigned width, unsigned height);
         void getSpecs(istream&) override;
         void draw(ostream&)const override;
   };
}





#endif
