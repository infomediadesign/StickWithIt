#pragma once

#include "sprite.h"
#include "iostream"

namespace game::core {
    class Actor {
    protected:
        std::shared_ptr<game::core::Sprite> sprite_;

        int movePoints;
        bool firstMovementIsOver = false;

    public:
        Actor(std::shared_ptr<game::core::Sprite> sprite);

        Actor() = delete;

        //prevent slicing
        Actor(const game::core::Actor& actor) = delete;
        Actor &operator=(const Actor &) = delete;

        virtual ~Actor();

        [[nodiscard]] const std::shared_ptr<game::core::Sprite> &sprite() const;

        void sprite(std::shared_ptr<game::core::Sprite> sprite);

        //=========================================

        virtual void move() = 0;

        virtual void placeOnMap() = 0;



        //defines player movement (32px movement)
        void playerMovement(bool isPlayerAllowedToMove);

        //checks if all movePoints have been used
        bool isPlayerAllowedToMove();

        //getter for movePoints
        int getMovePoints();

        Vector2 getActorPosition();

        //place player at beginning of level
        void placePlayer();

        //getter/setter 
        void setFirstMovementIsOver(bool isOver);
        bool getFirstMovementIsOver();
        void setPlayerPosition(int x, int y);
    };
}
