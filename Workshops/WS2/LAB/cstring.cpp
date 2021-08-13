#include "cstring.h"

namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		while ((des[i] = src[i]) != '\0')
		{ // copy the character one by one until it hits to \0
			i++;
		}
	}

	void strnCpy(char* des, const char* src, int len)
	{
		int length = strLen(src);
		if (length < len)
		{  // compare the length of the pattern 
			*des = *src;   // assign the pattern to des
			des[length] = '\0';
		}
		else if (length >= len)
		{  // compare the length of the pattern
			for (int i = 0; i < len; i++)
			{
				des[i] = src[i]; // copy the character one by one until it hits len
			}
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;
		int comp = 0;
		while ((s1[i] || s2[i]) != '\0')
		{ // keep checking while both s1 and s2 are not \0
			if (s1[i] != s2[i])
			{  // if the character doesn't match
				if (s1[i] > s2[i])
				{ // if s1[i] is lager than s2[i]
					comp = 1;
				}
				else if (s1[i] < s2[i])
				{  // if if s1[i] is smaller than s2[i]
					comp = -1;
				}
			}
			i++;
		}
		return comp;
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int comp = 0;
		for (int i = 0; i < len; i++)
		{            // check if the characters don't match
			if (s1[i] != s2[i] && s1[i] > s2[i])
			{ // and s1[i] is larger than s2[i]
				comp = 1;                          // assign 1 to comp
			}
			else if (s1[i] != s2[i] && s1[i] < s2[i])
			{ // check if the characters don't match
				comp = -1;                         // and s1[i] is smaller than s2[i], assign -1 to comp
			}
		}
		return comp;
	}

	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{ // keep checking while s[i] is not \0
			i++;               // i is inclemented by 1
		}
		return i;   // return the index number 
	}

	const char* strStr(const char* str1, const char* str2)
	{
		do
		{
			const char* org = str1;
			const char* pat = str2;
			while (*str1 && *pat && *str1 == *pat)
			{ // if str1 has a value, pat has a value and the first character of str2 matches,
				str1++;     // inclement the address of str1
				pat++;      // inclement the address of pat
			}
			if (!*pat)
			{    // if pat doesn't have a value,
				return org; // returns the original value or str1
			}
			str1 += 1;      // increment the address of str1 
		} while (*str1);
		return nullptr;
	}

	void strCat(char* des, const char* src)
	{
		int i = 0;
		int len = strLen(des);
		while (src[i] != '\0')
		{
			des[len] = src[i];  // assign the character of src[i] to des[len]
			len++;
			i++;
		}
		des[len] = '\0';  // clear the rest of elements
	}
}