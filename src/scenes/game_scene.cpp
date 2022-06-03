#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"
#include "information.h"
#include "player.h"


using namespace std::string_literals;

game::scenes::GameScene::GameScene() : level(1) {
    // Your scene initialization code here...
    actors.insert(std::make_pair("player", std::make_shared<game::core::Player>(std::make_shared<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>
        ("assets/graphics/player/scarecrow_idle_animation.png"), 29, 40, 1, 9, 6, game_width / 2 - player_sprite_width / 2, game_height / 2 - player_sprite_height / 2))));

}

game::scenes::GameScene::~GameScene() {
    // Your scene cleanup code here...
}

void game::scenes::GameScene::Update() {
    // Your process input and update game scene code here...
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    //place player at round start, transparent
    actors.at("player")->placePlayer();

    //move player when keys pressed
    actors.at("player")->playerMovement(actors.at("player")->isPlayerAllowedToMove());

    //exchange tiles when player touches them
    if (actors.at("player")->getFirstMovementIsOver())
    {
        tilesetter->exchangeTile(actors.at("player")->getActorPosition(), level);
    }

    //TEMP press b and switch level
    if (IsKeyPressed(KEY_B) && level != 2)
    {
        level++;
        actors.at("player")->setFirstMovementIsOver(false);
        actors.at("player")->setPlayerPosition(game_width / 2 - player_sprite_width / 2, game_height / 2 - player_sprite_height / 2);
    }
}

void game::scenes::GameScene::Draw() {
    // Your scene drawing code here...
    // Note that scene-actors are drawn automatically
    DrawText("This is the game scene - press ESCAPE for pause", 10, 10, 30, LIGHTGRAY);

    //draw level
    tilesetter->drawTilemap(level);

    //shows how many points player is allowed to move
    if (IsKeyPressed(KEY_ENTER))
    {
        actors.at("player")->setFirstMovementIsOver(true);
    }
    if (actors.at("player")->getFirstMovementIsOver())
    {
        DrawText(TextFormat("%i moves left", actors.at("player")->getMovePoints()), 20, 20, 20, BLACK);
    }
    else
    {
        actors.at("player")->setFirstMovementIsOver(false);
        DrawText(TextFormat("Place Player and press enter", actors.at("player")->getMovePoints()), 20, 20, 20, BLACK);
    }
}