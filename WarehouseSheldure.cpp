#include "WarehouseSheldure.h"

void WarehouseSheldure::GetShedule()
{
	std::cout << workweek << "   " << worktime << std::endl;
}

std::string WarehouseSheldure::GetWorktime()
{
	return worktime;
}

void WarehouseSheldure::SetWorktime(std::string worktime)
{
	this->worktime = worktime;
}

void WarehouseSheldure::SetWorkweek(std::string workweek)
{
	this->workweek = workweek;
}