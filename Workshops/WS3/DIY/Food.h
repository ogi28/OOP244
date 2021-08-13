//Ogulcan Tayhan
//104472204
//6.2.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds
{
    class Food
    {
        char nameFood[31];
        char dayTime[10];
        int calFood;
        void setFoodName(const char* name);

    public: 
        void setEmpty();
        void set(const char* name, int cal, int foodtime); 
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}










#endif // !SDDS_FOOD_H
