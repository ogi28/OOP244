#include <iostream>
#include <string>
#include <istream>
#include "cstring.h"
#include "Label.h"

using namespace std;

namespace sdds{
 

    Label::Label()
    {
        this->UIchars = nullptr;
        this->content = nullptr;
        char defaultChar[] = "+-+|+-+|";
        this->UIchars = new char[strLen(defaultChar) + 1];
        strCpy(this->UIchars, defaultChar);
    }

    Label::Label(const char* frameArg)
    {
        this->UIchars = nullptr;
        this->content = nullptr;
        this->UIchars = new char[strLen(frameArg) + 1];
        strCpy(this->UIchars, frameArg);
    }
        
    Label::Label(const char* frameArg, const char* content)
    {
        this->content = nullptr;
        this->content = new char[strLen(content) + 1]; // deallocate
        strCpy(this->content, content);

        this->UIchars = nullptr;
        this->UIchars = new char[strLen(frameArg) + 1]; // deallocate
        strCpy(UIchars, frameArg);
    }

    Label::~Label()
    {
        if (this->content != nullptr)
        {
            delete[] this->content;
            this->content = nullptr;

        }
        if (this->UIchars != nullptr)
        {
            delete[] this->UIchars;
            this->UIchars = nullptr;
        }
        
    }

    void Label::readLabel()
    {
        char content[71];
        cout << "> ";
        cin.getline(content, 71);
        if (this->content != nullptr)
        {
            delete[] this->content;
        }
       
        this->content = new char[strLen(content) + 1];
        strCpy(this->content, content);

    }
    std::ostream& Label::printLabel()const
    {
        int conLen;
        int i = 0;
        if (this->content != nullptr && this->content[0] != '\0')
        {
            cout << UIchars[0]; // prints / 
            conLen = strLen(content);
            while (i < conLen + 2)
            {
                cout << UIchars[1]; // prints ----
                i++;
            }
            i = 0;
            cout << UIchars[2] << endl; // prints "\"
            cout << UIchars[7]; // prints | (the last one)
            while (i < conLen + 2)
            {
                cout << ' '; // prints a bunch of spaces
                i++;
            }
            i = 0;
            cout << UIchars[3] << endl; // prints | (the middle one)
            cout << UIchars[7] << ' ' << this->content << ' ' << UIchars[3] << endl; //content
            cout << UIchars[7]; // |
            while (i < conLen + 2)
            {
                cout << ' ';
                i++;
            }
            i = 0;
            cout << UIchars[3] << endl; // prints | (the middle one)
            cout << UIchars[6]; // prints bottom left "\"
            while (i < conLen + 2)
            {
                cout << UIchars[5]; // bottom -
                i++;
            }
            cout << UIchars[4]; // bottom right /
        }


        return cout;
    }

}

