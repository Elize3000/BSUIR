#pragma once
#include "Book.h"
#include <vector>


class Box
{
private:
	std::vector<Book> list_of_book_;
	int box_size_;
public:
	Box(int box_size);
	bool AddBookToBox(Book book);
	Book TekeBookFromBox(Book book);
	Book TekeBookFromBox(std::string Name);
	Book TekeBookFromBox(int id);
	bool FindBookInBox(Book book);
	bool FindBookInBox(std::string Name);

	bool operator==(const Box& other) const;
};


