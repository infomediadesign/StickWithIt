#include "config.h"
#include "extras/headers.h"
#include "scenes/scenes.h"

#include <fstream>
#include <filesystem>

int main() 
{
    std::cout << std::filesystem::current_path() << std::endl;

    // Init game
    InitWindow(game::SCREEN_WIDTH, game::SCREEN_HEIGHT, game::PROJECT_NAME);
    SetWindowIcon(game::ICON);
    SetTargetFPS(game::FRAMERATE);


    // Init starting scene
    std::unique_ptr<scenes::Scene> activeScene = std::make_unique<scenes::MenuScene>();


    // Exit game bool
    bool exitGame = false;


    // Game loop starts here
    while (!WindowShouldClose() && !exitGame)
    {
        // Scenes know when to change to what scene
        switch (activeScene->ChangeScene())
        {
        case scenes::Scene::eMenuScene:
            activeScene = std::make_unique<scenes::MenuScene>();
            break;
        case scenes::Scene::eGameScene:
            activeScene = std::make_unique<scenes::GameScene>();
            break;
        case -1:
            exitGame = true;
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


    UnloadImage(game::ICON);

    // Deinit game
    CloseWindow();
}