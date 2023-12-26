#include "WarehouseBuilding.h"

bool WarehouseBuilding::UnpackBoxes()
{
	while (!list_of_unpacked_box_.empty())
	{
		Box box = list_of_unpacked_box_.front();
		Book book = box.TekeBookFromBox(0);
		while (!(book == emptyBook))
		{
			if (!AddBook(book))
				return false;
			book = box.TekeBookFromBox(0);
		}
		list_of_unpacked_box_.erase(list_of_unpacked_box_.begin());
	}
	return true;
}
bool WarehouseBuilding::AddBook(Book book)
{
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		if (book_case_list_[i].IsTheamed() && book_case_list_[i].IsRelatesToAuthor())
			if (book_case_list_[i].AddBookToBookcase(book))
				return true;
	}
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		if (book_case_list_[i].IsTheamed() || book_case_list_[i].IsRelatesToAuthor())
			if (book_case_list_[i].AddBookToBookcase(book))
				return true;
	}
	for (int i = 0; i < book_case_list_.size(); i++)
	{
			if (book_case_list_[i].AddBookToBookcase(book))
				return true;
	}
	for (int i = 0; i < list_of_unpacked_box_.size(); i++)
	{
		if (list_of_unpacked_box_[i].AddBookToBox(book))
		{
			return true;
		}
	}
	return false;
}
Book WarehouseBuilding::TakeBook(Book book)
{
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		Book bufbook = book_case_list_[i].TekeBookFromBookcase(book);
		if (!(bufbook == emptyBook))
			return bufbook;
	}
	for (int i = 0; i < list_of_unpacked_box_.size(); i++)
	{
		Book bufbook = list_of_unpacked_box_[i].TekeBookFromBox(book);
		if (!(bufbook==emptyBook))
			return bufbook;
	}
	return emptyBook;
}
Book WarehouseBuilding::TakeBook(std::string name)
{
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		Book book = book_case_list_[i].TekeBookFromBookcase(name);
		if (book.author_first_name != "" && book.author_last_name != "" && book.name != ""&& book.theam != "")
			return book;
	}
	for (int i = 0; i < list_of_unpacked_box_.size(); i++)
	{
		Book book = list_of_unpacked_box_[i].TekeBookFromBox(name);
		if (book.author_first_name != "" && book.author_last_name != "" && book.name != "" && book.theam != "")
			return book;
	}
	return emptyBook;
}

bool WarehouseBuilding::AddBox(Box box)
{
	list_of_unpacked_box_.push_back(box);
	return true;
}
bool WarehouseBuilding::CheckIfExist(Book book)
{
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		if (book_case_list_[i].FindBookInBookcase(book))
			return true;
	}
	for (int i = 0; i < list_of_unpacked_box_.size(); i++)
	{
		if (list_of_unpacked_box_[i].FindBookInBox(book))
			return true;
	}
	return false;
}
bool WarehouseBuilding::CheckIfExist(std::string name)
{
	for (int i = 0; i < book_case_list_.size(); i++)
	{
		if (book_case_list_[i].FindBookInBookcase(name))
			return true;
	}
	for (int i = 0; i < list_of_unpacked_box_.size(); i++)
	{
		if (list_of_unpacked_box_[i].FindBookInBox(name))
			return true;
	}
	return false;
}

bool  WarehouseBuilding::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld)
{
	Bookcase bookcase(max_ammaunt_of_book, amaunt_of_sheld);
	book_case_list_.push_back(bookcase);
	return true;
}
bool  WarehouseBuilding::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam)
{
	Bookcase bookcase(max_ammaunt_of_book, amaunt_of_sheld,theam);
	book_case_list_.push_back(bookcase);
	return true;
}
bool  WarehouseBuilding::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string author_first_name, std::string author_last_name)
{
	Bookcase bookcase(max_ammaunt_of_book, amaunt_of_sheld, author_first_name, author_last_name);
	book_case_list_.push_back(bookcase);
	return true;
}
bool  WarehouseBuilding::AddBookcase(int max_ammaunt_of_book, int amaunt_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name)
{
	Bookcase bookcase(max_ammaunt_of_book, amaunt_of_sheld, theam, author_first_name, author_last_name);
	book_case_list_.push_back(bookcase);
	return true;
}
bool WarehouseBuilding::RemoveBookcase(int ind)
{
	if (ind >= book_case_list_.size())
		return false;
	Box box(1000);
	for (int i = 0; i < book_case_list_[ind].get_namber_of_shel(); i++)
	{
		Book book = book_case_list_[ind].TekeBookFromBookcase(0, 0);
		while (true)
		{
			if (book == emptyBook)
				break;
			box.AddBookToBox(book);
			book = book_case_list_[ind].TekeBookFromBookcase(i, 0);
		}
	}
	list_of_unpacked_box_.push_back(box);
	book_case_list_.erase(book_case_list_.begin() + ind);
	return true;
}