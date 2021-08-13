#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds{
   class Line : public LblShape
   {
      private: 
         unsigned m_length;
      public:
         Line();
         Line(const char*, unsigned);
         //~Line();
         void getSpecs(istream &) override;
         void draw(ostream&)const override;

   };
}

#endif
