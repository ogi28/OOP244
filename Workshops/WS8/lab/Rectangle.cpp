#include "Rectangle.h"
#include <cstring>
#include <iomanip>

namespace sdds {

Rectangle::Rectangle() : LblShape() {
  m_width = 0;
  m_height = 0;
}
Rectangle::Rectangle(const char *cstr, unsigned width, unsigned height)
    : LblShape(cstr) {
  if (height > 3 && width > (strlen(cstr) + 2)) {
    m_width = width;
    m_height = height;
  } else {
    m_height = 0;
    m_width = 0;
  }
}

void Rectangle::getSpecs(istream &in) {
  LblShape::getSpecs(in);
  in >> m_width;
  in.ignore();
  in >> m_height;
  in.clear();
  in.ignore(50000000, '\n');
}
void Rectangle::draw(ostream &os) const {
  if (m_height > 0 && m_width > 0) {
    unsigned i = 0;
    unsigned j = 0;
    os << '+';
    while (i < (m_width - 2)) {
      os << '-';
      i++;
    }
    i = 0;
    os << '+' << endl;
    os << '|' << label();
    while (i < (m_width - 2 - strlen(label()))) {
      os << ' ';
      i++;
    }
    i = 0;
    os << '|' << endl;
    while (i < (m_height - 3)) {
      os << '|';
      while (j < (m_width - 2)) {
        os << ' ';
        j++;
      }
      j = 0;
      os << '|';
      i++;
      if (i < (m_height - 3))
        os << endl;
    }
    os << endl;
    i = 0;
    os << '+';
    while (i < (m_width - 2)) {
      os << '-';
      i++;
    }
    os << '+';
  }
}
} // namespace sdds
