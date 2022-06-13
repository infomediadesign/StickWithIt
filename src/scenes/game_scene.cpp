#include <memory>
#include <string>

#include <raylib-cpp.hpp>
#include <raylib.h>

#include <store.h>

#include "scenes.h"
#include "renderer.h"
#include "player.h"
#include "boar.h"
#include "mushroom.h"
#include "information.h"

using namespace std::string_literals;

game::scenes::GameScene::GameScene() {
    actors.insert(std::make_pair("player", std::make_unique<game::core::Player>()));
    //actors.insert(std::make_pair("boar", std::make_unique<game::core::Boar>()));
    actors.insert(std::make_pair("mushroom", std::make_unique<game::core::Mushroom>()));
}

game::scenes::GameScene::~GameScene() {
}

void game::scenes::GameScene::Update() {
    if (IsKeyPressed(KEY_ESCAPE))
        game::core::Store::stage->switchToNewScene("pause"s, std::make_unique<PauseScene>());

    if (actors.at("player")->getMovementPoints() != 0) //PlayerTurn
    {
        //move player dependant on input
        actors.at("player")->handleMovement(level);

        //if player has been placed, start exchanging tiles
        if (actors.at("player")->getIsPlayerPlaced())
        {
            tilesetter->exchangeTile(actors.at("player")->sprite()->position(), playerDeviationX, playerDeviationY, level);
        }
    }
    else //EnemyTurn
    {
        std::cout << actors.at("mushroom")->sprite()->pos_x << std::endl << actors.at("mushroom")->sprite()->pos_y << std::endl;
        actors.at("mushroom")->sprite()->pos_x += 32;
        actors.at("mushroom")->sprite()->pos_y += 32;
        tilesetter->exchangeTile(actors.at("mushroom")->sprite()->position(), mushroomDeviationX, mushroomDeviationY, level);

         actors.at("player")->setMovementPoints(10);
    }


    //switch level when pressing P
    if (IsKeyPressed(KEY_P) && level != 2)
    {
        level++;
    }


    //TODO run through for each loop and call exchangeTile() on every object
    //tilesetter->exchangeTile(actors.at("boar")->sprite()->position(), level); //-> this makes the game crash, cuz boar pos != tiles pos
    //actors.at("boar")->placeEnemyAtRandomLocation();

    //TODO make boar run in a straight line x-move points when player turn is over
    //Make sure boars position is compatible with tilesetter tile positions

    //exchange tiles on players position when preperation phase is over

}

void game::scenes::GameScene::Draw() {
    //tilesetter draws tilemap dependant on level
    tilesetter->drawTilemap(level);

    //counts the wheat tiles left
    DrawText(TextFormat("Wheat left: %i", tilesetter->getNumberOfWheat(level)), 20, 50, 20, WHITE);

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
