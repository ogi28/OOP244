#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* zip)
   {
       int ret = fscanf(fptr, "%3s,", zip);
       return ret ? 1 : 0;
   }

   bool read(int& noPop)
   {
       int ret = fscanf(fptr, "%d", &noPop); // needed the comma in %d to ignore the delimiter comma
       return ret ? 1 : 0;
   }

}


/*
A0A,46587
A0B,19792
A0C,12587
A0E,22294
A0G,35266
A0H,17804
A0J,7880
A0K,26058
A0L,7643
A0M,6200
A0N,13815
A0P,13721
A0R,2543
A1A,30382
A1B,19867
*/