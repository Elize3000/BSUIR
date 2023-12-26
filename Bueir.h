#pragma once
#include "Book.h"
#include "Administratar.h"

class Bueir
{
public:
	bool AddBookToTheTRecwest(Book new_book);
	bool AddBookToTheTRecwest(std::string name);
	bool SendRecwest(Administratar* admin);
private:
	std::vector<std::string> list_of_name_;
	std::vector<Book> list_of_book;
};

