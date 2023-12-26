#pragma once
#include <string>
#include <iostream>

class WarehouseSheldure
{
public:
	std::string GetWorktime();
	std::string GetWorkWeek();
	void SetWorktime(std::string worktime);
	void SetWorkweek(std::string workweek);
protected:
	std::string worktime_;
	std::string workweek_;
};

