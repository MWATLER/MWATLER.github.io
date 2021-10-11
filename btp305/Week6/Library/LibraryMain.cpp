//LibraryMain.cpp - main program for the library

#include "BookObserver.h"
#include "Library.h"

using namespace std;

int main() {
	BookObserver bookObserver;
	Library<Book> library("Seneca Library");
	Book book[] = {
		{"Star Wars", 1000121, Book::Type::Science_Fiction},
		{"The Bridges of Madison County", 1000122, Book::Type::Romance},
		{"Star Trek", 1000123, Book::Type::Science_Fiction},
		{"Battlestar Galactica", 1000124, Book::Type::Science_Fiction},
		{"The Old Man and the Sea", 1000125, Book::Type::Fiction},
		{"The Battle of the Ardennes", 1000126, Book::Type::Documentary},
		{"Romeo and Juliet", 1000127, Book::Type::Romance},
		{"Canada Cup 1987", 1000128, Book::Type::Sport},
		{"Olympics 2012 100m Relay", 1000129, Book::Type::Sport},
		{"Neanderthal Man", 1000130, Book::Type::Documentary},
		{"Harry Potter", 1000131, Book::Type::Science_Fiction},
		{"The Adventures of Pinocchio", 1000132, Book::Type::Fiction},
		{"Red Dawn", 1000133, Book::Type::Fiction},
		{"The Little Prince", 1000134, Book::Type::Fiction},
		{"FIFA World Cup 2016", 1000135, Book::Type::Sport},
		{"Cosmos", 1000136, Book::Type::Science_Fiction},
		{"War and Peace", 1000137, Book::Type::Documentary},
		{"Nineteen Eighty Four", 1000138, Book::Type::Science_Fiction},
		{"Gone with the Wind", 1000139, Book::Type::Fiction},
		{"What to Expect When You're Expecting", 1000140, Book::Type::Documentary}
	};

	try {
		library.RegisterObserver(&bookObserver, BookObserver::RegisterBook);
		int numBooks = sizeof book / sizeof book[0];
		for (int i = 0; i < numBooks; ++i) {
			library += book[i];
		}

		auto percentType = [=](BookObserver& bObserver, Book::Type type) -> double{
			return 100.0 * bObserver(type);
		};
		double percent = percentType(bookObserver, Book::Type::Science_Fiction);
		cout << percent << "% of these books were science fiction." << endl;

		percent = percentType(bookObserver, Book::Type::Documentary);
		cout << percent << "% of these books were documentaries." << endl;

		percent = percentType(bookObserver, Book::Type::Romance);
		cout << percent << "% of these books were romance." << endl;

		percent = percentType(bookObserver, Book::Type::Sport);
		cout << percent << "% of these books were sport." << endl;

		percent = percentType(bookObserver, Book::Type::Fiction);
		cout << percent << "% of these books were fiction." << endl;
	}
	catch (bad_alloc error) {
		cout << "EXCEPTION: " << error.what() << endl;
		library.~Library();//destroy the object
	}
	catch (const string error) {
		cout << "EXCEPTION: " << error << endl;
	}

	return 0;
}
