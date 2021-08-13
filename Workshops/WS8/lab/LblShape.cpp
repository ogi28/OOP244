#include "LblShape.h"
#include <string>
#include <cstring>

namespace sdds{
   LblShape::LblShape()
   {
      if (m_label != nullptr)
         m_label = nullptr;
   }

   LblShape::LblShape(const char* label) : LblShape()
   {
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }

   LblShape::~LblShape()
   {
      if (m_label != nullptr)
      {
         delete[] m_label;
         m_label = nullptr;
      }
   }

   void LblShape::getSpecs(istream &in)
   {
      string str;
      getline(in, str, ',');
      delete[] m_label;
      m_label = nullptr;
      m_label = new char[strlen(str.c_str()) + 1];
      strcpy(m_label, str.c_str());
   }

   const char* LblShape::label()const
   {
      return (const char*) m_label;
   }
}
