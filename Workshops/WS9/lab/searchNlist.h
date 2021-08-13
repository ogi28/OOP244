#include "Collection.h"
#include <iostream>

using namespace std;

namespace sdds{
   template <typename T, typename U>// Template "forward dec" but not really. Tells the function which template we are using. This is needed everytime I use <T> in a function.
   bool search(Collection<T>& obj, T listArr[], int size, U Key)
   {
      bool flag = false;
      for (int i = 0; i < size; i++)
      {
         if (listArr[i] == Key) // had to swap them around
         {
            obj.add(listArr[i]);
            flag = true;
         }
      }
      return flag;
   }

   template <typename T> 
   void listArrayElements(const char* Title, const T listArr[], int size)
   {
      cout << Title << endl;
      for (int i = 0; i < size; i++)
      {
         cout << i+1 << ": " << listArr[i] << endl; 
      }
   }
}
