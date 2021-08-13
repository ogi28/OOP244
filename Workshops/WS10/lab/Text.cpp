#include "Text.h"
#include "cstring.h"



#include <fstream>
using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }


   const char& Text::operator[](int index)const
   {
      return m_content[index]; //will be undefined behaviour for invalid index
   }


   Text::Text(const char* filename)
   {
      m_filename = nullptr;
      m_content = nullptr;

      if (filename != nullptr)
      {
         m_filename = new char [strLen(filename) + 1 ];
         strCpy(m_filename, filename);
         read();
      }

   }

   char* Text::filename() const
   {
      return m_filename;
   }

   void Text::clear()
   {

      if (m_content != nullptr)
      {
         delete[] m_content;
         m_content = nullptr;
      }
      if (m_filename != nullptr)
      {
         delete[] m_filename;
         m_filename = nullptr;
      }
 
   }
   Text::~Text()
   {
      clear();
   }

   Text::Text(const Text& C) : Text()
   {
      *this = C; // unoptimized but hey, no repeated code.
   }

   Text& Text::operator=(const Text& C)
   {
    //  if (m_content != nullptr || m_filename != nullptr) // to optimize from 
         clear();

      m_filename = new char[strLen(C.m_filename) + 1];
      strCpy(m_filename,C.m_filename);
      m_content = new char[strLen(C.m_content) + 1];
      strCpy(m_content,C.m_content);
      
      return *this;
   }



   void Text::read()
   {
      if (getFileLength() > 0)
      {
         char c = 48; // this is 0
         int i = 0;
         m_content = new char[getFileLength() + 1];
         ifstream fin(m_filename);
         while (fin.get(c))
         {
            m_content[i] = c;
            i++;
         }
         m_content[i] = '\0';
      }
      

   }

   void Text::write(std::ostream& os)const
   {
      if (m_content != nullptr)
      {
         os << m_content;
      }
   }

   
   std::ostream& operator<<(std::ostream& os, const Text& rhs)
   {
      rhs.write(os);
      return os;
   }
}
