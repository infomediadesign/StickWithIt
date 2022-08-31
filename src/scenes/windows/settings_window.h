#pragma once

#include "../scene.h"


namespace scenes::windows
{
	class SettingsWindow : public scenes::Scene
	{
	public:
		SettingsWindow();
		~SettingsWindow();

		void Update() override;
		void Draw() override;

		Texture2D OptionTexture = LoadTexture("assets/graphics/ui/Options/options_background_sheet.png");
		Texture2D FullscreenTexture = LoadTexture("assets/graphics/ui/Options/fullscreen.png");;
		Texture2D SoundTexture = LoadTexture("assets/graphics/ui/Options/sound_text_sheet.png");;
		Texture2D KeyTexture = LoadTexture("assets/graphics/ui/Options/key_sheet.png");;
		Texture2D F_Texture = LoadTexture("assets/graphics/ui/Options/f_texture.png");;
		Texture2D M_Texture = LoadTexture("assets/graphics/ui/Options/m_texture.png");;
	};
}