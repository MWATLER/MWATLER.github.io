//TextBook.h - class declaration for a text book
//
// 15-Feb-21  M. Watler         Created.
#include <iostream>
class TextBook {
	std::string title;
	std::string content;
public:
	TextBook(std::string);
	void ImportBookByString(std::string);
	void ImportBookByLine(std::string);
	void ExportBook(std::string) const;
	void DisplayBook() const;
};