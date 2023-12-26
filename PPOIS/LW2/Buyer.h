#pragma once
#include "Book.h"
#include "Administratar.h"

class Buyer
{
public:
	bool AddBookToTheRequest(Book new_book);
	bool AddBookToTheRequest(std::string name);
	bool SendRequest(Administratar* admin);
private:
	std::vector<std::string> list_of_name_;
	std::vector<Book> list_of_book;
};

