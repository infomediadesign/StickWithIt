#include "fly.h"

actor::Fly::Fly(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate)
	:
	Player(
		//max_hp
		10,
		//max_move_points
		12,
		//max_action_points
		6,
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
				"assets/graphics/players/fly_animations.png",
				//wanted_speed
				7,
				//texture_collumns
				11,
				//texture_rows
				13,
				//texture_width
				1056,
				//texture_height
				1248,
				//texture_offset
				std::pair<int, int>
				{
				48 - game::TILE_SIZE / 2,
				58 - game::TILE_SIZE / 2
				},
				//frames_per_row
				std::vector<int>
				{
				6, 6, 6, 6,
				6, 6, 6, 6,
				9, 10, 11, 11,
				11, 11
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
