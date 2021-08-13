#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* zip);
   bool read(int& noPop);
}
#endif // !SDDS_FILE_H_
