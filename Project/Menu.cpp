#include <cstring>
#include "utils.h"
#include "Time.h"
#include "Menu.h"


namespace sdds{

   Menu::Menu(const char* MenuContent, int NoOfSelections)
   {
      m_text = new char[strlen(MenuContent) + 1];
      strcpy(m_text, MenuContent);
      m_noOfSel = NoOfSelections;
   }

   Menu::~Menu()
   {
      if (m_text != nullptr)
      {
         delete[] m_text;
         m_text = nullptr;
      }
   }
   
   Menu::Menu(const Menu& C) : Menu(C.m_text, C.m_noOfSel)
   {
      
   }

   ostream& Menu::display(ostream& os)
   {
      os << m_text << endl;
      os << "0- Exit" << endl;

      return os;
   }

   int& Menu::operator>>(int &Selection)
   {
      display(cout);
      Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");

      return Selection;
   }
   


   








}
