#include "Owner.h"

void Owner::SetWorktime(std::string worktime)
{
	place_of_work_->SetWorktime(worktime);
}
void Owner::SetWorkweek(std::string workweek)
{
	place_of_work_->SetWorkweek(workweek);
}
bool Owner::MakeTheamed(string theam, int num)
{
	return place_of_work_->MakeTheamed(theam, num);
}
//Owner::Owner(WareHouseModel* work_place, std::string worktime, std::string workweek)
//{
//}
bool Owner::MakeRelatedToAuthor(string first_name, string last_name, int num)
{
	return place_of_work_->MakeRelatedToAuthor(first_name, last_name, num);
}

bool Owner::MakeNotTheamed(int num)
{
	return place_of_work_->MakeNotTheamed(num);
}
bool Owner::MakeNotRelatedToAuthor(int num)
{
	return place_of_work_->MakeNotRelatedToAuthor(num);
}

bool Owner::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld)
{
	return place_of_work_->AddBookcase(max_ammaunt_of_book, amaunt_of_sheld);
}

bool Owner::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam)
{
	return place_of_work_->AddBookcase(max_ammaunt_of_book, amaunt_of_sheld, theam);
}

bool Owner::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string author_first_name, std::string author_last_name)
{
	return place_of_work_->AddBookcase(max_ammaunt_of_book,amaunt_of_sheld,author_first_name,author_last_name);
}

bool Owner::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name)
{
	return place_of_work_->AddBookcase(max_ammaunt_of_book, amaunt_of_sheld, theam, author_first_name, author_last_name);
}

std::string Owner::GetWorktime()
{
	return place_of_work_->GetShedule();
}
