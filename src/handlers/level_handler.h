#pragma once

#include "../config.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"


namespace handlers
{
    class LevelHandler
    {
    public:

        LevelHandler(int* currentLevel);
        ~LevelHandler();


        void DrawGround();
        void DrawAir();


        type::Vec_Ptr_Position GetCollisionsGround();
        type::Vec_Ptr_Position GetCollisionsSky();


        type::Vec_Position GetSpawnsGround();
        type::Vec_Position GetSpawnsSky();
        type::Vec_Position GetSpawnsPC();


        // Exchange wheat tile for a more damaged wheat/field tile
        void DestroyWheat(type::Position position);
        void DestroyWheat(type::Vec_Position positions);
        int GetNumberOfWheat();


    private:

        void DrawAnyLayer(int layer);


        int* _currentLevel = 0;


        // Add tilesheets here, preferably all tiles are in one sheet and sorted by type
        Texture2D _texture = Texture2D(LoadTexture("assets/graphics/tilesets/tileset.png"));


        enum tiles
        {
            eNULLTile,
            eWheat1Tile,
            eWheat2Tile,
            eWheat3Tile,
            eFieldTile,
            eRitualTile,
            eSpawnGroundTile,
            eSpawnSkyTile,
            eCollisionTiles,
            eCollisionOnlyGroundTile,
            eSkyTile
        };
        enum layers
        {
            eGroundLayer,
            eSpawnLayer,
            eCollisionLayer,
            eSkyLayer
        };


        // Contains the layer data of specific levels
        // Must be manually updated, if the map layout is going to change
        type::Vec_Vec_Int _vecDataLevel1 = {
            {
                11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 11, 11, 11, 1, 1, 1, 1, 1, 11, 11, 1, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 11, 11, 11, 1, 1, 1, 1, 1, 11, 11, 1, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 1, 1, 1, 5, 5, 1, 1, 1, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 1, 1, 1, 5, 5, 1, 1, 1, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 1, 11, 11, 1, 1, 1, 1, 1, 11, 11, 11, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 1, 11, 11, 1, 1, 1, 1, 1, 11, 11, 11, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 11, 11,
                11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
                11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11
            },
            {
                0, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0
            },
            {
                8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                8, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 9,
                8, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 9,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                9, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 8,
                9, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 8,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8,
                8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0, 8, 8, 8, 8, 8
            },
            {
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10,
                10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10,
                10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10
            }
        };
        type::Vec_Vec_Int _vecDataLevel2 = {};
        // Vector that contains data of all layers of each level
        type::Vec_Vec_Vec_Int _vecDataAllLevel = { _vecDataLevel1, _vecDataLevel2 };


        // Stoes an ID together with position of each tile on tileset
        type::Map_ID_Position _IDWithPosition = {};
    };
}