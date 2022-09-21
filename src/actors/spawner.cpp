#include "spawner.h"

#include <stdexcept>

actor::Spawner::Spawner(std::shared_ptr<gs::GameState>& gamestate)
	:
	gamestate_(gamestate)
{
}

std::shared_ptr<actor::Player> actor::Spawner::SpawnPlayer(int entity, std::shared_ptr<level::Map>& map) const
{
	std::shared_ptr<actor::Player> player = nullptr;

	switch (entity)
	{
	case FLY:
		player = std::make_shared<Fly>(map, gamestate_);
		break;
	case SCARECROW:
		player = std::make_shared<Scarecrow>(map, gamestate_);
		break;

	default:
		std::cout << "invalid player" << std::endl;
		return nullptr;
	}

	player->Spawn();

	return player;
}

std::shared_ptr<actor::Enemy> actor::Spawner::SpawnEnemy(int entity, std::shared_ptr<level::Map>& map) const
{
	std::shared_ptr<actor::Enemy> enemy = nullptr;

	switch (entity)
	{
	case BAT:
		enemy = std::make_shared<Bat>(map, gamestate_);
		break;
	case BIRD:
		enemy = std::make_shared<Bird>(map, gamestate_);
		break;
	case BOAR:
		enemy = std::make_shared<Boar>(map, gamestate_);
		break;
	case MUSHROOM:
		enemy = std::make_shared<Mushroom>(map, gamestate_);
		break;
	case SPIDER:
		enemy = std::make_shared<Spider>(map, gamestate_);
		break;

	default:
		return nullptr;
	}

	enemy->Spawn();

	return enemy;
}

std::vector<std::shared_ptr<actor::Enemy>> actor::Spawner::SpawnWave(int number_of_enemies, std::shared_ptr<level::Map>& map)
{
	int counter = 0;

	std::vector<std::shared_ptr<actor::Enemy>> enemies;

	while (counter < number_of_enemies)
	{
		int rand_number = GetRandomValue(0, MAX_ENEMIES - 1);

		switch (rand_number)
		{
		case BAT:
			enemies.push_back(std::make_shared<Bat>(map, gamestate_));
			break;
		case BIRD:
			enemies.push_back(std::make_shared<Bird>(map, gamestate_));
			break;
		case BOAR:
			enemies.push_back(std::make_shared<Boar>(map, gamestate_));			
			break;
		case MUSHROOM:
			enemies.push_back(std::make_shared<Mushroom>(map, gamestate_));			
			break;
		case SPIDER:
			enemies.push_back(std::make_shared<Spider>(map, gamestate_));			
			break;
		}

		counter++;
	}

	for (auto& enemy : enemies)
	{
		enemy->Spawn();
	}

	return enemies;
}
