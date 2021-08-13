#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;

namespace sdds{
class Menu{
   private:
      char* m_text;
      int m_noOfSel;
      void display()const;
   public:
      Menu(const char* MenuContent, int NoOfSelections);
      virtual ~Menu();
      int& operator>>(int& Selection);
      Menu(const Menu&);
      Menu& operator=(const Menu&) = delete;
      ostream& display(ostream& os);

};
}




#endif

