#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"

using namespace std::string_literals;

game::scenes::MenuScene::MenuScene() {
    // Your scene initialization code here...
    titlescreen = LoadTexture("assets/graphics/backgrounds/farmhouse_titlescreen.png"); //@Levin delete this
}

game::scenes::MenuScene::~MenuScene() {
    // Your scene cleanup code here...
    UnloadTexture(titlescreen); //@Levin and this
}

void game::scenes::MenuScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ENTER))
        game::core::Store::stage->replaceWithNewScene("menu"s, "game"s, std::make_unique<GameScene>());

    //To implement

    //if (IsKeyPressed(KEY_W)) dann eine Auswahl nach oben
    //if (IsKeyPressed(KEY_S)) dann eine Auswahl nach unten
    //if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) dann Auswahl bestätigen

    //Gucken, wie man andere Schrift miteinbinden kann und wie man Rückmeldung an den User geben kann, welche Auswahl gerade aktiv ist.
}

void game::scenes::MenuScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically

    DrawTexture(titlescreen, 0, 0, WHITE); //@Levin and this
    //@Levin and then create a actor with animated sprite here (when Sarahs finished with animated background)

    DrawText("Start new game", 30, 40, 30, WHITE);
    DrawText("Continue", 30, 80, 30, WHITE);
    DrawText("Settings", 30, 120, 30, WHITE);
    DrawText("Exit game", 30, 160, 30, WHITE);
    DrawText("Credits", 30, 200, 20, WHITE);
}
