#pragma once
#include "Bookcase.h"
#include "Box.h"

class WarehouseBuilding
{
public:
	bool UnpackBoxes();
	bool AddBook(Book book);
	Book TakeBook(Book book);
	Book TakeBook(std::string name);
	bool AddBox(Box box);
	bool CheckIfExist(Book book);
	bool CheckIfExist(std::string name);


protected:
	std::vector <Bookcase> book_case_list_;
	std::vector <Box> list_of_unpacked_box_;
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string author_first_name, std::string author_last_name);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name);
	bool RemoveBookcase(int num);
};

