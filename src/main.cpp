﻿#include "config.h"
#include "extras/headers.h"
#include "extras/typedefs.h"
#include "scenes/scenes.h"

int main() {

    // Init game
    InitWindow(game::SCREEN_WIDTH, game::SCREEN_HEIGHT, game::PROJECT_NAME);
    SetWindowIcon(game::ICON);
    SetTargetFPS(game::FRAMERATE);

    // Init starting scene
    std::unique_ptr<scenes::> activeScene = std::make_unique<scenes::MenuScene>();

    // Game loop starts here
    while (!WindowShouldClose())
    {
        // Scenes know when to change to which scene
        switch (activeScene->ChangeScene())
        {
        case scenes::VirtualScene::eScenes::eMenuScene:
            activeScene = std::make_unique<scenes::MenuScene>();
            break;
        case scenes::VirtualScene::eScenes::eGameScene:
            activeScene = std::make_unique<scenes::GameScene>();
            break;
        }

        // Update active scene
        activeScene->Update();

        // Clear Background and draw scene
        BeginDrawing();
        {
            ClearBackground(WHITE);
            activeScene->Draw();
        }
        EndDrawing();
    }

    // Deinit game
    CloseWindow();
}