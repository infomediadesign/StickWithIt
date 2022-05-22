#pragma once

#include <scene.h>

namespace game::scenes {
class MenuScene final : public game::core::Scene {
        public:
            Texture2D titlescreen;
            Texture2D startscreen_button;
            Texture2D start_button;
            Texture2D options_button;
            Texture2D exit_button;

            MenuScene();

            ~MenuScene() override ;

            void Update() override;

            void Draw() override;
        };
}
