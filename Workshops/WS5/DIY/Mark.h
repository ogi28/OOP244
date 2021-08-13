#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds
{
   class Mark
   {
      int marks;
      double GPA;
      void setMarks(int sets);
      void validate();
      char letter;
      bool valid; // needed a second check condition to seperate valid and invalid 0;
      public:
         Mark();
         Mark(int grade);
         operator const int();
         operator double();
         operator char();
         bool operator~();
         Mark& operator+=(int extraGrade);
         Mark& operator=(int fixInvalid);
   };


   int operator+=(int& val, Mark& rhs); 






}
#endif
