#pragma once

#include "tree.h"

namespace st
{
	class TreeScythe : public Tree
	{
	public:

		TreeScythe(const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate);

	};
}