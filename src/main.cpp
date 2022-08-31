#include "config.h"
#include "extras/headers.h"
#include "scenes/scenes.h"

#include <fstream>
#include <filesystem>

int main() 
{
    std::cout << std::filesystem::current_path() << std::endl;

    // Init game
    InitWindow(game::SCREEN_WIDTH*2, game::SCREEN_HEIGHT*2, game::PROJECT_NAME);
    SetWindowIcon(game::ICON);
    SetTargetFPS(game::FRAMERATE);


    // Init starting scene
    std::unique_ptr<scenes::Scene> activeScene = std::make_unique<scenes::MenuScene>();

    Camera2D Screencamera{};

    Screencamera.zoom = 2.0f;

    // Exit game bool
    bool resumeGame = true;


    // Game loop starts here
    while (resumeGame && (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)))
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
            resumeGame = false;
        }


        // Update active scene
        activeScene->Update();


        // Clear Background and draw scene
        BeginDrawing();
        {
            ClearBackground(WHITE);
            BeginMode2D(Screencamera);
            activeScene->Draw();
        }

        EndMode2D();
        EndDrawing();
    }


    UnloadImage(game::ICON);

    // Deinit game
    CloseWindow();
}