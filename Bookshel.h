#pragma once
#include "Book.h"
#include "Box.h"
#include <vector>

class Bookshel
{
private:
	std::vector<Book> list_of_book_;
	int max_amaunt_of_book_;
	bool is_related_to_author_, is_theamed_;
	std::string theam_, author_first_name_, author_last_name_;
public:

	Bookshel(int namber_of_book);
	Bookshel(int namber_of_book, std::string theam);
	Bookshel(int namber_of_book, std::string author_first_name, std::string author_last_name);
	Bookshel(int namber_of_book, std::string theam, std::string author_first_name, std::string author_last_name);
	bool AddBookToShel(Book book);
	Book TekeBookFromShel(Book book);
	Book TekeBookFromShel(int id);
	Book TekeBookFromShel(std::string Name);
	bool FindBookInShel(Book book);
	bool FindBookInShel(std::string Name);
	Box MakeTheamedShel(std::string theam);
	Box MakeRelatedToAuthor(std::string author_first_name, std::string author_last_name);
	bool MakeNotTheamed();
	bool MakeNotRelatedToAuthor();
};

