#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool () const;
      operator int () const;
      operator double () const;
      bool operator~() const;
      Account& operator=(int a);
      Account& operator=(Account& rhs);
      Account& operator+=(double dep);
      Account& operator-=(double wit);
      Account& operator<<(Account& rhs);
      Account& operator>>(Account& lhs);
   };
   
  double operator+(const Account& lhs, const Account& rhs);
  double operator+=(double& lhs, Account& rhs); 
}
#endif // SDDS_ACCOUNT_H_
