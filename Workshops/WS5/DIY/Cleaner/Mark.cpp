//cpp
#include "Mark.h"
namespace sdds
{
   Mark::Mark()
   {
      marks = 0;
   }
   
   Mark::Mark(int grade)
   {
      setMarks(grade);
   }

   bool Mark::operator~() // if true, valid.
   {
      return (marks <= 100 && marks >= 0);
   }

   void Mark::setMarks(int sets)
   {
      marks = sets;
      marks = int(*this);
   }

   Mark::operator int()
   {
      return ~*this ? marks : 0; 
   }


   Mark& Mark::operator+=(int extraGrade)
   {
      ~*this && extraGrade >= 0 ? marks+=extraGrade : marks;
      return *this;
   }

   Mark& Mark::operator=(int fixInvalid)
   {
         setMarks(fixInvalid);

      return *this;
   }

   Mark::operator double()
   {
      if (80 <= marks && ~*this)
         GPA = 4.0; 
      else if (70 <= marks && 80 > marks)
         GPA = 3.0;
      else if (60 <= marks && 70 > marks)
         GPA = 2.0;
      else if (50 <= marks && 60 > marks)
         GPA = 1.0;
      else 
         GPA = 0;

      return GPA;
   }

   Mark::operator char()
   {
      if (!~*this)
         letter = 'X';
      else if (80 <= marks && ~*this)
         letter = 'A'; 
      else if (70 <= marks && 80 > marks)
         letter = 'B';
      else if (60 <= marks && 70 > marks)
         letter = 'C';
      else if (50 <= marks && 60 > marks)
         letter = 'D';
      else  
         letter = 'F';

      return letter;
   }

   int operator+=(int& val, Mark &rhs)
   {
      return ~rhs ? val+= int(rhs) : val;
   }
}
