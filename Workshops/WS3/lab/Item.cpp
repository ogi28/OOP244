//Ogulcan Tayhan
//104472204
//3.2.2021
//otayhan@myseneca.ca
//Julian Rogers told me to put a null terminator in my strnCpy in cstring. (Microsot Team Workshops chat).

#include <iostream>
#include "cstring.h"
using namespace std;
#include "Item.h"
#include <iomanip> // needed for formatting cout in display
namespace sdds
{
	
	const double tax = 0.13;
	void Item::setName(const char* name)
	{
		strnCpy(m_itemName, name, 20);
		return;
	}

	void Item::setEmpty()
	{
		m_itemName[0] = '\0';
		m_price = 0;
		return;
	}


	void Item::set(const char* name, double price, bool taxed) //mutator function, because it changes a value
	{
		
		if (price <= 0 || name == nullptr || name[0] == '\0') //added nullptr otherwise checks for price, then checks if first letter is null because tester prints enters nullptr. Also check for nullptr before name[0], otherwise it tries to check the memory of a nullptr which crashes the program. 
		{			
			setEmpty();
		}
		else
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
		return;
	}
	
	double Item::price()const
	{
		return m_price; //accesser function to access price because of class privacy
	}
	double Item::tax()const
	{
		double OneEntryOneExit = 0.00;

		return !m_taxed ? OneEntryOneExit = 0.00 : OneEntryOneExit = m_price * TAX;

	}

	bool Item::isValid()const
	{
		return m_itemName[0] != '\0' && m_price > 0;
	}

	void Item::display()const
	{
		
		if (!isValid())
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
		else
		{
			cout << "| " << setfill('.') << setw(20) << left << m_itemName;
			//setfill fills the empty space, dot in this case. 
			//setw sets the width of the string. So 20 characters in this case
			//left will align the output to left.
			cout << " | " << setfill(' ') << setw(7) << right << fixed << setprecision(2) << m_price;
			// fixed = forces precision. (puts .00 if the value doesn't have any numbers after the .)
			cout << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
		}
		return;


	}
	
}