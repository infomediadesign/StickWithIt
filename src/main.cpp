#include <cstdlib>
#include <iostream>
#include <raylib.h>
#include <vector>
#include <memory>

#include "config.h"

//scenes

#include "scenes/gameScene.h"
#include "scenes/menuScene.h"

int main() {

    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);

    SetTargetFPS(60);

    std::unique_ptr<scenes::Scene> activeScene = std::make_unique<scenes::MenuScene>();

    enum eScenes
    {
        eMenuScene = 1,
        eGameScene = 2
    };

    while (!WindowShouldClose())
    {

        //start scene handling here

        switch (activeScene->changeScene())
        {

        case eMenuScene:
            activeScene = std::make_unique<scenes::MenuScene>();
            break;

        case eGameScene:
            activeScene = std::make_unique<scenes::GameScene>();
            break;
        }

        activeScene->Update();

        activeScene->Draw();
    }

    CloseWindow();

    return EXIT_SUCCESS;
}