//Ogulcan Tayhan
//104472204
//3.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "cstring.h"
using namespace std;
#include "Bill.h"
#include <iomanip>

namespace sdds {

	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr; //pointer to address of object of class. The object will be set later.
	}

	bool Bill::isValid()const 
	{
		bool OneEntryOneExit = true;
		int i = 0;
		if (m_title[0] != '\0' && m_items != nullptr)
		{
			for (i = 0; i < m_noOfItems && OneEntryOneExit; i++)
			{
				if (!m_items[i].isValid()) OneEntryOneExit = false;
			}

		}
		else OneEntryOneExit = false;

		return OneEntryOneExit;
	}

	double Bill::totalTax()const
	{
		double sum = 0.00;
		int i = 0;
		for (i = 0; i < m_noOfItems ; i++)
		{
			m_items[i].tax() ? sum += m_items[i].tax() : sum;
		}
		return sum;
	}
	
	double Bill::totalPrice()const
	{
		double sum = 0.00;
		int i = 0;
		for (i = 0; i < m_noOfItems; i++)
		{
			m_items[i].price() ? sum += m_items[i].price() : sum;
		}
		return sum;
	}

	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;
		if (!isValid()) cout << "| Invalid Bill                         |" << endl;
		else
		{
			cout << "| " << setw(36) << left << m_title <<" |"<<endl;
		}

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (!isValid()) cout << "| Invalid Bill                         |" << endl;
		else
		{
			cout << "|                Total Tax: " << setw(10) << right << fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << setw(10) << right << fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << setw(10) << right << fixed << setprecision(2) << totalTax()+totalPrice() << " |" << endl;
		}

		cout << "+--------------------------------------+" << endl;


	}

	void Bill::init(const char* title, int noOfItems)
	{

		if (title[0] == '\0' && noOfItems <= 0)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) // sets all the members to empty state by calling the function
			{
				m_items[i].setEmpty();
			}
		}
		return;
 	}
	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		bool OneEntryOneExit = false;
		if (m_noOfItems > m_itemsAdded)
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			OneEntryOneExit = true;
		}
		return OneEntryOneExit;
		
	}
	void Bill::display()const
	{
		int i=0;
		Title();
		for (i = 0; i < m_noOfItems; i++) // has to be noOfItems not items added
		{
			m_items[i].display();
		}
		footer();
		return;
	}

	void Bill::deallocate()
	{
		if (m_items)
		{
			delete[] m_items;	
		}
		m_itemsAdded = 0;
		m_noOfItems = 0;
		return;
	}
}