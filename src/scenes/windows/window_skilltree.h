#pragma once

#include "window.h"
#include "skilltrees/trees.h"

namespace window
{
	class WindowSkilltree : public Window
	{
	public:

		WindowSkilltree(std::shared_ptr<gs::GameState>& gamestate);
		~WindowSkilltree();

		void Update() override;
		void Draw() const override;

	private:

		void SwitchBetweenTrees();

		// Mark upgrades as locked
		const Texture2D lock_		= LoadTexture("assets/graphics/skilltree/lock.png");
		const Texture2D button_buy	= LoadTexture("assets/graphics/ui/button_buy.png");

		std::unique_ptr<st::Tree> tree_ = std::make_unique<st::TreeScythe>("assets/graphics/skilltree/skilltree_scythe.png", lock_, gamestate_);

		int tree_active_ = 0;
	};
}