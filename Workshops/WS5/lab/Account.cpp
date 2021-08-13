#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace sdds;
using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool () const // check valid
   {
      return (this->m_number >= 10000 && this->m_number <= 99999
         && this->m_balance >= 0);
   }

   Account::operator int() const
   {
      return this->m_number;
   }

   Account::operator double() const
   {
      return this->m_balance;
   }

   bool Account::operator~() const
   {
      return this->m_number == 0;
   }

   Account& Account::operator=(int a)
   {

      if (a < 10000 || a > 99999)
      {
         setEmpty();
      }
      else if (!~*this || this->m_number < 0)
      {
       // do nothing   
      }
      else this->m_number = a;

      return *this;
   }

   Account& Account::operator=(Account& rhs)
   {

      if (~*this && bool(rhs))
      {
         this->m_balance = rhs.m_balance;
         this->m_number = rhs.m_number;
         rhs.m_balance = 0;
         rhs.m_number = 0;
      }
      return *this;
      //If the left Account operand is not new or the
      //right account operand is not valid, no action should be taken.
   }
   
   Account& Account::operator+=(double dep)
   {
    if (dep < 0 || this->m_number < 0);
    else 
    {
       this->m_balance += dep;
    }
   return *this;
   }

   Account& Account::operator-=(double wit)
   {
    if (this->m_balance < wit || this->m_number < 0 || wit < 0);
    else 
    {
       this->m_balance -= wit;
    }
   return *this;
   }
 
   Account& Account::operator<<(Account& rhs)
   {
      if (this->m_number == rhs.m_number || this->m_number < 0 || rhs.m_number < 0 );
      else 
      {
         this->m_balance+=rhs.m_balance;
         rhs.m_balance = 0;
      }
      return *this;
   }
   
   Account& Account::operator>>(Account& lhs) 
   {
      if (this->m_number == lhs.m_number || this->m_number < 0 || lhs.m_number < 0 );
      else 
      {
         lhs.m_balance += this->m_balance;
         this->m_balance = 0;
      }
      return *this;
   }

   double operator+(const Account &lhs, const Account &rhs)
   {
      double sum = 0.0;

      if (int(lhs) < 0 || int(rhs) < 0);
      else sum = double(lhs) + double(rhs);

      return sum; 
   }

   double operator+=(double &lhs, Account &rhs)
   {
      //is account valid? is
      if (int(rhs) >= 0 && double(rhs) >= 0.0)
      {
         lhs += double(rhs);
      }
      
      return lhs;
      
   }


//whenever you need to check something use the operators.
//~ for new, bool for valid!

}

