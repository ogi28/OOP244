#include "HtmlText.h"
#include "cstring.h"
namespace sdds {

    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
    {
        m_title = nullptr;
        if (title != nullptr)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    void HtmlText::clear()
    {
        Text::clear();
        if (m_title != nullptr)
        {
            delete[] m_title;
            m_title = nullptr;
        }
    }

    HtmlText::~HtmlText()
    {
        clear();
    }

    HtmlText::HtmlText(const HtmlText& C) : HtmlText(C.filename(), C.m_title)
    {
        *this = C;
    }

    HtmlText& HtmlText::operator=(const HtmlText& C)
    {
        clear();
        Text::operator=(C);
        m_title = new char[strLen(C.m_title) + 1];
        strCpy(m_title, C.m_title);
        return *this;
    }


    void HtmlText::write(std::ostream &os) const
    {
        bool MS = false;
        os << "<html><head><title>" << (m_title !=nullptr ? m_title : "No Title") << "</title></head>\n<body>\n";
        if (m_title != nullptr)
        {
           os << "<h1>" << m_title << "</h1>\n";
        }
        int i = 0;
        char ch = 48;

        while ((ch = (*this)[i]) != '\0')
        {
            if (ch == ' ')
            {
                if (MS)
                {
                    os << "&nbsp;";
                }
                else 
                {
                    MS = true;
                    os << ' ';
                }
            }
            else if (ch == '<')
            {
                os << "&lt;";
                MS = false;
            }
            else if (ch == '>')
            {
                os << "&gt;";
                MS = false;
            }
            else if (ch == '\n')
            {
                os << "<br />\n";
                MS = false;
            }
            else 
            {
                MS = false;
                os << ch;
            }
            i++;
        }

        os << "</body>\n</html>";
    }
}
