#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>
namespace sdds
{
   class Label
   {
         char* UIchars;
         char* content;
      public:
         Label();
         Label(const char* frameArg);
         Label(const char* frameArg, const char* content);
         ~Label();
         void readLabel();
         std::ostream& printLabel()const;

         
   };

}


#endif
