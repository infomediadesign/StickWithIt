#pragma once

#include "headers.h"

namespace type
{
	std::pair<int, int> Position;
	std::pair<int*, int*> Ptr_Position;

	std::vector<std::pair<int, int>> Vec_Position;
	std::vector<std::pair<int*, int*>> Vec_Ptr_Position;

	std::vector<int> Vec_Int;
	std::vector<std::vector<int>> Vec_Vec_Int;

	std::map<int, std::pair<int, int>> Map_ID_Position;
}