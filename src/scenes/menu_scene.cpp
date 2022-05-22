#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"

using namespace std::string_literals;

game::scenes::MenuScene::MenuScene() {
    // Your scene initialization code here...
    titlescreen = LoadTexture("assets/graphics/backgrounds/farmhouse_titlescreen.png"); //@Levin delete this
    startscreen_button = LoadTexture("assets/graphics/ui/startscreen-sheet.png");
    start_button = LoadTexture("assets/graphics/ui/start_button_sheet.png");
    options_button = LoadTexture("assets/graphics/ui/weiß_options_button.png");
    exit_button = LoadTexture("assets/graphics/ui/weiß_exit_button.png");
}

game::scenes::MenuScene::~MenuScene() {
    // Your scene cleanup code here...
    UnloadTexture(titlescreen); //@Levin and this
    UnloadTexture(startscreen_button);
    UnloadTexture(start_button);
    UnloadTexture(options_button);
    UnloadTexture(exit_button);
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
    DrawTexture(startscreen_button, 95, 220, WHITE);
    DrawTexture(start_button, 124, 251, WHITE);
    DrawTexture(options_button, 261, 251, WHITE);
    DrawTexture(exit_button, 398, 251, WHITE);

 /* DrawText("Start new game", 30, 40, 30, WHITE);
    DrawText("Continue", 30, 80, 30, WHITE);
    DrawText("Settings", 30, 120, 30, WHITE);
    DrawText("Exit game", 30, 160, 30, WHITE);
    DrawText("Credits", 30, 200, 20, WHITE);*/
}
