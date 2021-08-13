//Ogulcan Tayhan
//104472204
//6.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;


namespace sdds
{
	void CalorieList::setEmpty()
	{
		disLen[0] = '\0';
		food = nullptr; 
		return;
	}

	bool CalorieList::isValid()const
	{
		bool OneEntryOneExit = true;
		int i = 0;
		if (disLen[0] != '\0' && food != nullptr)
		{
			for (i = 0; i < totalFood && OneEntryOneExit; i++)
			{
				if (!food[i].isValid()) OneEntryOneExit = false;
			}

		}
		else OneEntryOneExit = false;

		return OneEntryOneExit;
	}
	int CalorieList::totalCal()const
	{
		int sum = 0;
		int i = 0;
		for (i = 0; i < totalFood; i++)
		{
			food[i].calorie() ? sum += food[i].calorie() : sum;
		}
		return sum;
	}

	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+" << endl;
		if (!isValid()) cout << "| Invalid Calorie Consumption list                   |" << endl;
		else
		{
			cout << "|  " << setw(50) << left << disLen << "|" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
		return;
	}

	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (!isValid()) cout << "|    Invalid Calorie Consumption list                |" << endl; // |    Invalid Calorie Consumption list                |
		else
		{
			cout << "|    Total Calories for today:   " << setw(6) << right << totalCal() << " |            |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;

		return;
	}


	void CalorieList::init(int size)
	{

		if (size <= 0)
		{
			setEmpty();
		}
		else
		{
			totalFood = size;
			addedFood = 0;
			strCpy(disLen, "Daily Calorie Consumption");
			food = new Food[size];
			for (int i = 0; i < size ; i++) // sets all the members to empty state by calling the function
			{
				food[i].setEmpty();
			}
		}
		return;
	}
	
	bool CalorieList::add(const char* item_name, int cal, int when)
	{
		bool OneEntryOneExit = false;
		if (totalFood > addedFood)
		{
			food[addedFood].set(item_name, cal, when);
			addedFood++;
			OneEntryOneExit = true;
		}
		return OneEntryOneExit;

	}

	void CalorieList::display()const
	{
		int i = 0;
		Title();
		for (i = 0; i < totalFood; i++) // has to be noOfItems not items added
		{
			food[i].display();
		}
		footer();
		return;
	}

	void CalorieList::deallocate()
	{
		if (food)
		{
			delete[] food;
		}
		totalFood = 0;
		addedFood = 0;
		return;
	}
}