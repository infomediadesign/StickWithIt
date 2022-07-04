#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <vector>
#include <memory>

#include "config.h"

//scenes

#include "scenes/game_scene.h"
#include "scenes/menu_scene.h"

int main() {

    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);

    SetTargetFPS(60);

    std::unique_ptr<scenes::Scene> activeScene = std::make_unique<scenes::MenuScene>();

    while (!WindowShouldClose())
    {

        //start scene handling here

        switch (activeScene->changeScene())
        {

        case scenes::Scene::eScenes::eMenuScene:
            activeScene = std::make_unique<scenes::MenuScene>();
            break;

        case scenes::Scene::eScenes::eGameScene:
            activeScene = std::make_unique<scenes::GameScene>();
            break;
        }

        activeScene->Update();

        BeginDrawing();

        ClearBackground(WHITE);

        activeScene->Draw();

        EndDrawing();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}