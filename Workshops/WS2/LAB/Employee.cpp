//Ogulcan Tayhan
//104472204
//26.1.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std; 

namespace sdds {

// Holds the number of records (employees) in the file.
// Should be used (after setting) to allocate the dynamic array of Employees.
   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // reads one employee record from the file and loads it into the employee reference argument

   bool load(Employee &emp) {
      bool ok = false;
      char name[128]; 
   
      read(emp.m_empNo) && read(emp.m_salary) && read(name) ? ok = 1 : ok = 0;
      if (ok)
      {
          int Len = strLen(name);
           
          emp.m_name = new char[Len + 1];  //dynamic memory allocation for delete later
          strCpy(emp.m_name, name);
      }

      return ok;
   }
    
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) 
      { 

          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees]; //dynamic memory 2.0 for more delete later

          while (i < noOfEmployees)
          {
              ok = load(employees[i]); // ok will become true everytime this loop happens.
              i++;
          }
          if (i != noOfEmployees)
          {
              ok = 0;
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
         // else ok = true;

      }
      else {
          cout << "Could not open data file: " << DATAFILE << endl;
      }
      closeFile();
      return ok;
   }

   
   void display(const Employee& emp)
   {
       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
   }

   void display()
   {
       int i = 0;
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort(); 
       while (i < noOfEmployees)
       {
           cout << i + 1 << "- "; 
           display(employees[i]);
           i++;
       }
   }
   
   void deallocateMemory() // should be 2
   {
       for (int i = 0; i < noOfEmployees; i++) //to set all the name pointers to null 
       {
           delete [] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete[] employees; 
       employees = nullptr;
   }

  
}