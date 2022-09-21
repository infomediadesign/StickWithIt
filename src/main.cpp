#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <raylib.h>
#include <iostream>
#include <time.h>

#include "config.h"
#include "gamestate.h"
#include "scenes/scenes.h"

int main() 
{
    // Set window + name + icon + fps + seed
    InitWindow(game::SCREEN_WIDTH * 2, game::SCREEN_HEIGHT * 2, game::PROJECT_NAME);
    SetTargetFPS(game::FRAMERATE);
    const Image icon = LoadImage("assets/graphics/extras/icon.png");
    SetWindowIcon(icon);
    SetRandomSeed(static_cast<unsigned int>(time(NULL)));

    // Audio
    InitAudioDevice();
    Music music = LoadMusicStream("assets/audio/tracks/song.mp3");
    PlayMusicStream(music);
    float time_played = 0.0f;

    // Enable fullscreen
    Camera2D camera{};
    camera.zoom = 2.0f;

    // Our gamestate that has to communicate between scenes (e.g. skilltree and settings)
    std::shared_ptr<gs::GameState> gamestate = std::make_unique<gs::GameState>();

    // Our current scene
    std::unique_ptr<scene::Scene> scene_current = std::make_unique<scene::MenuScene>(gamestate);

    // Bool to end game
    bool end_game = false;

    // Main game loop
    while (!end_game && (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)))     // Exit game loop when end_game becomes true or the exit window icon is pressed
    {
        if (!gamestate->GetMusicPause())
        {
            UpdateMusicStream(music);
        }

        // Change current scene
        switch (scene_current->ChangeScene())
        {
        case scene::Scene::MENU_SCENE:
            scene_current = std::make_unique<scene::MenuScene>(gamestate);
            break;
        case scene::Scene::GAME_SCENE:
            scene_current = std::make_unique<scene::GameScene>(gamestate);
            break;
        case scene::Scene::EXIT_GAME:
            end_game = true;
            break;
        }

        // Update
        scene_current->Update();

        // Draw
        BeginDrawing();

        BeginMode2D(camera);

        ClearBackground(WHITE);

        scene_current->Draw();

        EndDrawing();
    }

    // Delete heap memory
    UnloadImage(icon);

    CloseWindow();
}
