/* Ogulcan Tayhan
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
*/
#ifndef NAMESPACE_File_H 
#define NAMESPACE_File_H
#include "ShoppingRec.h"

const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

namespace sdds
{
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif