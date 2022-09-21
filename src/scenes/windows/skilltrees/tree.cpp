#include "tree.h"

st::Tree::Tree(const char* name, const char* texture_path, Texture2D lock, std::shared_ptr<gs::GameState>& gamestate, int treetype)
	:
	name_(name),
	texture_(LoadTexture(texture_path)),
	lock_(lock),
	gamestate_(gamestate),
	treetype_(treetype)
{
}

st::Tree::~Tree()
{
	UnloadTexture(texture_);
}

void st::Tree::Update()
{
	int temp = active_upgrade_;

	if (IsKeyPressed(KEY_UP))
	{
		switch (active_upgrade_)
		{
		case UPGRADE_1:
			active_upgrade_ = UPGRADE_LEFT_1;
			break;
		case UPGRADE_LEFT_1:
			active_upgrade_ = UPGRADE_LEFT_2;
			break;
		case UPGRADE_RIGHT_1:
			active_upgrade_ = UPGRADE_RIGHT_2;
			break;
		}
	}
	else if (IsKeyPressed(KEY_DOWN))
	{
		switch (active_upgrade_)
		{
		case UPGRADE_1:
			active_upgrade_ = EXIT_TREE;
			break;
		case UPGRADE_LEFT_1:
			active_upgrade_ = UPGRADE_1;
			break;
		case UPGRADE_LEFT_2:
			active_upgrade_ = UPGRADE_LEFT_1;
			break;
		case UPGRADE_RIGHT_1:
			active_upgrade_ = UPGRADE_1;
			break;
		case UPGRADE_RIGHT_2:
			active_upgrade_ = UPGRADE_RIGHT_1;
			break;
		}
	}
	else if (IsKeyPressed(KEY_RIGHT))
	{
		switch (active_upgrade_)
		{
		case UPGRADE_1:
			active_upgrade_ = UPGRADE_RIGHT_1;
			break;
		case UPGRADE_LEFT_1:
			active_upgrade_ = UPGRADE_RIGHT_1;
			break;
		case UPGRADE_LEFT_2:
			active_upgrade_ = UPGRADE_RIGHT_2;
			break;
		}
	}
	else if (IsKeyPressed(KEY_LEFT))
	{
		switch (active_upgrade_)
		{
		case UPGRADE_1:
			active_upgrade_ = UPGRADE_LEFT_1;
			break;
		case UPGRADE_RIGHT_1:
			active_upgrade_ = UPGRADE_LEFT_1;
			break;
		case UPGRADE_RIGHT_2:
			active_upgrade_ = UPGRADE_LEFT_2;
			break;
		}
	}

	// Buy upgrades
	if (IsKeyPressed(KEY_ENTER))
	{
		switch (treetype_)
		{
		case gs::GameState::SCYTHE:
			switch (active_upgrade_)
			{
			case UPGRADE_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_MID, true);
				break;
			case UPGRADE_LEFT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_1, true);
				break;
			case UPGRADE_LEFT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_2, true);
				break;
			case UPGRADE_RIGHT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_1, true);
				break;
			case UPGRADE_RIGHT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_2, true);
				break;
			}
			break;

		case gs::GameState::PITCHFORK:
			switch (active_upgrade_)
			{
			case UPGRADE_1:
				gamestate_->SetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_MID, true);
				break;
			case UPGRADE_LEFT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_1, true);
				break;
			case UPGRADE_LEFT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_2, true);
				break;
			case UPGRADE_RIGHT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_1, true);
				break;
			case UPGRADE_RIGHT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_2, true);
				break;
			}
			break;

		case gs::GameState::SHOVEL:
			switch (active_upgrade_)
			{
			case UPGRADE_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_MID, true);
				break;
			case UPGRADE_LEFT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_1, true);
				break;
			case UPGRADE_LEFT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_2, true);
				break;
			case UPGRADE_RIGHT_1:
				gamestate_->SetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_1, true);
				break;
			case UPGRADE_RIGHT_2:
				gamestate_->SetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_2, true);
				break;
			}
			break;
		}

		if (!upgrades_[active_upgrade_]->GetIsUnlocked() && upgrades_[active_upgrade_]->GetCost() <= gamestate_->GetWheatOverall())
		{
			upgrades_[active_upgrade_]->SetIsUnlocked(true);
			gamestate_->SetWheatOverall(gamestate_->GetWheatOverall() - upgrades_[active_upgrade_]->GetCost());
		}
	}

	// If the active_upgrade has been switched deactivate it and activate the new active upgrade (except we want to leave tree)
	if (temp != active_upgrade_)
	{
		upgrades_[temp]->SetIsActive(false);

		if (active_upgrade_ == EXIT_TREE)
		{
			is_active_ = false;
			return;
		}

		upgrades_[active_upgrade_]->SetIsActive(true);
	}
}

void st::Tree::Draw() const
{
	DrawTexture(texture_, 0, 0, WHITE);

	for (auto& upgrade : upgrades_)
	{
		upgrade->Draw();

		if (!upgrade->GetIsUnlocked())
		{
			DrawTexture(lock_, upgrade->GetPosition().first, upgrade->GetPosition().second, { 200, 200, 200, 200 });
		}

		// Draw upgrade data to infobox
		if (upgrade->GetIsActive())
		{
			float y = 90.0f;

			if (upgrade->GetStrength() != 0)
			{
				DrawTextEx(gamestate_->GetFont(), TextFormat("Strength +%i", upgrade->GetStrength()), { 62.0f, y }, 16, 0, WHITE);
				y += 20;
			}
			if (upgrade->GetMovePoints() != 0)
			{
				DrawTextEx(gamestate_->GetFont(), TextFormat("Move Points +%i", upgrade->GetMovePoints()), { 62.0f, y }, 16, 0, WHITE);
				y += 20;
			}
			if (upgrade->GetActionPoints() != 0)
			{
				DrawTextEx(gamestate_->GetFont(), TextFormat("Action Points +%i", upgrade->GetActionPoints()), { 62.0f, y }, 16, 0, WHITE);
			}

			DrawTextEx(gamestate_->GetFont(), TextFormat("Cost: %i", upgrade->GetCost()), { 62.0f, 180 }, 16, 0, WHITE);
		}
	}

	DrawTextEx(gamestate_->GetFont(), TextFormat("Wheat: %i", gamestate_->GetWheatOverall()), { 62.0f, 210 }, 16, 0, WHITE);
}

const char* st::Tree::GetName() const
{
	return name_;
}

bool st::Tree::GetIsActive() const
{
	return is_active_;
}

void st::Tree::SetIsActive(bool status)
{
	is_active_ = status;

	// That means we have entered either a new tree or the same tree again
	if (status == true)
	{
		active_upgrade_ = UPGRADE_1;
		upgrades_[active_upgrade_]->SetIsActive(true);
	}
}
