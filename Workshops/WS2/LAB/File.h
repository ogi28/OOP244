//Ogulcan Tayhan
//104472204
//26.1.2021
//otayhan@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* nameEmp);
   bool read(int& numEmp);
   bool read(double& salEmp);

}
#endif // !SDDS_FILE_H_
