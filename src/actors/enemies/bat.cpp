#include "bat.h"

actor::Bat::Bat(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate)
	:
	Enemy(
		//max_hp
		3,
		//max_move_points
		1,
		//max_action_points
		1,
		//attack_damage
		2,
		//can_fly
		true,
		//is_active
		false,
		//animation_player
		std::make_shared<component::AnimationPlayer>(
			std::make_shared<component::Sprite>(
				//texture
				"assets/graphics/enemies/bat_animations.png",
				//wanted_speed
				6,
				//texture_collumns
				8,
				//texture_rows
				13,
				//texture_width
				768,
				//texture_height
				1248,
				//texture_offset
				std::pair<int, int>
				{
					48 - game::TILE_SIZE / 2,
					48 - game::TILE_SIZE / 2
				},
				//frames_per_row
				std::vector<int>
				{
					8, 8, 8, 8,
					8, 8, 8, 8,
					8, 8, 8, 8,
					8, 8
				}
				),
			//state
			state_,
			//is_active_
			is_active_
			),
		//map
		map,
		gamestate
	)
{
}
