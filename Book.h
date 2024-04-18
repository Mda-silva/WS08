#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include "LibraryItem.h"

using namespace std;
namespace seneca
{
	class Book : public LibraryItem
	{
		char* m_author;

	public:
		Book(const char* title, const int year, const char* author);
		Book(const Book& book);
		Book& operator=(const Book& book);
		virtual ~Book();
		ostream& display(ostream& ostr = cout) const override;
		bool operator >(const Book& other) const;
	};

}

#endif