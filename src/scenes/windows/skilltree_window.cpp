#include "skilltree_window.h"
#include "../../gamestate.h"

#include <fstream>
#include <string>

scenes::windows::SkilltreeWindow::SkilltreeWindow()
{
	initTrees();

	std::string skillpointsString;

	std::ifstream savegameFile("savegame.txt");
	while (std::getline(savegameFile, skillpointsString))
		skillpoints = std::stoi(skillpointsString);

	// Maybe relevant for savegame but ignored for now
	//std::fstream savegame;
	//savegame.open("../../../../src/savegame.txt");

	//if (savegame.fail())
	//	std::cout << "opening savegame failed" << std::endl;
	//
	//std::string skillpointLine;

	//bool startCounting = false;
	//int i = 0;

	//for (std::string line; std::getline(savegame, line);)
	//{
	//	if (i == 2)
	//	{
	//		for (int j = 0; j < line.length(); j++)
	//		{
	//			if (startCounting)
	//			{
	//				skillpointLine.push_back(line[j]);
	//			}

	//			if (line[j] == '=')
	//			{
	//				startCounting = true;
	//			}
	//		}
	//	}

	//	i++;
	//}

	for (auto& tree : trees)
		for (auto& upgrade : tree->upgrades)
			for (auto& number : gamestate::gamestateUpgrades)
				if (upgrade->upgradeNumber == number)
					upgrade->locked = false;

	activeUpgrade = activeTree->upgrades[0];
	activeUpgrade->isActive = true;
}

scenes::windows::SkilltreeWindow::~SkilltreeWindow()
{
	UnloadTexture(lock);
	UnloadTexture(skilltreeScythe);
	UnloadTexture(skilltreePitchfork);
	UnloadTexture(skilltreeShovel);

	for (auto& upgrade : scythe->upgrades)
		UnloadTexture(upgrade->texture);

	for (auto& upgrade : pitchfork->upgrades)
		UnloadTexture(upgrade->texture);

	for (auto& upgrade : shovel->upgrades)
		UnloadTexture(upgrade->texture);

	std::ofstream savegameFile("savegame.txt");
	savegameFile << skillpoints;
	savegameFile.close();

	for (auto& tree : trees)
		for (auto& upgrade : tree->upgrades)
			if (!upgrade->locked)
				gamestate::gamestateUpgrades.push_back(upgrade->upgradeNumber);
}

void scenes::windows::SkilltreeWindow::Update()
{
	if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
	{
		activeUpgrade->isActive = false;

		if (IsKeyPressed(KEY_A))
			activeWeapon--;

		if (IsKeyPressed(KEY_D))
			activeWeapon++;

		if (activeWeapon < 0)
			activeWeapon = 2;

		if (activeWeapon > 2)
			activeWeapon = 0;

		switch (activeWeapon)
		{
		case 0:
			activeTree = scythe;
			break;

		case 1:
			activeTree = pitchfork;
			break;

		case 2:
			activeTree = shovel;
			break;
		}

		activeUpgrade = activeTree->upgrades[0];
		activeUpgrade->isActive = true;
	}

	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_LEFT))
	{
		if (IsKeyPressed(KEY_UP) && activeUpgrade->upgradeTop != nullptr)
		{
			activeUpgrade->isActive = false;
			activeUpgrade = activeUpgrade->upgradeTop;
		}
		if (IsKeyPressed(KEY_DOWN) && activeUpgrade->upgradeDown != nullptr && activeUpgrade->upgradeDown->cost != -1)
		{
			activeUpgrade->isActive = false;
			activeUpgrade = activeUpgrade->upgradeDown;
		}
		if (IsKeyPressed(KEY_RIGHT) && activeUpgrade->upgradeRight != nullptr)
		{
			activeUpgrade->isActive = false;
			activeUpgrade = activeUpgrade->upgradeRight;
		}
		if (IsKeyPressed(KEY_LEFT) && activeUpgrade->upgradeLeft != nullptr)
		{
			activeUpgrade->isActive = false;
			activeUpgrade = activeUpgrade->upgradeLeft;
		}

		activeUpgrade->isActive = true;
	}

	if ((IsKeyPressed(KEY_SPACE)) && skillpoints >= activeUpgrade->cost && activeUpgrade->locked &&
		(activeUpgrade->upgradeDown->locked == false || activeUpgrade->upgradeDown->cost == -1))
	{
		activeUpgrade->locked = false;
		skillpoints -= activeUpgrade->cost;
	}
}

void scenes::windows::SkilltreeWindow::Draw()
{
	DrawTexture(activeTree->backgroundTexture, 0, 0, WHITE);

	DrawText(TextFormat("Skillpoints: %i", skillpoints), 270, 55, 10, BLACK);

	for (auto& upgrade : activeTree->upgrades)
	{
		if (upgrade->isActive)
		{
			DrawText(upgrade->description, 65, 55, 10, BLACK);
			DrawTexture(upgrade->texture, upgrade->pos.first, upgrade->pos.second, WHITE);
		}
		else
			DrawTexture(upgrade->texture, upgrade->pos.first, upgrade->pos.second, LIGHTGRAY);


		if (upgrade->locked)
		{
			if (upgrade->isActive)
			{
				DrawTexture(lock, upgrade->pos.first, upgrade->pos.second, LIGHTGRAY);
				DrawText(TextFormat("Cost: %i", upgrade->cost), 65, 100, 10, BLACK);
			}
			
			else
				DrawTexture(lock, upgrade->pos.first, upgrade->pos.second, DARKGRAY);
		}
	}
}

void scenes::windows::SkilltreeWindow::initTrees()
{
	std::shared_ptr<Upgrade> dummyUpgrade = std::make_shared<Upgrade>();
	dummyUpgrade->cost = -1;

	scythe->backgroundTexture = skilltreeScythe;

	std::shared_ptr<Upgrade> upgrade1 = std::make_shared<Upgrade>();
	upgrade1->cost = 100;
	upgrade1->description = "+20% chance to \n dodge an attack";
	upgrade1->locked = true;
	upgrade1->pos = {453, 132};
	upgrade1->texture = LoadTexture("assets/graphics/skilltree/scythe/dodge.png");
	upgrade1->upgradeNumber = 1;

	std::shared_ptr<Upgrade> upgrade2 = std::make_shared<Upgrade>();
	upgrade2->cost = 100;
	upgrade2->description = "+5 ritual/player \n health points";
	upgrade2->locked = true;
	upgrade2->pos = { 353 , 132 };
	upgrade2->texture = LoadTexture("assets/graphics/skilltree/scythe/dexterity.png");
	upgrade2->upgradeNumber = 2;

	std::shared_ptr<Upgrade> upgrade3 = std::make_shared<Upgrade>();
	upgrade3->cost = 100;
	upgrade3->description = "+4 damage";
	upgrade3->locked = true;
	upgrade3->pos = { 403, 182 };
	upgrade3->texture = LoadTexture("assets/graphics/skilltree/scythe/damage.png");
	upgrade3->upgradeNumber = 3;

	std::shared_ptr<Upgrade> upgrade4 = std::make_shared<Upgrade>();
	upgrade4->cost = 100;
	upgrade4->description = "+30% chance to \n deal double damage";
	upgrade4->locked = true;
	upgrade4->pos = { 453, 70 };
	upgrade4->texture = LoadTexture("assets/graphics/skilltree/scythe/strength.png");
	upgrade4->upgradeNumber = 4;

	std::shared_ptr<Upgrade> upgrade5 = std::make_shared<Upgrade>();
	upgrade5->cost = 100;
	upgrade5->description = "+5% chance to \n steal 1hp";
	upgrade5->locked = true;
	upgrade5->pos = { 353, 70 };
	upgrade5->texture = LoadTexture("assets/graphics/skilltree/scythe/lifesteal.png");
	upgrade5->upgradeNumber = 5;

	scythe->upgrades.push_back(upgrade3);
	scythe->upgrades.push_back(upgrade2);
	scythe->upgrades.push_back(upgrade5);
	scythe->upgrades.push_back(upgrade1);
	scythe->upgrades.push_back(upgrade4);

	upgrade3->upgradeLeft = upgrade2;
	upgrade3->upgradeRight = upgrade1;
	upgrade3->upgradeTop = upgrade2;
	upgrade3->upgradeDown = dummyUpgrade;

	upgrade2->upgradeDown = upgrade3;
	upgrade2->upgradeTop = upgrade5;
	upgrade2->upgradeRight = upgrade1;

	upgrade5->upgradeDown = upgrade2;
	upgrade5->upgradeRight = upgrade4;

	upgrade1->upgradeDown = upgrade3;
	upgrade1->upgradeTop = upgrade4;
	upgrade1->upgradeLeft = upgrade2;

	upgrade4->upgradeDown = upgrade1;
	upgrade4->upgradeLeft = upgrade5;


	//////////////

	shovel->backgroundTexture = skilltreeShovel;

	std::shared_ptr<Upgrade> upgrade6 = std::make_shared<Upgrade>();
	upgrade6->cost = 100;
	upgrade6->description = "+1 action point";
	upgrade6->locked = true;
	upgrade6->pos = { 453, 132 };
	upgrade6->texture = LoadTexture("assets/graphics/skilltree/shovel/clock.png");
	upgrade6->upgradeNumber = 6;
	

	std::shared_ptr<Upgrade> upgrade7 = std::make_shared<Upgrade>();
	upgrade7->cost = 100;
	upgrade7->description = "+5 damage";
	upgrade7->locked = true;
	upgrade7->pos = { 403, 182 };
	upgrade7->texture = LoadTexture("assets/graphics/skilltree/shovel/damage.png");
	upgrade7->upgradeNumber = 7;

	std::shared_ptr<Upgrade> upgrade8 = std::make_shared<Upgrade>();
	upgrade8->cost = 100;
	upgrade8->description = "+2 movepoints";
	upgrade8->locked = true;
	upgrade8->pos = { 353, 70 };
	upgrade8->texture = LoadTexture("assets/graphics/skilltree/shovel/rewind.png");
	upgrade8->upgradeNumber = 8;

	std::shared_ptr<Upgrade> upgrade9 = std::make_shared<Upgrade>();
	upgrade9->cost = 100;
	upgrade9->description = "+10% chance to be \n invincible next enemy \n turn";
	upgrade9->locked = true;
	upgrade9->pos = { 353 , 132 };
	upgrade9->texture = LoadTexture("assets/graphics/skilltree/shovel/shield.png");
	upgrade9->upgradeNumber = 9;

	std::shared_ptr<Upgrade> upgrade10 = std::make_shared<Upgrade>();
	upgrade10->cost = 100;
	upgrade10->description = "+5% chance to \n regenerate 2hp";
	upgrade10->locked = true;
	upgrade10->pos = { 453, 70 };
	upgrade10->texture = LoadTexture("assets/graphics/skilltree/shovel/sleep.png");
	upgrade10->upgradeNumber = 10;

	shovel->upgrades.push_back(upgrade7);
	shovel->upgrades.push_back(upgrade9);
	shovel->upgrades.push_back(upgrade8);
	shovel->upgrades.push_back(upgrade6);
	shovel->upgrades.push_back(upgrade10);

	upgrade7->upgradeLeft = upgrade9;
	upgrade7->upgradeRight = upgrade6;
	upgrade7->upgradeTop = upgrade9;
	upgrade7->upgradeDown = dummyUpgrade;

	upgrade9->upgradeDown = upgrade7;
	upgrade9->upgradeTop = upgrade8;
	upgrade9->upgradeRight = upgrade6;

	upgrade8->upgradeDown = upgrade9;
	upgrade8->upgradeRight = upgrade10;

	upgrade6->upgradeDown = upgrade7;
	upgrade6->upgradeTop = upgrade10;
	upgrade6->upgradeLeft = upgrade9;

	upgrade10->upgradeDown = upgrade6;
	upgrade10->upgradeLeft = upgrade8;

	//////////////////

	pitchfork->backgroundTexture = skilltreePitchfork;

	std::shared_ptr<Upgrade> upgrade11 = std::make_shared<Upgrade>();
	upgrade11->cost = 100;
	upgrade11->description = "+10% chance for \n extended attack";
	upgrade11->locked = true;
	upgrade11->pos = { 353, 70 };
	upgrade11->texture = LoadTexture("assets/graphics/skilltree/pitchfork/bow.png");
	upgrade11->upgradeNumber = 11;

	std::shared_ptr<Upgrade> upgrade12 = std::make_shared<Upgrade>();
	upgrade12->cost = 100;
	upgrade12->description = "+3 damage";
	upgrade12->locked = true;
	upgrade12->pos = { 403, 182 };
	upgrade12->texture = LoadTexture("assets/graphics/skilltree/pitchfork/damage.png");
	upgrade12->upgradeNumber = 12;

	std::shared_ptr<Upgrade> upgrade13 = std::make_shared<Upgrade>();
	upgrade13->cost = 100;
	upgrade13->description = "+10% chance to \n instakill";
	upgrade13->locked = true;
	upgrade13->pos = { 453, 132 };
	upgrade13->texture = LoadTexture("assets/graphics/skilltree/pitchfork/instakill.png");
	upgrade13->upgradeNumber = 13;

	std::shared_ptr<Upgrade> upgrade14 = std::make_shared<Upgrade>();
	upgrade14->cost = 100;
	upgrade14->description = "+20% chance to \n knockback hit enemy";
	upgrade14->locked = true;
	upgrade14->pos = { 453, 70 };
	upgrade14->texture = LoadTexture("assets/graphics/skilltree/pitchfork/punch.png");
	upgrade14->upgradeNumber = 14;

	std::shared_ptr<Upgrade> upgrade15 = std::make_shared<Upgrade>();
	upgrade15->cost = 100;
	upgrade15->description = "+2 movepoints";
	upgrade15->locked = true;
	upgrade15->pos = { 353 , 132 };
	upgrade15->texture = LoadTexture("assets/graphics/skilltree/pitchfork/wings.png");
	upgrade15->upgradeNumber = 15;

	pitchfork->upgrades.push_back(upgrade12);
	pitchfork->upgrades.push_back(upgrade15);
	pitchfork->upgrades.push_back(upgrade11);
	pitchfork->upgrades.push_back(upgrade13);
	pitchfork->upgrades.push_back(upgrade14);

	upgrade12->upgradeLeft = upgrade15;
	upgrade12->upgradeRight = upgrade13;
	upgrade12->upgradeTop = upgrade15;
	upgrade12->upgradeDown = dummyUpgrade;

	upgrade15->upgradeDown = upgrade12;
	upgrade15->upgradeTop = upgrade11;
	upgrade15->upgradeRight = upgrade13;

	upgrade11->upgradeDown = upgrade15;
	upgrade11->upgradeRight = upgrade14;

	upgrade13->upgradeDown = upgrade12;
	upgrade13->upgradeTop = upgrade14;
	upgrade13->upgradeLeft = upgrade15;

	upgrade14->upgradeDown = upgrade13;
	upgrade14->upgradeLeft = upgrade11;
}

