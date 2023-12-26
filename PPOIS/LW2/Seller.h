#pragma once
#include "Administratar.h"
#include "Box.h"

class Seller
{
public:
	~Seller()
	{

	}
	bool AddBook(Book book);
	bool SendBook(Administratar& Admin);
private:
	Box box = Box(1000);
};

