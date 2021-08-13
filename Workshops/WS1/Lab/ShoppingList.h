#ifndef NAMESPACE_ShoppingList_H 
#define NAMESPACE_ShoppingList_H

const int MAX_NO_OF_RECS = 15;

namespace sdds
{
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}
#endif