#pragma once

#include "headers.h"

namespace type
{
	typedef std::pair<int, int> Position;
	typedef std::vector<std::pair<int, int>> Vec_Position;
	typedef std::vector<std::pair<int, int>*> Vec_Ptr_Position;

	typedef std::vector<int> Vec_Int;
	typedef std::vector<std::vector<int>> Vec_Vec_Int;
	typedef std::vector<std::vector<std::vector<int>>> Vec_Vec_Vec_Int;

	typedef std::map<int, std::pair<int, int>> Map_ID_Position;
	typedef std::pair<int, std::vector<std::pair<int, int>>> Pair_Damage_Vec_Position;
}