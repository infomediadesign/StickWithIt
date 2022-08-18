#pragma once

#include "../scene.h"


namespace scenes::windows
{
	class SkilltreeWindow : public scenes::Scene
	{
	public:
		SkilltreeWindow();
		~SkilltreeWindow();

		void Update() override;
		void Draw() override;
	};
}