#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>

namespace seneca
{
	Book::Book(const char* title, const int year, const char* author) : LibraryItem(title, year)
	{
		if (author != nullptr)
		{
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
		}
	}

	Book::Book(const Book& book)
	{
		if (!book.m_author)
		{
			m_author = nullptr;
		}
		else
		
		{
			m_author = new char[strlen(book.m_author) + 1];
			strcpy(m_author, book.m_author);
			LibraryItem::operator=(book);
		}
	}

	Book& Book::operator=(const Book& book)
	{
		if (this != &book)
		{
			delete[] m_author;
			if (!book.m_author)
			{
				m_author = nullptr;
			}
			else
			
			{
				m_author = new char[strlen(book.m_author) + 1];
				strcpy(m_author, book.m_author);
			}

			LibraryItem::operator=(book);
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	ostream& Book::display(ostream& out) const
	{
		LibraryItem::display(out);
		out << "\nAuthor: " << m_author;
		return out;
	}

	bool Book::operator>(const Book& other) const
	{
		bool check = false;
		if (m_author != nullptr && other.m_author != nullptr)
		{
			if (strcmp(m_author, other.m_author) < 0)
			{
				check = false;
			}
			else
			{
				check = true;
			}
		}

		return check;
	}
}