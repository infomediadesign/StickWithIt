#pragma once

#include <raylib.h>
#include <iostream>
#include <memory>
#include <vector>

#include "../../../gamestate.h"
#include "upgrade.h"
#include "../../button.h"

namespace st
{
	class Tree
	{
	public:

		Tree(const char* name, const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate, int treetype);
		virtual ~Tree();

		virtual void Update();
		virtual void Draw() const;

		enum
		{
			TREE_SCYTHE,
			TREE_PITCHFORK,
			TREE_SHOVEL,

			MAX_TREES = 3
		};

		const char* GetName() const;
		bool GetIsActive() const; void SetIsActive(bool status);

	protected:

		const char* name_;

		bool is_active_ = false;

		int treetype_;

		enum
		{
			EXIT_TREE = - 1,

			UPGRADE_1,
			UPGRADE_LEFT_1,
			UPGRADE_LEFT_2,
			UPGRADE_RIGHT_1,
			UPGRADE_RIGHT_2,

			MAX_UPGRADES = 5
		};

		const Texture2D texture_;
		const Texture2D lock_;

		// Vector of upgrades
		std::vector<std::shared_ptr<st::Upgrade>> upgrades_;
		
		int active_upgrade_ = 0;

		std::shared_ptr<gs::GameState> gamestate_;
	};
}