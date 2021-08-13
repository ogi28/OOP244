#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream> // added for now

namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      virtual ~Text();
      Text(const Text& C);
      Text& operator=(const Text& C);
      void read();
      virtual void write(std::ostream& os)const;
      void clear();
      char* filename() const;
   };

   std::ostream& operator<<(std::ostream&, const Text&);


}
#endif // !SDDS_PERSON_H__

