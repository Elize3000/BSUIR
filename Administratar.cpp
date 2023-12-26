#include "Administratar.h"



bool Administratar::SatisfyRequest(std::vector<std::string>& list_of_name,
	std::vector<Book>& list_of_book)
{
	//Добавить if проверить все ли норм
	place_of_work_->AddBox(place_of_work_->SatisfyRequest(list_of_name));
	place_of_work_->AddBox(place_of_work_->SatisfyRequest(list_of_book));
	return true;
}

bool Administratar::GetBox(Box * box)
{
	place_of_work_->AddBox(*box);
	return true;
}

bool Administratar::TryToMoveBox()
{
	place_of_work_->UnpackBoxes();
	return true;
}