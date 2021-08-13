#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds
{
   class Mark
   {
      int marks;
      double GPA;
      void setMarks(int sets);
      char letter;
      bool valid;

      public:
         Mark();
         Mark(int grade);
         operator int();
         operator double();
         operator char();
         bool operator~();
         Mark& operator+=(int extraGrade);
         Mark& operator=(int fixInvalid);
   };

   int operator+=(int& val, Mark& rhs); 






}
#endif
