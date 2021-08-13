//Ogulcan Tayhan
//104472204
//3.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "cstring.h"


namespace sdds
{
    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src)
    {
        int i = 0;
        while (src[i])
        {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';

        return;
    }
    // Copies the source character string into the destination upto "len"
         // characters. The destination will be null terminated only if the number
         // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;

        while (len > i && src[i] != '\0')
        {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
        return;
    }
    // Compares two C-strings 
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2)
    {
        int i = 0, x = 0;

        while (s1[i] != '\0' || s2[i] != '\0')
        { // I just wanted to use the nested ?: that I learned from Prof. Fardad's sunday lecture. 
          s1[i] > s2[i] ? x = 1 : (s1[i] < s2[i] ? x = -1 : x = 0); 
          i++;
        }
        return x; 
    }
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0, x = 0;

        while (len > i)
        {
            s1[i] > s2[i] ? x = 1 : (s1[i] < s2[i] ? x = -1 : x = 0);
            i++;
        }
        return x;
    }
    // returns the lenght of the C-string in characters
    int strLen(const char* s)
    {
        int i = 0, Len;
        
        while (s[i]) i++;
     
        Len = i;

        return Len;
    }
    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2)
    {
        //const char* ret = nullptr;
        int str2Len = strLen(str2);
        int numCharsMatched = 0;

        const char* pStr1 = str1;
        const char* pStr2 = str2;

        while(*pStr1)
        {
            //printf("checking %c\n", *pStr1);
            if (*(pStr1+numCharsMatched) != *(pStr2))
            {
                pStr1++;
                pStr2 = str2;
                numCharsMatched = 0;

            }
            else
            {
                /* chars match*/
                numCharsMatched++;
                if (numCharsMatched == str2Len)
                    return pStr1;
                else
                    pStr2++;

            }

        }
        return nullptr;

    }

    void strCat(char* des, const char* src)
    {
        int i = 0, j;

        while (des[i]) i++;

        for (j = 0; src[j] != '\0'; j++, i++) des[i] = src[j];

        des[i] = '\0';
        return;
    }
}





int* a;




// if ( s1[i] > s2[i] ? x = 1 : (s1[i] < s2[i] ? x = -1 : x = 0);