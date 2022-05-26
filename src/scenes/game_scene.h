#pragma once

#include <memory>

#include <actor.h>
#include <scene.h>
#include <sprite.h>
#include <sprite_animated.h>

#include "tilesetter.h"

namespace game::scenes {
    class GameScene final : public game::core::Scene {
    public:
        GameScene();

        ~GameScene() override;

        void Update() override;

        void Draw() override;

    private:
        // Add private members here...
        std::unique_ptr<game::core::Tilesetter> tilesetter;

        int level = 1;
    };
}
