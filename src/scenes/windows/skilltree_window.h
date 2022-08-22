#pragma once

#include "../scene.h"


namespace scenes::windows
{
	class SkilltreeWindow : public scenes::Scene
	{
	public:
		SkilltreeWindow();
		~SkilltreeWindow();

		void Update() override;
		void Draw() override;

	private:
		int skillpoints = 0;

		Texture2D lock = LoadTexture("assets/graphics/skilltree/lock.png");
		Texture2D skilltreeScythe = LoadTexture("assets/graphics/skilltree/skilltree_scythe.png");
		Texture2D skilltreePitchfork = LoadTexture("assets/graphics/skilltree/skilltree_pitchfork.png");
		Texture2D skilltreeShovel = LoadTexture("assets/graphics/skilltree/skilltree_shovel.png");

		struct Upgrade
		{
			int upgradeNumber;
			type::Position pos;
			int cost = 0;
			bool locked = true;
			const char* description = "no description";
			Texture2D texture;
			bool isActive = false;
			std::shared_ptr<Upgrade> upgradeTop = nullptr;
			std::shared_ptr<Upgrade> upgradeDown = nullptr;
			std::shared_ptr<Upgrade> upgradeRight = nullptr;
			std::shared_ptr<Upgrade> upgradeLeft = nullptr;
		};


		struct Tree
		{
			std::vector<std::shared_ptr<Upgrade>> upgrades;
			Texture2D backgroundTexture;
		};

		
		std::shared_ptr<Tree> scythe = std::make_shared<Tree>();
		std::shared_ptr<Tree> shovel = std::make_shared<Tree>();
		std::shared_ptr<Tree> pitchfork = std::make_shared<Tree>();

		std::shared_ptr<Tree> activeTree = scythe;

		std::shared_ptr<Upgrade> activeUpgrade = nullptr;

		std::vector<std::shared_ptr<Tree>> trees = { scythe, pitchfork, shovel };
		
		int activeWeapon = 0;

		void initTrees();
	};
}