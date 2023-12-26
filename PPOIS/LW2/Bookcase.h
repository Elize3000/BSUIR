#pragma once
#include "Bookshel.h"
#include "Box.h"
class Bookcase
{
private:
	std::vector<Bookshel> list_of_book_shel_;
	int max_ammaunt_of_book_, namber_of_shelds_;
	bool is_theamed_, is_related_to_author_;
	std::string theam_, author_first_name_, author_last_name_;
public:
	Bookcase(int namber_of_book, int namber_of_sheld);
	Bookcase(int namber_of_book, int namber_of_sheld, std::string theam);
	Bookcase(int namber_of_book, int namber_of_sheld, std::string author_first_name, std::string author_last_name);
	Bookcase(int namber_of_book, int namber_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name);

	bool AddBookToBookcase(Book book);
	Book TekeBookFromBookcase(Book book);
	Book TekeBookFromBookcase(std::string Name);
	Book TekeBookFromBookcase(int shel_num, int book_num);
	bool FindBookInBookcase(Book book);
	bool FindBookInBookcase(std::string Name);
	Box MakeTheamed(std::string theam);
	Box MakeRelatedToAuthor(std::string author_first_name, std::string author_last_name);
	bool MakeNotTheamed();
	bool MakeNotRelatedToAuthor();
	bool IsTheamed();
	bool IsRelatesToAuthor();
	int get_namber_of_shel();
};

