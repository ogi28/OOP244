#include "Population.h"
#include "File.h"
#include "cstring.h"
#include <iostream>


using namespace std;
namespace sdds {

	int numEntry;
	Population* pop;

    void sort()
    {
        int i, j;
        Population temp;
        for (i = numEntry - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (pop[j].noPop > pop[j + 1].noPop) // flipped the greater sign to list in a descending order
                {
                    temp = pop[j];
                    pop[j] = pop[j + 1];
                    pop[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& pop)
    {
        bool ok = false;
        char zip[4];
        ok = read(zip) && read(pop.noPop) ? 1 : 0;
        
        if (ok)
        {
            //int Len = strLen(zip);
            //zip = new char[Len + 1];  //dynamic memory allocation for delete later
            strCpy(pop.ZIP, zip);
        }

        return ok;
    }

    bool load(const char filename[])
    {
        bool ok = false;
        int i = 0;
        if (openFile(filename)) // ???
        {

            numEntry = noOfRecords();
            pop = new Population[numEntry]; //dynamic memory 2.0 for more delete later

            while (i < numEntry)
            {
                ok = load(pop[i]); // ok will become true everytime this loop happens.
                i++;
            }
            if (i != numEntry)
            {
                ok = 0;
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            // else ok = true;

        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
        }
        closeFile();
        return ok;
    }

    void display(const Population& popItem1)
    {
        cout << popItem1.ZIP << ":  " << popItem1.noPop << endl;
    }

    void display()
    {

        int i = 0;
        int sum = getSum();
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        while (i < numEntry)
        {
            cout << i + 1 << "- ";
            display(pop[i]);
            i++;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << sum << endl;

    }

    int getSum()
    {
        int i = 0;
        int sum = 0;
        while (i < numEntry)
        {
            sum += pop[i].noPop;
            i++;
        }
        return sum;
    }

    void deallocateMemory() // should be 2
    {
   
        delete[] pop;
        pop = nullptr;
    }


}