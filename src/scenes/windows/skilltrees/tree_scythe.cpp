#include "tree_scythe.h"

st::TreeScythe::TreeScythe(const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate)
	:
	Tree("Scythe:", texture_path, lock, gamestate, gs::GameState::SCYTHE)
{
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/scythe/damage.png", 403, 182, 0, 1, 1, 100, gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_MID)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/scythe/dexterity.png", 353, 132, 0, 3, 0, 150, gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_1)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/scythe/dodge.png", 353, 70, 1, 2, 2, 200, gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_2)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/scythe/lifesteal.png", 453, 132, 0, 0, 2, 150, gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_1)));
	upgrades_.push_back(std::make_shared<Upgrade>("assets/graphics/skilltree/scythe/strength.png", 453, 70, 1, 1, 3, 200, gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_2)));
}
