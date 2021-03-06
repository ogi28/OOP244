//cpp
#include "Mark.h"
namespace sdds
{
   Mark::Mark()
   {
      marks = 0;
      GPA = 0.0;
      letter = 'F';
      valid = true;

   }
   
   Mark::Mark(int grade) : Mark()
   {
      setMarks(grade);
   }

   bool Mark::operator~() // if true, valid.
   {
      return (marks <= 100 && marks >= 0);
   }

   void Mark::validate()
   {
      valid = ~*this ? true : false;
      marks = int(*this);
   }
   void Mark::setMarks(int sets)
   {
      marks = sets;
      validate();
   }

   Mark::operator const int()
   {
      return ~*this ? marks : 0; 
   }


   Mark& Mark::operator+=(int extraGrade)
   {
     // ~*this && extraGrade >= 0 && valid ? marks+=extraGrade : marks;
     if (~*this && extraGrade >= 0 && valid)
     {
        marks += extraGrade;
        validate();
     }
      return *this;
   }

   Mark& Mark::operator=(int fixInvalid)
   {
      //if (fixInvalid <= 100 && fixInvalid >= 0)
         setMarks(fixInvalid);

      return *this;
   }

   Mark::operator double()
   {
      if (80 <= marks && ~*this && valid)
         GPA = 4.0; 
      else if (70 <= marks && 80 > marks && valid)
         GPA = 3.0;
      else if (60 <= marks && 70 > marks && valid)
         GPA = 2.0;
      else if (50 <= marks && 60 > marks && valid)
         GPA = 1.0;
      else 
         GPA = 0.0;

      return GPA;
   }

   Mark::operator char()
   {
      if (!valid)
         letter = 'X';
      else if (80 <= marks && 100 >= marks)
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

