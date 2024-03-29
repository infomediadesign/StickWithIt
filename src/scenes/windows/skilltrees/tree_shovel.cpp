#include "tree_shovel.h"

st::TreeShovel::TreeShovel(const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate)
	:
	Tree("Shovel:", texture_path, lock, gamestate, gs::GameState::SHOVEL)
{
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/shovel/damage.png", 403, 182, 1, 0, 0, 100, gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_MID)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/shovel/clock.png", 353, 132, 1, 1, 0, 150, gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_1)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/shovel/rewind.png", 353, 70, 1, 1, 1, 200, gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_2)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/shovel/shield.png", 453, 132, 1, 0, 1, 150, gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_1)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/shovel/sleep.png", 453, 70, 1, 2, 1, 200, gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_2)));
}
