#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"
#include "player.h"
#include "information.h"
#include "boar.h"

using namespace std::string_literals;

game::scenes::GameScene::GameScene() {
    actors.insert(std::make_pair("player", std::make_unique<game::core::Player>()));
    actors.insert(std::make_pair("boar", std::make_unique<game::core::Boar>()));
}

game::scenes::GameScene::~GameScene() {
}

void game::scenes::GameScene::Update() {
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    //switch level when pressing P
    if (IsKeyPressed(KEY_P))
    {
        level++;
    }

    //move player dependant on input
    actors.at("player")->handleMovement(level);
    actors.at("boar")->placeEnemyAtRandomLocation();

    //TODO make boar run in a straight line x-move points when player turn is over
    //Make sure boars position is compatible with tilesetter tile positions

    //exchange tiles on players position when preperation phase is over
    if (actors.at("player")->getIsPlayerPlaced())
    {
        tilesetter->exchangeTile(actors.at("player")->sprite()->position(), level);

        //TODO run through for each loop and call exchangeTile() on every object
        tilesetter->exchangeTile(actors.at("boar")->sprite()->position(), level);
    }
}

void game::scenes::GameScene::Draw() {
    //tilesetter draws tilemap dependant on level
    tilesetter->drawTilemap(level);

    //TODO y-sorting here
    //compare 
    //actors.at(x)->sprite->pos_y
    //to
    //actors.at(y)->sprite->pos_y

    //if players not placed yet, show "preperation phase"
    if (!actors.at("player")->getIsPlayerPlaced())
    {
        DrawText("Press enter to leave preperation phase", 20, 20, 20, WHITE);
    }
    //if player is placed, count "turns left"
    else
    {
        DrawText(TextFormat("Moves left: %i", actors.at("player")->getMovementPoints()), 20, 20, 20, WHITE);
    }
}
