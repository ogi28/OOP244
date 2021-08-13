#ifndef SDDS_STATS_H
#define SDDS_STATS_H



#include <iostream>
namespace sdds {
   class Stats {
      char* m_filename;
      double* num; 
      double dummy;

      unsigned m_columnWidth;
      unsigned m_noOfColumns;
      unsigned m_precision;
      unsigned m_noOfNoRead;
      void setFilename(const char* fname, bool isCopy);
      void setNoOfNoRead(); 
      void setEmpty(); // pass reference object of ifstream and remove condition
      void loadData();
      void saveAs(const char *fileName)const;
      


     // std::string m_lines[]; // this makes sense I guess?

      public:
         Stats(unsigned columnWidth = 15,
               unsigned noOfColumns = 4,
               unsigned precision = 2);

         Stats(const char* filename, //can I just other parameters and call default cnstr?
               unsigned columnWidth = 15,
               unsigned noOfColumns = 4,
               unsigned precision = 2);
         Stats(const Stats&);
         ~Stats();
         Stats& operator=(const Stats&);
         double& operator[](unsigned idx);
         double operator[](unsigned idx) const;
         operator bool()const;
         void sort(bool ascending);
         unsigned size()const;
         const char* name()const;
         unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
         std::ostream& view(std::ostream& ostr, double* arr, unsigned size)const;
         std::istream& read(std::istream& istr);
         double* getnum()const;
      
   };
   std::ostream& operator <<(std::ostream& ostr, const Stats& stats);
   std::istream& operator >>(std::istream& istr, Stats& stats);

      int compareAs(const void *p1, const void* p2);
      int compareDes(const void *p1, const void* p2);
}


#endif 
