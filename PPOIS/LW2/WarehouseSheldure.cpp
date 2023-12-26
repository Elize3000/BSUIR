#include "WarehouseSheldure.h"

std::string WarehouseSheldure::GetShedule()
{
	return worktime_ + " " + workweek_;
}


void WarehouseSheldure::SetWorktime(std::string worktime)
{
	worktime_ = worktime;
}

void WarehouseSheldure::SetWorkweek(std::string workweek)
{
	workweek_ = workweek;
}