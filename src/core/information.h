#pragma once
#include <string>

//game
const int gameHeight = 360;
const int gameWidth = 640;
//oberstesTileX = 0
//oberstesTileY = 0
//->diagonal unten links = 32, 32

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
const float playerDeviationX = 18;
const float playerDeviationY = 32; //32 so the tile UNDER the scarecrow gets exchanged

//boar tileset
static const char* const boarTexturePath = "assets/graphics/enemies/boar/boar_walking_animation.png";
const int boarFrameWidth = 128;
const int boarFrameHeight = 125;
const int boarRow = 1;
const int boarSteps = 8;
const int boarSpeed = 6;
const int boarStartpositionX = 0;
const int boarStartpositionY = 0;

//mushroom tileset
static const char* const mushroomTexturePath = "assets/graphics/enemies/mushroom/mushroom_walking_animation_front.png";
const int mushroomFrameWidth = 26;
const int mushroomFrameHeight = 28;
const int mushroomRow = 1;
const int mushroomSteps = 7;
const int mushroomSpeed = 6;
//const int mushroomStartpositionX = 16 + 3; //16 to get center of tile, 3 (is half of 32-26) to deny misplacement
//const int mushroomStartpositionY = 16 + 2 - 8; //-8 to get sprites "feet" to the center
//const float mushroomDeviationX = 13;
//const float mushroomDeviationY = 16;
const int mushroomStartpositionX = 32 - mushroomFrameWidth / 2; //16 to get center of tile, 3 (is half of 32-26) to deny misplacement
const int mushroomStartpositionY = 32 - mushroomFrameHeight / 2; //-8 to get sprites "feet" to the center
const float mushroomDeviationX = 19; // = StartpositionX
const float mushroomDeviationY = 14; // = 32 - StartpositionY