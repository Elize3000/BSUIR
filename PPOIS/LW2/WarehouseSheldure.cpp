#include "WarehouseSheldure.h"



std::string WarehouseSheldure::GetWorktime()
{
	return worktime_;
}

std::string WarehouseSheldure::GetWorkWeek()
{
	return workweek_;
}

void WarehouseSheldure::SetWorktime(std::string worktime)
{
	worktime_ = worktime;
}

void WarehouseSheldure::SetWorkweek(std::string workweek)
{
	workweek_ = workweek;
}