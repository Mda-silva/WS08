#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>
using namespace std;
namespace seneca
{
	class LibraryItem
	{
	public:
		LibraryItem();
		LibraryItem(const char* title, const int year);
		LibraryItem(const LibraryItem& lib);
		LibraryItem& operator=(const LibraryItem& lib);
		virtual ~LibraryItem();
		virtual ostream& display(ostream& out = cout) const;

	protected:
		char* m_title;
		int m_year;
	};
}

#endif // !SENECA_LIBRARYITEM_H


