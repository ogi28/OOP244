#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
//#include <cstring>
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }
   void TextFile::setEmpty()
   {
      if (m_textLines != nullptr)
      {
         delete [] m_textLines;
         m_textLines = nullptr;
      }
      if (m_filename != nullptr)
      {
         delete [] m_filename;
         m_filename = nullptr;
      }
      m_noOfLines = 0;
   }

   void TextFile::setFilename(const char* fname, bool isCopy)
   {
      if (fname == nullptr || fname[0] == '\0');
      else if (!isCopy)
      {
         m_filename = new char[strLen(fname) + 1];
         strCpy(m_filename, fname);
      }
      else
      {
         m_filename = new char[strLen(fname) + 3];
         strCpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
   }
   void TextFile::setNoOfLines()
   {
      char storeChar;
      ifstream inFile;
      inFile.open(m_filename);
      //ifstream vinFile(m_filename) ifstream has a constructor that opens the file
      if (inFile.is_open())
      {
         while (inFile.get(storeChar)) //stops when it hits null trm (end of file)
         {
            if (storeChar == '\n')
               m_noOfLines++;
         }
         if (m_noOfLines == 0) setEmpty();
         else m_noOfLines++;
         inFile.close();
      }
      else setEmpty();
   }

   void TextFile::loadText() 
   {
      string line;

      if (!*this);
      else 
      {
         if (m_textLines != nullptr) 
         { 
            delete[] m_textLines;
            m_textLines = nullptr;
         } 
         m_textLines = new Line[m_noOfLines];
         ifstream fileObject;
         fileObject.open(m_filename);
         if (fileObject.is_open())
         {
            int i = 0;
            while(getline(fileObject, line)) 
            {
               m_textLines[i] = line.c_str();
               //strCpy(m_textLines[i].m_value, line.c_str());
               i++;
            }
            m_noOfLines = i;
           fileObject.close();
         }

      }
   }

   void TextFile::saveAs(const char *fileName)const
   {
      ofstream fileOutputObject;
      fileOutputObject.open(fileName);
      if (fileOutputObject.is_open())
      {
         for (unsigned i = 0; i < m_noOfLines; i++) // unsigned i, means it has to be non-negative (0 or higher)
         {
            fileOutputObject << (const char*)m_textLines[i] << endl; // remember to test not casting, if endl doesn't work, put a new line character.
         }
         fileOutputObject.close();
      }
   }

   TextFile::TextFile(unsigned pageSize)
   {
      m_pageSize = pageSize;  
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
   }


   TextFile::TextFile(const char* filename, unsigned pageSize) : TextFile(pageSize)
   {
      if (filename != nullptr)
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile::TextFile(const TextFile& C) : TextFile(C.m_pageSize) // apparently this is done by c++ anyway, so didn't need to do it?
   {//deep copy vs shallow copy. Default copy is shallow. Deep copy explicitly makes a new object. This is an issue when there is an object of a class in another class. String has its own deep copy constructor.
      if (C)
      {
         this->setFilename(C.m_filename, true);
         C.saveAs(this->m_filename);
         this->setNoOfLines();
         this->loadText();
      }
   }
   TextFile& TextFile::operator=(const TextFile& C)
   {
      if (this != &C && C && *this) // the latter 2 calls bool casting operator. first one makes sure the objects aren't the same by checking this pointer isn't pointing to the address of C.
      {
         delete[] m_textLines;
         m_textLines = nullptr;
        //this->m_pageSize = C.m_pageSize;
         C.saveAs(this->m_filename);
         this->setNoOfLines();
         this->loadText();
      }
      return *this;
   }



   TextFile::~TextFile()
   {
      setEmpty();
   }
   
   unsigned TextFile::lines()const
   {
      return m_noOfLines;
   }


   std::ostream& TextFile::view(std::ostream& ostr)const
   {
      if (*this)
      {
         ostr << m_filename << endl;
         for(int i = 0; i < strLen(m_filename); i++)
         {
            ostr << '=';
         }
         ostr << endl;
         unsigned count = 0;
         while(count < m_noOfLines)
         {
            for (unsigned i = 0; i < m_pageSize && count < m_noOfLines; i++)
            {
               ostr << (const char*)m_textLines[count] << endl;
               count++;
            }
            //cin.ignore();
            if (count < m_noOfLines)
            {
               string dummy;
               ostr << "Hit ENTER to continue...";
               getline(cin, dummy);
            }
         }
      }
      return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr)
   {
      setEmpty();
      string temp;
      getline(istr, temp);
      setFilename(temp.c_str());
      setNoOfLines();
      loadText();
// remember to check if issues
      return istr;
   }


   const char* TextFile::operator[](unsigned index)const
   {
      //remember to check
      return *this ? (const char*)m_textLines[index % m_noOfLines] : nullptr; // instead of if else, use modulus to loop back
   }

   TextFile::operator bool()const
   {
     return m_filename[0] != '\0' || m_filename != nullptr;
   }

   const char* TextFile::name()const
   {
      return (const char*)m_filename;
   }
   ostream& operator<<(ostream& ostr, const TextFile& text)
   {
      return text.view(ostr);
   }

   istream& operator>>(istream& istr, TextFile& text)
   {
      return text.getFile(istr);
   }

}
