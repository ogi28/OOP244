#include "PreTriage.h"
#include <cstring>
#include <fstream>
#include "utils.h"
#include "CovidPatient.h"
#include "TriagePatient.h"


namespace sdds{

   PreTriage::PreTriage(const char* dataFilename) : 
      m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), 
      m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
   {
      m_dataFilename = new char[strlen(dataFilename) + 1];
      strcpy(m_dataFilename, dataFilename);
      m_averCovidWait = 15;
      m_averTriageWait = 5;
      load();
   }


   PreTriage::~PreTriage()
   {
      ofstream file(m_dataFilename, ofstream::trunc); // http://www.cplusplus.com/reference/fstream/ofstream/open/

      file << m_averCovidWait << ',' << m_averTriageWait << endl;
      cout << "Saving Average Wait Times,\n   COVID Test: " << m_averCovidWait << endl;
      cout << "   Triage: " << m_averTriageWait << endl; // newline?

      cout << "Saving lineup..." << endl;
      for (int i = 0; i < m_lineupSize; i++)
      {
         m_lineup[i]->csvWrite(file) << endl;
         cout << i+1 << "- ";
         m_lineup[i]->csvWrite(cout) << endl;
         delete m_lineup[i]; // delete one object at a time
         m_lineup[i] = nullptr;
      }
      file.close();
      delete[] m_dataFilename;
      m_dataFilename = nullptr;

      cout << "done!" << endl; //endl?
   }

   const Time PreTriage::getWaitTime(const Patient& p)const
   {
      unsigned int count = 0;
      for (int i = 0; i < m_lineupSize ; i++)
      {
         if (p.type() == m_lineup[i]->type())
         {
            count++;
         }
      }

      return (p.type() == 'C') ? m_averCovidWait * count : m_averTriageWait * count; 
   }


   void PreTriage::setAverageWaitTime(const Patient& p)
   {
      Time CT;
      CT.setToNow();
      Time PTT = (Time)p;
      if (p.type() == 'C')
      {
        m_averCovidWait = ((CT - PTT) + (m_averCovidWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
      }
      else 
      {
        m_averTriageWait = ((CT - PTT) + (m_averTriageWait * ((unsigned)p.number() - 1))) / (unsigned)p.number();
      }
   }

   void PreTriage::removePatientFromLineup(int index)
   {
      if (index < m_lineupSize)
      {
         removeDynamicElement(m_lineup, index, m_lineupSize);
      }
   }

   int PreTriage::indexOfFirstInLine(char type) const
   {
      bool found = false;
      int i = 0;
      for (i = 0; i < m_lineupSize && !found; i++)
      {
         if (m_lineup[i]->type() == type)
            found = true;
      }

      return found ? i : -1;
   }

    
   void PreTriage::load()
   {
      ifstream file(m_dataFilename);
      cout << "Loading data..." << endl;
      file >> m_averCovidWait;
      file.ignore();
      file >> m_averTriageWait;
      file.ignore();
      char type = '0';
      
      Patient* patient;
      bool instantiation = false;
      for (int i = 0; i < maxNoOfPatients && file >> type; i++)
      {
         file.ignore(); // ignores the comma
         if (type == 'C')
         {
            patient = new CovidPatient();
            instantiation = true;
         }
         else if (type == 'T')
         {
            patient = new TriagePatient();
            instantiation = true;
         }
         if (instantiation)
         {
            patient->fileIO(true);
            patient->csvRead(file);
            patient->fileIO(false);
            m_lineup[i] = patient;
            m_lineupSize++;
         }
         else
         {
            file.ignore(100000000, '\n'); // to ignore the line cuz instantiation didn't happen
         }
      }

      if (!file.eof())
      {
         cout << "Warning: number of records exceeded " << maxNoOfPatients;
      }
      else if (m_lineupSize == 0)
      {
         cout << "No data or bad data file!";
      }
      else 
      {
         cout << m_lineupSize << " Records imported...";
      }
      cout << endl << endl;
      file.close();
   }

   void PreTriage::reg()
   {
      if (m_lineupSize >= maxNoOfPatients)
      {
         cout << "Line up full!" << endl;
      }
      else 
      {
         int selection;
         m_pMenu >> selection;

         switch (selection) {
            case 1:
             m_lineup[m_lineupSize] = new CovidPatient();
             break;
            case 2:
             m_lineup[m_lineupSize] = new TriagePatient();
             break;
            case 0:
             return;
          }
         m_lineup[m_lineupSize]->setArrivalTime();
         cout << "Please enter patient information: " << endl;
         m_lineup[m_lineupSize]->fileIO(false);
         cin >> *m_lineup[m_lineupSize];
         cout << endl << "******************************************" << endl;
         cout << *m_lineup[m_lineupSize];
         cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
         cout << "******************************************" << endl << endl;
         m_lineupSize++;
      }
   }

   void PreTriage::admit()
   {
      int selection;
      char type;
      m_pMenu >> selection;
      switch (selection) {
         case 1:
            type = 'C';
          break;
         case 2:
          type = 'T';
          break;
         case 0:
          return;
       }
      int index = indexOfFirstInLine(type);

      if (index == -1);
      else 
      {
         cout << endl << "******************************************" << endl;
         m_lineup[index]->fileIO(false);
         cout << "Calling for " << *m_lineup[index] << "******************************************" << endl << endl;
         setAverageWaitTime(*m_lineup[index]);
         removePatientFromLineup(index);
      }
   }



   void PreTriage::run(void)
   {
      int selection = 0;
      while (m_appMenu >> selection)
      {
         switch (selection) {
               case 1:
                  reg();
                  break;
               case 2:
                  admit();
                  break;
               case 0:
                  return;
         }
      }
   }
}
