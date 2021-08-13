#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds{
   class LblShape : public Shape{
      private:
         char* m_label;
      protected:
         const char* label()const;
      public:
         LblShape();
         LblShape(const char* );
         ~LblShape();
         LblShape(const LblShape&) = delete;
         LblShape& operator=(const LblShape&) = delete;
         void getSpecs(istream &) override;
   };

}


#endif
