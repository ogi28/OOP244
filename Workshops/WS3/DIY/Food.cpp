//Ogulcan Tayhan
//104472204
//6.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "Food.h"
#include "cstring.h"

using namespace std;

namespace sdds
{

	void Food::setFoodName(const char* name)
	{
		strnCpy(nameFood, name, 30);
		return;
	}

	void Food::setEmpty()
	{
		nameFood[0] = '\0';
		calFood = 0;
		return;
	}

	void Food::set(const char* name, int cal, int foodtime)
	{
		
		if (name != nullptr && 0 < foodtime && foodtime < 5 && name[0] != '\0')
		{
			setFoodName(name);
			calFood = cal;
			if (foodtime == 1)
			{
				strCpy(dayTime, "Breakfast");
			}
			else if (foodtime == 2)
			{
				strCpy(dayTime, "Lunch");
			}
			else if (foodtime == 3)
			{
				strCpy(dayTime, "Dinner");
			}
			else
			{
				strCpy(dayTime, "Snack");
			}
		}
		else dayTime[0] = '\0';

		return;

	}
	int Food::calorie()const
	{
		return calFood;
	}

	bool Food::isValid()const
	{
		return nameFood[0] != '\0' && dayTime[0] != '\0' && 0 < calFood && calFood <= 3000;
	}

	void Food::display()const
	{

		if (!isValid())
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
		else
		{
			cout << "| " << setfill('.') << setw(30) << left << nameFood;

			cout << " | " << setfill(' ') << setw(4) << right << calFood;

			cout << " | " << setfill(' ') << setw(10) << left << dayTime << " |" << endl;
		}
		return;
	}
}



//setfill fills the empty space, dot in this case. 
//setw sets the width of the string. So 30 characters in this case
//left will align the output to left.

// fixed = forces precision. 
	//(puts .00 if the value doesn't have any numbers after the .)