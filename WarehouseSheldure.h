#pragma once
#include <string>
#include <iostream>

class WarehouseSheldure
{
public:
	void GetShedule();
	std::string GetWorktime();
	void SetWorktime(std::string worktime);
	void SetWorkweek(std::string workweek);
protected:
	std::string worktime;
	std::string workweek;
};

