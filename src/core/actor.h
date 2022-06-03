#pragma once

#include "sprite.h"
#include "iostream"

namespace game::core {
    /**
     * @brief Actor base class. Actors represent all game objects, such as players, enemies and other obstacles.
     *
     * Graphically, actors are represented via a sprite object associated with them. The sprite must be passed in the constructor call.
     *
     * Actors can be placed in the actor-map of a scene object and will be drawn automatically if their visible
     * attribute is true. If actor objects are supposed to be available across scenes, they can be stored in
     * game::core::actors. Objects that are only referenced there will not be drawn automatically.
     * The position and appearance of an actor object in the game depends on attributes (e.g. position and rotation) of its sprite member.
     */
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
