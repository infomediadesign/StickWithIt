#pragma once
#include <string>

//game
const int gameHeight = 360;
const int gameWidth = 640;

//tilesetter
const int tilesetHeight = 7;
const int tilesetWidth = 10;

const int amountOfTilesX = 21;
const int amountOfTilesY = 12;

//player tileset
static const char* const playerTexturePath = "assets/graphics/player/scarecrow_idle_animation.png";
const int playerFrameWidth = 29;
const int playerFrameHeight = 40;
const int playerRow = 1;
const int playerSteps = 9;
const int playerSpeed = 6;
const int playerStartpositionX = gameWidth / 2 - playerFrameWidth / 2;
const int playerStartpositionY = gameHeight / 2 - playerFrameHeight / 2;