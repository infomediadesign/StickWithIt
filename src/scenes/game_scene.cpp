#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"
#include "player.h"

using namespace std::string_literals;

game::scenes::GameScene::GameScene() {
    // Your scene initialization code here...

    actors.insert(std::make_pair("player", std::make_unique<game::core::Player>()));
}

game::scenes::GameScene::~GameScene() {
    // Your scene cleanup code here...
}

void game::scenes::GameScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    actors.at("player")->handleMovement();

    tilesetter->exchangeTile(actors.at("player")->sprite()->position(), level);
}

void game::scenes::GameScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawText("This is the game scene - press ESCAPE for pause", 10, 10, 30, LIGHTGRAY);
    
    tilesetter->drawTilemap(level);
}
