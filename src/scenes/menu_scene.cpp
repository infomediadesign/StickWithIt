#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"

using namespace std::string_literals;

game::scenes::MenuScene::MenuScene() {
    // Your scene initialization code here...
    titlescreen = LoadTexture("assets/graphics/backgrounds/farmhouse_titlescreen.png");
}

game::scenes::MenuScene::~MenuScene() {
    // Your scene cleanup code here...
    UnloadTexture(titlescreen);
}

void game::scenes::MenuScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ENTER))
        game::core::Store::stage->replaceWithNewScene("menu"s, "game"s, std::make_unique<GameScene>());
}

void game::scenes::MenuScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawTexture(titlescreen, 0, 0, WHITE);
    DrawText("Start new game", 30, 40, 30, WHITE);
    DrawText("Continue", 30, 80, 30, WHITE);
    DrawText("Settings", 30, 120, 30, WHITE);
    DrawText("Exit game", 30, 160, 30, WHITE);
    DrawText("Credits", 30, 200, 20, WHITE);
}
