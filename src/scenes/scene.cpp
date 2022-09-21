#include "scene.h"

scene::Scene::Scene(std::shared_ptr<gs::GameState>& gamestate)
	: gamestate_(gamestate)
{
}
