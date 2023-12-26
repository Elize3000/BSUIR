#pragma once
#include <string>


struct Book
{
	std::string name, author_first_name, author_last_name, theam;

	bool operator==(const Book& other) const
	{
		return name == other.name && author_first_name == other.author_first_name && author_last_name == other.author_last_name && theam == other.theam;
	}

	Book(const std::string& name, const std::string& author_first_name, const std::string& author_last_name, const std::string& theam)
		: name(name), author_first_name(author_first_name), author_last_name(author_last_name), theam(theam)
	{
	}
};

const Book emptyBook("", "", "", "");

struct BookCaracteristicsRequest
{
	std::string name, first_name, second_name;
};