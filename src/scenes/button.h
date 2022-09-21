#pragma once

#include <raylib.h>
#include <string>

namespace ui
{
	class Button
	{
	public:

		Button(const char* texture_path, int x, int y, bool is_active);
		~Button();

		void Draw() const;
		bool GetIsActive() const; void SetIsActive(bool status);

	private:

		const Texture2D texture_;
		
		const int x_;
		const int y_;

		bool is_active_;
	};
}