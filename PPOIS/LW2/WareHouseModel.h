#pragma once
#include "WarehouseBuilding.h"
#include "WarehouseSheldure.h"

using namespace std;

class WareHouseModel : public WarehouseBuilding, public WarehouseSheldure
{
public:
	friend class Owner;
	friend class Administratar;
private:
	Box SatisfyRequest(vector<string>& list_of_books);
	Box SatisfyRequest(vector<BookCaracteristicsRequest>& list_of_books);
	Box SatisfyRequest(vector<Book>& list_of_books);
	bool MakeTheamed(string theam, int num);
	bool MakeRelatedToAuthor(string first_name, string last_name, int num);
	bool MakeNotTheamed(int num);
	bool MakeNotRelatedToAuthor(int num);
};
