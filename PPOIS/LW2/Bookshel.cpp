#include "Bookshel.h"

Bookshel::Bookshel(int namber_of_book)
{
	max_amaunt_of_book_ = namber_of_book;
	is_related_to_author_ = false;
	is_theamed_ = false;
	author_last_name_ = "";
	author_first_name_ = "";
	theam_ = "";
}

Bookshel::Bookshel(int namber_of_book, std::string theam)
{
	max_amaunt_of_book_ = namber_of_book;
	is_related_to_author_ = false;
	is_theamed_ = true;;
	author_last_name_ = "";
	author_first_name_ = "";
	theam_ = theam;
}

Bookshel::Bookshel(int namber_of_book, std::string author_first_name, std::string author_last_name)
{
	max_amaunt_of_book_ = namber_of_book;
	is_related_to_author_ = true;
	is_theamed_ = false;
	author_last_name_ = author_last_name;
	author_first_name_ = author_first_name;
	theam_ = "";
}

Bookshel::Bookshel(int namber_of_book, std::string theam, std::string author_first_name, std::string author_last_name)
{
	max_amaunt_of_book_ = namber_of_book;
	is_related_to_author_ = true;
	is_theamed_ = true;
	author_last_name_ = author_last_name;
	author_first_name_ = author_first_name;
	theam_ = theam;
}

bool Bookshel::AddBookToShel(Book book)
{
	if(list_of_book_.size() >= max_amaunt_of_book_ || is_theamed_ && book.theam!= theam_ || is_related_to_author_
		&& book.author_first_name != author_first_name_  && book.author_last_name != author_last_name_)
	           return false;
	list_of_book_.push_back(book);
	return true;
}

Book Bookshel::TekeBookFromShel(Book book)
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

Book Bookshel::TekeBookFromShel(int id)
{
	if (id < list_of_book_.size())
	{
		Book book = list_of_book_[id];
		list_of_book_.erase(list_of_book_.begin() + id);
		return book;
	}
	return emptyBook;
}

Book Bookshel::TekeBookFromShel(std::string Name)
{
	//тут че то не то книг нет
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

bool Bookshel::FindBookInShel(Book book)
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

bool Bookshel::FindBookInShel(std::string Name)
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

Box Bookshel::MakeTheamedShel(std::string theam)
{
	Box box(max_amaunt_of_book_);
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i].theam != theam)
		{
			box.AddBookToBox(list_of_book_[i]);
			list_of_book_.erase(list_of_book_.begin() + i);
			i--;
		}
	}
	is_theamed_ = true;
	theam_ = theam;
	return box;
}

Box Bookshel::MakeRelatedToAuthor(std::string author_first_name, std::string author_last_name)
{

	Box box(max_amaunt_of_book_);
	for (int i = 0; i < list_of_book_.size(); i++)
	{
		if (list_of_book_[i].author_first_name != author_first_name || list_of_book_[i].author_last_name != author_last_name)
		{
			box.AddBookToBox(list_of_book_[i]);
			list_of_book_.erase(list_of_book_.begin() + i);
			i--;
		}
	}
	is_related_to_author_ = true;
	author_first_name_ = author_first_name;
	author_last_name_ = author_last_name;
	return box;
}

bool Bookshel::MakeNotTheamed()
{
	is_theamed_ = false;
	theam_ = "";
	return true;
}

bool Bookshel::MakeNotRelatedToAuthor()
{
	is_related_to_author_ = false;
	author_first_name_ = "";
	author_last_name_ = "";
	return true;
}
