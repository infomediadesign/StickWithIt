// class of the protagonist object

#include "player_character.h"

namespace objects
{

	class Scarecrow : public PlayerCharacter
	{

	public:

		Scarecrow();

		~Scarecrow() override;

		void spawn(Vector2 position) override;

		void move(std::vector<Vector2> positionsOfColliders) override;

		std::tuple<int, std::vector<Vector2>> attack() override;

		void getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions) override;
	};
}