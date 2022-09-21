#pragma once

#include "tree.h"

namespace st
{
	class TreePitchfork : public Tree
	{
	public:

		TreePitchfork(const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate);

	};
}