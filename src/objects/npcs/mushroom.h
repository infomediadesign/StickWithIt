#pragma once

#include "../../extras/headers.h"
#include "virtual_non_player_character.h"

namespace objects {
	class Mushroom : public VirtualNonPlayerCharacter {
	public:
		Mushroom();

		~Mushroom() override;
	};
}