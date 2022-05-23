#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"
#include "sprite_information.h"


using namespace std::string_literals;

game::scenes::GameScene::GameScene() {
    // Your scene initialization code here...
    std::shared_ptr<game::core::Actor> actor_player = std::make_unique<game::core::Actor>(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>("assets/graphics/player/scarecrow_idle_animation.png"), 29, 40, 1, 9, 6, GetScreenWidth() / 2 - player_sprite_width / 2, GetScreenHeight() / 2 - player_sprite_height / 2));
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

    //TEMP press b and switch level
    if (IsKeyPressed(KEY_B) && level != 2)
    {
        level++;
    }
}

void game::scenes::GameScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawText("This is the game scene - press ESCAPE for pause", 10, 10, 30, LIGHTGRAY);

    tilemap->drawTilemap(level);
}
