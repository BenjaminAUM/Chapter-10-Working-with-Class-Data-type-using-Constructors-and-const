// 3-4-2026 Chapter 10 Library Book System
#include <iostream>
#include <string>
using namespace std;

class Library_Book
{
private:
	string book_title;
	int copies_available;

public:
	Library_Book()
	{
		book_title = "C++ Basics";
		copies_available = 3;
	}

	void set_title(string new_title)
	{
		if (new_title != " ")
		{
			book_title = new_title;
		}
	}

	string get_title()
	{
		return book_title;
	}

	int get_copies()
	{
		return copies_available;
	}

	void borrow_book()
	{
		if (copies_available > 0)
		{
			copies_available -= 1;
		}
		else
		{
			cout << "Not available!" << endl;
			return;
		}
	}
};

int main()
{
	Library_Book book;

	string input_title;
	int borrow_count;

	cout << "Enter Book Title: ";
	cin >> input_title;

	book.set_title(input_title);

	cout << "Enter How many you want to borrow: ";
	cin >> borrow_count;


	for (int index = 0; index < borrow_count; index++)
	{
		book.borrow_book();
	}

	cout << "Book title: " << book.get_title() << endl;
	cout << "Available: " << book.get_copies() << endl;

	return 0;
}
