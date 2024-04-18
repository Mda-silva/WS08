#define _CRT_SECURE_NO_WARNINGS
#include "LibraryItem.h"
#include <cstring>

namespace seneca
{
	LibraryItem::LibraryItem()
	{
		m_title = nullptr;
		m_year = 0;
	}

	LibraryItem::LibraryItem(const char* title, const int year)
	{
		if (title != nullptr)
		{
			m_year = year;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	LibraryItem::LibraryItem(const LibraryItem& lib)
	{
		if (!lib.m_title)
		{
			m_title = nullptr;
		}
		else
		{
			m_title = new char[strlen(lib.m_title) + 1];
			strcpy(m_title, lib.m_title);
		}
		m_year = lib.m_year;
	}

	LibraryItem& LibraryItem::operator=(const LibraryItem& lib)
	{
		if (this != &lib)
		{
			delete[] m_title;
			if (!lib.m_title)
			{
				m_title = nullptr;
			}
			else
			
			{
				m_title = new char[strlen(lib.m_title) + 1];
				strcpy(m_title, lib.m_title);
			}
			m_year = lib.m_year;
		}

		return *this;
	}

	LibraryItem::~LibraryItem()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	ostream& LibraryItem::display(ostream& out) const
	{
		out << "Title: " << m_title << " (" << m_year << ")";
		return out;
	}



}
