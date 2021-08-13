#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring> // using strLen, strCpy and strCmp
#include "Canister.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	char *m_contentName;	// points to a dynamically allocated Cstring.
	double m_diameter;		// in centimeters
	double m_height;		// in centimeters
	double m_contentVolume; // in CCs
	double PI = 3.14159265;
	bool m_usable; // a flag to identify if the Canister is usable or unusable

	void Canister::setToDefault()
	{
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	void Canister::setName(const char *Cstr)
	{
		if (Cstr && m_usable)
		{
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	bool Canister::isEmpty() const { return m_contentVolume < 0.00001; }

	bool Canister::hasSameContent(const Canister &C) const
	{
		bool isSame = false;
		if (m_contentName != nullptr && C.m_contentName != nullptr)
		{
			if (strcmp(m_contentName, C.m_contentName) == 1)
			{
				isSame = true;
			}
		}
		return isSame;
	}

	Canister::Canister() { setToDefault(); }

	Canister::Canister(const char *contentName)
	{
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char *contentName)
	{
		setToDefault();
		if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30)
		{
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0;
			setName(contentName);
		}
		else
		{
			m_usable = false;
		}
	}

	Canister::~Canister()
	{
		clear();
	}

	Canister &Canister::setContent(const char *contentName)
	{
		if (contentName == nullptr)
		{
			m_usable = false;
		}
		else if (isEmpty() == 1)
		{
			setName(contentName);
		}
		else if (hasSameContent(contentName) == 0)
		{
			m_usable = false;
		}
		return *this;
	}
	Canister &Canister::pour(double quantity)
	{
		if (m_usable && quantity > 0 && quantity + volume() <= capacity())
		{
			m_contentVolume += quantity;
		}
		else
		{
			m_usable = false;
		}
		return *this;
	}

	Canister &Canister::pour(Canister &C)
	{
		if (m_contentName == nullptr || volume() == 0)
		{
			setContent(C.m_contentName);
		}
		if (strcmp(m_contentName, C.m_contentName) == 0)
		{
			if (C.volume() > capacity() - volume())
			{
				C.m_contentVolume -= (capacity() - volume());
				m_contentVolume = capacity();
			}
			else
			{
				pour(C.volume());
				C.m_contentVolume = 0.0;
			}
		}
		else
		{
			if (volume() + C.volume() <= capacity())
			{
				C.m_contentVolume = 0;
			}
			else
			{
				C.m_contentVolume -= (capacity() - volume());
				m_usable = false;
			}

			isEmpty();
		}
		return *this;
	}

	double Canister::volume() const { return m_contentVolume; }

	std::ostream &Canister::display() const
	{
		cout << fixed << setw(7) << setprecision(1) << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable)
		{
			cout << " of Unusable content, discard!";
		}
		if (m_contentName != nullptr && m_usable)
		{
			cout << fixed << " of " << setw(7) << volume() << "cc   " << m_contentName;
		}
		return cout;
	}

	double Canister::capacity() const { return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2); }

	void Canister::clear()
	{
		if (!m_usable)
		{
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentVolume = 0.0;
			m_usable = true;
		}
	}

}