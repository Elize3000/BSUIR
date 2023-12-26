#pragma once
#include "AdminustrationUniuon.h"
//#include "WareHouseModel.h"

class Administratar: public AdminustrationUniuon
{
public:
	Administratar(WareHouseModel* place_of_work)
	{
		place_of_work_ = place_of_work;
	}
	bool SatisfyRequest(std::vector<std::string>& list_of_name,
		std::vector<Book>& list_of_book);
	bool GetBox(Box * box);
	bool TryToMoveBox();
};


