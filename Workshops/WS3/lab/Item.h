//Ogulcan Tayhan
//104472204
//3.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SUBJECT_H
#define SDDS_SUBJECT_H
#define TAX 0.13
namespace sdds {
   class Item {
      char m_itemName[21]; // private by default
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
