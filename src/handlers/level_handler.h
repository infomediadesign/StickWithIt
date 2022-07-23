#pragma once

#include "../extras/constants.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"

namespace handlers {
    class LevelHandler {
    public:
        LevelHandler(int* currentLevel);
        ~LevelHandler();

        void DrawGround();
        void DrawAir();

        // This will be the foundation of our pathfinding
        type::VectorPositions GetCollisionPositions();
        type::VectorPositions GetCollisionPositionsSkyObjectsOnly();
        type::VectorPositions GetSpawnsGround();
        type::VectorPositions GetSpawnsSky();
        type::VectorPositions GetRitualPositions();

        // Returns how many wheat tiles of current level are left
        int GetNumberOfWheat();

        // Exchange wheat tile for another, damaged wheat tile till there is no wheat tile no more
        void DestroyWheat(type::Position position);
        void DestroyWheat(type::VectorPositions positions);

        // This must be changed later on because one tile could have more than 1 type
        enum eTiles
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

    private:
        void DrawAnyLayer(int layer);

        int* _currentLevel = 0;

        // Add tilesheet here, preferably all tiles are in one sheet and sorted by type
        std::unique_ptr<Texture2D> _texture = std::make_unique<Texture2D>(LoadTextureFromImage(*data::cTileset));

        // All layers in the order they will be drawn
        // Spawn and obstacle layer will be invisible
        // Maybe need 1 additional layer for the height of heighest object (tree->3 layers)
        enum eLayers
        {
            eGroundLayer,
            eSpawnLayer,
            eCollisionLayer,
            eSkyLayer
        };

        // Contains the layer data of specific levels
        // Must be manually updated, if the map layout is going to change
        type::VectorVectorInt _vecDataLevel1 = {
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
        type::VectorVectorInt _vecDataLevel2 = {};

        // Vector that contains all data of each level
        type::VectorLevelData _vecLevelData = { _vecDataLevel1, _vecDataLevel2 };

        // Stoes an ID together with position of each tile on tileset
        type::PositionsWithIDs _positionsWithIDs = {};
    };
}