#pragma once
#include "Book.h"
#include "WareHouseModel.h"

class AdminustrationUniuon
{

public:
	virtual std::string GetSheldure() const = 0;
	bool CheckIfExist(Book book);
	bool CheckIfExist(std::string name);
	bool AddBook(Book book);
	bool TakeBook(Book book);
	bool TakeBook(std::string name);
protected:
	WareHouseModel* place_of_work_;
};

