#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population
    {
        char ZIP[4];
        int noPop;
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // loads a employee structue with its values from the file
    bool load(Population& pop);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load(const char filename[]);

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const Population& pop);
    // TODO: Declare the prototype for the display function that 
    // first sorts the employees then displays all the employees on the screen
    void display();
    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory();
    //Calculates the total population
    int getSum();



}
#endif // SDDS_POPULATION_H_