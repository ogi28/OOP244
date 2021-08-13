//Ogulcan Tayhan
//104472204
//26.1.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
    bool openFile(const char filename[]) 
    {
      fptr = fopen(filename, "r");
      return fptr != NULL;
    }
    int noOfRecords() 
    {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) 
      {
         noOfRecs += (ch == '\n'); // counts new lines
      }
      rewind(fptr); // the entire file was read in the while loop, so we move cursor to beginning. By doing this, we make sure the file is readable rest of the code.
      return noOfRecs;
    }
    void closeFile() 
    {
      if (fptr) fclose(fptr);
    }
   

   bool read(char* nameEmp)
   { 
       int ret = fscanf(fptr, "%[^\n]\n", nameEmp);
       return ret ? 1 : 0;   
   }

   bool read(int& numEmp) 
   {
       int ret = fscanf(fptr, "%d,", &numEmp); // needed the comma in %d to ignore the delimiter comma
       return ret ? 1 : 0;
   }

   bool read(double& salEmp) 
   {
       int ret = fscanf(fptr, "%lf,", &salEmp); // comma again
       return ret ? 1 : 0;
   }
   
}