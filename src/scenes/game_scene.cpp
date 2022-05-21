#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"

using namespace std::string_literals;

game::scenes::GameScene::GameScene() {
    // Your scene initialization code here...
    std::shared_ptr<game::core::Actor> actor_player = std::make_unique<game::core::Actor>(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>("assets/graphics/player/scarecrow_idle_animation.png"), 29.0f, 41.0f, 1, 9, 6, 320 - 15, 180 - 20.5));
    this->actors.insert(std::make_pair("actor_player", actor_player));

    tilemap = std::make_unique<game::core::Tilesetter>();
}

game::scenes::GameScene::~GameScene() {
    // Your scene cleanup code here...
}

void game::scenes::GameScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    actors.at("actor_player")->playerMovement();
}

void game::scenes::GameScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawText("This is the game scene - press ESCAPE for pause", 10, 10, 30, LIGHTGRAY);

    tilemap->drawTilemap(1);
}
