#include "Box.h"

Box::Box(int box_size)
{
	box_size_ = box_size;
}

bool Box::AddBookToBox(Book book)
{
	if (list_of_book_.size() < box_size_)
	{
		list_of_book_.push_back(book);
		return true;
	}
	return false;
}

Book Box::TekeBookFromBox(Book book)
{
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i] == book)
		{
			list_of_book_.erase(list_of_book_.begin() + i);
			return book;
		}
	}
	return emptyBook;
}

Book Box::TekeBookFromBox(std::string Name)
{
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i].name == Name)
		{
			Book book = list_of_book_[i];
			list_of_book_.erase(list_of_book_.begin() + i);
			return book;
		}
	}
	return emptyBook;
}

Book Box::TekeBookFromBox(int id)
{
	if (id < list_of_book_.size())
	{
		Book book = list_of_book_[id];
		list_of_book_.erase(list_of_book_.begin() + id);
		return book;
	}
	return emptyBook;
}

bool Box::FindBookInBox(Book book)
{
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i] == book)
		{
			return true;
		}
	}
	return false;
}

bool Box::FindBookInBox(std::string Name)
{
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i].name == Name)
		{
			return true;
		}
	}
	return false;
}


bool Box::operator==(const Box& other) const
{
	return list_of_book_ == other.list_of_book_ && box_size_ == other.box_size_;
}
