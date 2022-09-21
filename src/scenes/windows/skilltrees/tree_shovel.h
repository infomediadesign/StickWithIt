#pragma once

#include "tree.h"

namespace st
{
	class TreeShovel : public Tree
	{
	public:

		TreeShovel(const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate);

	};
}