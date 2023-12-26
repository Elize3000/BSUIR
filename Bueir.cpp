#include "Bueir.h"

bool Bueir::AddBookToTheTRecwest(Book new_book)
{
	list_of_book.push_back(new_book);
	return true;
}
bool Bueir::AddBookToTheTRecwest(std::string name)
{
	list_of_name_.push_back(name);
	return true;
}
bool Bueir::SendRecwest(Administratar* admin)
{
	return admin->SatisfyRequest(list_of_name_, list_of_book);
}