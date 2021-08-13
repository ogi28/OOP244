//got cin.peeks from cplusplus.com after a google search

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }


   int getInt(const char* prompt)
   {
      int input = 0;
      bool flag = true;

      if (prompt != nullptr) 
         cout << prompt;

      while (flag)
      {
        
         cin >> input;

         if (cin.fail())
         {
            cout << "Bad integer value, try again: ";
            
         }

         else if (cin.peek() != '\n') // checks the next character of the cin without consuming.
         {
            cout << "Enter only an integer, try again: ";
         }

         else flag = false;

            cin.clear();
            cin.ignore(10000, '\n');

      } 

      return input;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage,
         bool showRangeAtError)
   {
      int input = 0;
      bool flag = true;

         if (prompt != nullptr) 
            cout << prompt;

         while (flag)
         {
            cin >> input;

            if (cin.fail())
               cout << "Bad integer value, try again: ";
            else if (cin.peek() != '\n') // checks the next character of the cin without consuming.
            {
               cout << "Enter only an integer, try again: ";
               input = 0;
            }
            else if (min > input || input > max)
            {
               if (errorMessage != nullptr)
                  cout << errorMessage;

               if (showRangeAtError)
                  cout <<"[" << min << " <= " << "value" << " <= " << max << "]: ";

               input = 0;
            }
            else flag = false;

            cin.clear();
            cin.ignore(10000, '\n');

         } 

         return input;
   }

   char* getcstr(const char* prompt, istream& istr, char delimiter)
   {
      //istr.clear();
      char c;
      char* cstr;
      int size = 1; // actual size in memory not counting null trm
      int countChar = 0;
     // string line;
     // getline(istr, line);
     // cstr = new char[line.length() + 1];
     // strcpy(cstr, line.c_str());

     if (prompt != nullptr)
        cout << prompt;


      cstr = new char[2]; // one for character one for null terminator
      while(istr.get(c) && c != delimiter)
      {
         if (countChar == size)
         {
            size++;
            char* tempCstr = new char[size + 1];
            //cstr = new char[size];
            strncpy(tempCstr, cstr, countChar);
            delete[] cstr; // done with old data in  cstr
            cstr = tempCstr;
         }
         cstr[countChar] = c;
         countChar++;
      }
      cstr[countChar] = '\0';

      return cstr;
    
   }

}
