#include "AdminustrationUniuon.h"

bool AdminustrationUniuon::CheckIfExist(Book book)
{
	return place_of_work_->CheckIfExist(book);
}
bool AdminustrationUniuon::CheckIfExist(std::string name)
{
	return place_of_work_->CheckIfExist(name);
}

bool AdminustrationUniuon::AddBook(Book book)
{
	return place_of_work_->AddBook(book);
}
bool AdminustrationUniuon::TakeBook(Book book)
{
	Book bookb = place_of_work_->TakeBook(book);
	if (bookb == emptyBook)
		return false;
	return true;
}
bool AdminustrationUniuon::TakeBook(std::string name)
{
	Book book = place_of_work_->TakeBook(name);
	if (book == emptyBook)
		return false;
	return true;
}
