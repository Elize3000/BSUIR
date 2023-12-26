#pragma once
#include "AdminustrationUniuon.h"

class Owner: public AdminustrationUniuon
{
public:
	Owner(WareHouseModel* work_place, std::string worktime, std::string workweek)
	{
		place_of_work_ = work_place;

	}
	void SetWorktime(std::string worktime);
	void SetWorkweek(std::string workweek);
	bool MakeTheamed(string theam, int num);
	bool MakeRelatedToAuthor(string first_name, string last_name, int num);
	bool MakeNotTheamed(int num);
	bool MakeNotRelatedToAuthor(int num);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string author_first_name, std::string author_last_name);
	bool AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name);
	std::string GetSheldure() const override;
};

