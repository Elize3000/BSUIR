#include "Bookcase.h"

Bookcase::Bookcase(int namber_of_book, int namber_of_sheld)
{
	max_ammaunt_of_book_ = namber_of_book;
	namber_of_shelds_ = namber_of_sheld;
	is_related_to_author_ = false;
	is_theamed_ = false;
	author_last_name_ = "";
	author_first_name_ = "";
	theam_ = "";
	for (int i = 0; i < namber_of_sheld; i++)
	{
		list_of_book_shel_.push_back(Bookshel(namber_of_book));
	}
}

Bookcase::Bookcase(int namber_of_book, int namber_of_sheld, std::string theam)
{
	max_ammaunt_of_book_ = namber_of_book;
	namber_of_shelds_ = namber_of_sheld;
	is_related_to_author_ = false;
	is_theamed_ = true;
	author_last_name_ = "";
	author_first_name_ = "";
	theam_ = theam;
	for (int i = 0; i < namber_of_sheld; i++)
	{
		list_of_book_shel_.push_back(Bookshel(namber_of_book, theam));
	}
}

Bookcase::Bookcase(int namber_of_book, int namber_of_sheld, std::string author_first_name, std::string author_last_name)
{
	max_ammaunt_of_book_ = namber_of_book;
	namber_of_shelds_ = namber_of_sheld;
	is_related_to_author_ = true;
	is_theamed_ = false;
	author_last_name_ = author_first_name;
	author_first_name_ = author_last_name;
	theam_ = "";
	for (int i = 0; i < namber_of_sheld; i++)
	{
		list_of_book_shel_.push_back(Bookshel(namber_of_book, author_first_name, author_last_name));
	}
}

Bookcase::Bookcase(int namber_of_book, int namber_of_sheld, std::string theam, std::string author_first_name, std::string author_last_name)
{
	max_ammaunt_of_book_ = namber_of_book;
	namber_of_shelds_ = namber_of_sheld;
	is_related_to_author_ = true;
	is_theamed_ = true;
	author_last_name_ = author_first_name;
	author_first_name_ = author_last_name;
	theam_ = theam;
	for (int i = 0; i < namber_of_sheld; i++)
	{
		list_of_book_shel_.push_back(Bookshel(namber_of_book,theam, author_first_name, author_last_name));
	}
}

bool Bookcase::AddBookToBookcase(Book book)
{
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		if (list_of_book_shel_[i].AddBookToShel(book))
			return true;
	}
	return false;
}

Book Bookcase::TekeBookFromBookcase(Book book)
{
	Book bookbuf = emptyBook;
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		bookbuf = list_of_book_shel_[i].TekeBookFromShel(book);
		if ((bookbuf == emptyBook) == false)
			return book;
	}
	return emptyBook;
}

Book Bookcase::TekeBookFromBookcase(std::string Name)
{
	Book book = emptyBook;
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		book = list_of_book_shel_[i].TekeBookFromShel(Name);
		if ((book == emptyBook) == false)
			return book;
	}
	return emptyBook;
}

Book Bookcase::TekeBookFromBookcase(int shel_num, int book_num)
{
	if (shel_num >= namber_of_shelds_)
		return emptyBook;
	return list_of_book_shel_[shel_num].TekeBookFromShel(book_num);

}

bool Bookcase::FindBookInBookcase(Book book)
{
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		if (list_of_book_shel_[i].FindBookInShel(book))
			return true;
	}
	return false;
}

bool Bookcase::FindBookInBookcase(std::string Name)
{
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		if (list_of_book_shel_[i].FindBookInShel(Name))
			return true;
	}
	return false;
}

Box Bookcase::MakeTheamed(std::string theam)
{
	Box box(max_ammaunt_of_book_ * namber_of_shelds_);
	Box buf_box(max_ammaunt_of_book_);
	Book book = emptyBook;
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		buf_box = list_of_book_shel_[i].MakeTheamedShel(theam);
		while (true)
		{
			book = buf_box.TekeBookFromBox(0);
			if (book == emptyBook)
				break;
			box.AddBookToBox(book);
		}
	}
	is_theamed_ = true;
	theam_ = theam;
	return box;
}

Box Bookcase::MakeRelatedToAuthor(std::string author_first_name, std::string author_last_name)
{
	Box box(max_ammaunt_of_book_ * namber_of_shelds_);
	Box buf_box(max_ammaunt_of_book_);
	Book book = emptyBook;
	for (int i = 0; i < namber_of_shelds_; i++)
	{
		buf_box = list_of_book_shel_[i].MakeRelatedToAuthor(author_first_name, author_last_name);
		while (true)
		{
			book = buf_box.TekeBookFromBox(0);
			if (book == emptyBook)
				break;
			box.AddBookToBox(book);
		}
	}
	is_related_to_author_ = true;
	author_first_name_ = author_first_name;
	author_last_name_ = author_first_name;
	return box;
}

bool Bookcase::MakeNotTheamed()
{
	for (int i = 0; i < namber_of_shelds_; i++)
		list_of_book_shel_[i].MakeNotTheamed();
	is_theamed_ = false;
	theam_ = "";
	return true;
}

bool Bookcase::MakeNotRelatedToAuthor()
{
	for (int i = 0; i < namber_of_shelds_; i++)
		list_of_book_shel_[i].MakeNotRelatedToAuthor();
	is_related_to_author_ = false;
	author_first_name_ = "";
	author_last_name_ = "";
	return true;
}

bool Bookcase::IsTheamed()
{
	return is_theamed_;
}

bool Bookcase::IsRelatesToAuthor()
{
	return is_related_to_author_;
}

int Bookcase::get_namber_of_shel()
{
	return namber_of_shelds_;
}
