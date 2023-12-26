#include "Buyer.h"

bool Buyer::AddBookToTheRequest(Book new_book)
{
	list_of_book.push_back(new_book);
	return true;
}
bool Buyer::AddBookToTheRequest(std::string name)
{
	list_of_name_.push_back(name);
	return true;
}
bool Buyer::SendRequest(Administratar* admin)
{
	return admin->SatisfyRequest(list_of_name_, list_of_book);
}