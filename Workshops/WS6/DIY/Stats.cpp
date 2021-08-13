#include "Stats.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for qsort
#include <iomanip>
#include <string>
//#include <vector>
#include "cstring.h" 

using namespace std;

namespace sdds {

    void Stats::setEmpty()
    {
        if (m_filename != nullptr)
        {
            delete[] m_filename;
            m_filename = nullptr;
        }
        if (num != nullptr)
        {
            delete[] num;
            num = nullptr;
        }

    }

    void Stats::setFilename(const char* fname, bool isCopy)
    {
        if (fname == nullptr || fname[0] == '\0');
        else if (!isCopy)
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else 
        {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename,"C_");
            strCat(m_filename, fname);
        }
    }

    void Stats::setNoOfNoRead()
    {

        char storeChar;
              ifstream inFile;
              inFile.open(m_filename);
              //ifstream vinFile(m_filename) ifstream has a constructor that opens the file
              if (inFile.is_open())
              {
                 while (inFile.get(storeChar)) //stops when it hits null trm (end of file)
                 {
                    if (storeChar == ',')
                       m_noOfNoRead++;
                 }
                 if (m_noOfNoRead == 0) setEmpty();
                 else m_noOfNoRead++;
                 inFile.close();
              }
              else setEmpty();
                        
    }
    
   void Stats::loadData() 
   {
      char dummy;

      if (!*this);
      else 
      {
         if (num != nullptr) 
         { 
            delete[] num;
            num = nullptr;
         } 
         num = new double[m_noOfNoRead];
         ifstream fileObject;
         fileObject.open(m_filename);
         if (fileObject.is_open())
         {
            int i = 0;
            while(fileObject >> num[i]) 
            {
               fileObject >> dummy; 
               i++;
            }
            m_noOfNoRead = i;
           fileObject.close();
         }

      }
   }

   void Stats::saveAs(const char *fileName)const
   {
      ofstream fileOutputObject;
      fileOutputObject.open(fileName);
      /*if (fileOutputObject.is_open())
      {
         // fileOutputObject << defaultfloat;
         for (unsigned i = 0; i < m_noOfNoRead; i++)  
         {
            fileOutputObject << setprecision(10) << num[i] << ',';
         }
         fileOutputObject.close();
      }*/
      // HERE

      ifstream fileInputObject;
      fileInputObject.open(m_filename);

      if (fileInputObject.is_open() && fileOutputObject.is_open()) {
        char ch;
        while (fileInputObject.get(ch)) fileOutputObject << ch;
      }

      fileOutputObject.close();
      fileInputObject.close();
   }

    Stats::Stats(unsigned columnWidth, 
            unsigned noOfColumns, 
            unsigned precision)
    {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        m_filename = nullptr;
        num = nullptr;
        m_noOfNoRead = 0;
        dummy = 0;

    }

    Stats::Stats(const char* filename,
               unsigned columnWidth,
               unsigned noOfColumns,
               unsigned precision) : Stats(columnWidth, noOfColumns, precision)
    {
       if(filename != nullptr) 
       {
           setFilename(filename, false);
           setNoOfNoRead();
           loadData();
       }
           
    }
    Stats::Stats(const Stats& C) : Stats(C.m_columnWidth, C.m_noOfColumns, C.m_precision)
    {
        if (C)
        {
            setFilename(C.m_filename, true);
            C.saveAs(this->m_filename);
            setNoOfNoRead();
            loadData();
        }

    }

    
    Stats& Stats::operator=(const Stats& C)
    {
        if (this != &C && C && *this) // self assignment and bool cast
        {
            // HERE
            m_columnWidth = C.m_columnWidth;
            m_noOfColumns = C.m_noOfColumns;
            m_precision = C.m_precision;
            delete[] num;
            num = nullptr;
            C.saveAs(this->m_filename);
            setNoOfNoRead();
            loadData();
        }
        return *this;
    }

    Stats::~Stats()
    {
        setEmpty();
    }

    double& Stats::operator[](unsigned idx)
    {
       return *this ? num[idx % m_noOfNoRead] : dummy ;  // num and dummy can be altered here. 
    }

    double Stats::operator[](unsigned idx) const
    {
       return *this ? num[idx % m_noOfNoRead] : 0 ;  // return 0 instead of dummy because dummy can be altered.  
    }


   Stats::operator bool()const
   {
      return m_filename != nullptr && m_filename[0] != '\0';
   }


    int compareAs(const void *p1, const void* p2)
    {
        return (int) ( *(double*)p1 - *(double*)p2 );
    }

    int compareDes(const void *p1, const void* p2)
    {
        return (int) ( *(double*)p2 - *(double*)p1 );
    }

   void Stats::sort(bool ascending)
   {
       if (*this)
       {
         // if (ascending)
         // {
         //     qsort(num, m_noOfNoRead, sizeof(double), compareAs);
         // }
         // else 
         // {
         //     qsort(num, m_noOfNoRead, sizeof(double), compareDes);
         // }
         // if (ascending)
         // {
             qsort(num, m_noOfNoRead, sizeof(double), ascending ? compareAs : compareDes);
         // }
       
       }
   }

   unsigned Stats::size()const
   {
       return m_noOfNoRead;
   }

    const char* Stats::name()const
   {
       return (const char*)m_filename;
   }


    double* Stats::getnum()const
    {
        return num;
    }

    std::ostream& Stats::view(std::ostream& ostr, double* arr, unsigned size)const
    {
        if (*this)
        {
          unsigned countColumn = 0;
          cout << '\n';
          for(unsigned i = 0; i < size; i++)
          {
              ostr << setw(m_columnWidth) << setprecision(m_precision) << fixed << arr[i]; 
              countColumn++;
              if (countColumn == m_noOfColumns)
              {
                  ostr << endl;
                  countColumn = 0;
              }
          }

          // HERE
          if (countColumn > 0) {
            ostr << endl;
          }

          // ostr << "Total of " << size << " listed!" << endl;

        }

        return ostr;
    }
    unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
    {

        unsigned i = 0, j = 0;
        if (*this)
        {
         double* matching = nullptr;
        matching = new double[m_noOfNoRead];


        for (i = 0; i < m_noOfNoRead; i++)
        {
            if (num[i] <= max && num[i] >= min)
            {
                matching[j] = num[i];
                j++;
            }
        }
        view(ostr, matching, j);

        // HERE
        ostr << "Total of " << j << " numbers are between " << min << " and " << max << endl;

        delete[] matching;
        }
       
        return j;
    }

    std::istream& Stats::read(std::istream& istr)
    {

      setEmpty();
      string temp;
      getline(istr, temp);
      setFilename(temp.c_str(), false);
      setNoOfNoRead();
      loadData();

      return istr;
    }

   std::ostream& operator <<(std::ostream& ostr, const Stats& stats)
   {
      if (stats) {
        // HERE
        ostr << stats.name() << '\n';
        for (int i = 0; i < strLen(stats.name()); i++)
        {
          ostr << '=';
        }
        ostr << '\n';
         stats.view(ostr, stats.getnum(), stats.size());
         ostr << "Total of " << stats.size() << " listed!" << endl;
      }
       return ostr;
   }

   std::istream& operator >>(std::istream& istr, Stats& stats)
   {
       return stats.read(istr);
   }

}
