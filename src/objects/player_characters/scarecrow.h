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

		std::vector<int> attack() override;

		void getDamage(std::vector<int> incomingDamageAndPositions) override;
	};
}