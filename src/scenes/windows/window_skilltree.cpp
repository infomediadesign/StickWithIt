#include "window_skilltree.h"

window::WindowSkilltree::WindowSkilltree(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowSkilltree::~WindowSkilltree()
{
	UnloadTexture(button_buy);
}

void window::WindowSkilltree::Update()
{
	// Exit skilltree window
	if (IsKeyPressed(KEY_ESCAPE))
	{
		is_active_ = false;
	}

	// Modify upgrades OR switch between trees
	if (tree_->GetIsActive())
	{
		tree_->Update();
	}
	else
	{
		SwitchBetweenTrees();
	}

	// Enter skilltree to interact with upgrades (so we cant change tree and upgrades the same time)
	if (IsKeyPressed(KEY_UP) && !tree_->GetIsActive())
	{
		tree_->SetIsActive(true);
	}
}

void window::WindowSkilltree::Draw() const
{
	tree_->Draw();

	DrawTextEx(gamestate_->GetFont(), tree_->GetName(), { 65.0f, 60.0f }, 16, 0, WHITE);

	DrawTexture(exit_button_, 545, 50, WHITE);
	DrawTexture(button_buy, 495, 50, WHITE);
}

void window::WindowSkilltree::SwitchBetweenTrees()
{
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
	{
		tree_active_++;
	}
	else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
	{
		tree_active_--;
	}

	if (tree_active_ < 0)
	{
		tree_active_ = st::Tree::MAX_TREES - 1;
	}
	if (tree_active_ >= st::Tree::MAX_TREES)
	{
		tree_active_ = 0;
	}

	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
	{
		switch (tree_active_)
		{
		case st::Tree::TREE_SCYTHE:
			tree_ = std::make_unique<st::TreeScythe>("assets/graphics/skilltree/skilltree_scythe.png", lock_, gamestate_);
			break;
		case st::Tree::TREE_PITCHFORK:
			tree_ = std::make_unique<st::TreePitchfork>("assets/graphics/skilltree/skilltree_pitchfork.png", lock_, gamestate_);
			break;
		case st::Tree::TREE_SHOVEL:
			tree_ = std::make_unique<st::TreeShovel>("assets/graphics/skilltree/skilltree_shovel.png", lock_, gamestate_);
			break;
		}
	}
}
