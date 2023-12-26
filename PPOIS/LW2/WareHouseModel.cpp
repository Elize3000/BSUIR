#include "WareHouseModel.h"

Box WareHouseModel::SatisfyRequest(vector<string>& list_of_books)
{
	Box box(list_of_books.size());
	for (int i = 0; i < list_of_books.size(); i++)
	{
		Book book = TakeBook(list_of_books[i]);
		if (!(book == emptyBook))
		{
			box.AddBookToBox(book);
		}
	}
	return box;
}

Box WareHouseModel::SatisfyRequest(vector<Book>& list_of_books)
{
	Box box(list_of_books.size());
	for (int i = 0; i < list_of_books.size(); i++)
	{
		Book book = TakeBook(list_of_books[i]);
		if (!(book == emptyBook))
		{
			box.AddBookToBox(book);
		}
	}
	return box;
}
bool WareHouseModel::MakeTheamed(string theam, int num)
{
	if (num >= book_case_list_.size())
		return false();
	AddBox(book_case_list_[num].MakeTheamed(theam));
	return true;
}
bool WareHouseModel::MakeRelatedToAuthor(string first_name, string last_name, int num)
{
	if (num >= book_case_list_.size())
		return false();
	AddBox(book_case_list_[num].MakeRelatedToAuthor(first_name,last_name));
	return true;
}
bool WareHouseModel::MakeNotTheamed(int num)
{
	if (num >= book_case_list_.size())
		return false();
	AddBox(book_case_list_[num].MakeNotTheamed());
	return true;
}
bool WareHouseModel::MakeNotRelatedToAuthor(int num)
{
	if (num >= book_case_list_.size())
		return false();
	AddBox(book_case_list_[num].MakeNotRelatedToAuthor());
	return true;
}