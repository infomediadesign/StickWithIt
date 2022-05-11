#include "game_scene.h"
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
    std::shared_ptr<game::core::Actor> actor_player = std::make_unique<game::core::Actor>(std::make_unique<game::core::Sprite>(std::make_shared<game::core::Texture2D>("assets/graphics/scarecrow.png"), 320 - 16, 180 - 16));
    this->actors.insert(std::make_pair("actor1", actor_player));

    std::shared_ptr<game::core::Actor> actor2 = std::make_unique<game::core::Actor>(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>("assets/graphics/anim_sprite.png"), 80.0f, 80.0f, 1, 3, 50, 100, 200));
    this->actors.insert(std::make_pair("actor2", actor2));
}

game::scenes::GameScene::~GameScene() {
    // Your scene cleanup code here...
}

void game::scenes::GameScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    std::shared_ptr<Vector2> velocity = std::make_shared<Vector2>(0, 0);

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) 
    {
        velocity->x -= 32;
    }
    else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
    {
        velocity->x += 32;
    }
    else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
    {
        velocity->y -= 32;
    }
    else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
    {
        velocity->y += 32;
    }

    //actors.at("actor1")->sprite_->pos_x += velocity->x;
    //actors.at("actor1")->sprite_->pos_y += velocity->y;
}

void game::scenes::GameScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawText("This is the game scene - press ESCAPE for pause", 10, 10, 30, LIGHTGRAY);
}
