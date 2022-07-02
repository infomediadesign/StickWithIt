// class of the protagonist object

#include "player_character.h"

namespace objects
{

	class Scarecrow : public PlayerCharacter
	{

	public:

		Scarecrow(Texture2D texture, int lives, int damage, int movePoints,
			int actionPoints, bool isCurrentObjectSelected);

		~Scarecrow();

		//später bei npc Klasse nicht mehr virtual
		bool spawn(Vector2 position) override;

		//später bei npc Klasse nicht mehr virtual + private Funktion fürs Pathfinding?
		void move(std::set<Vector2> positionsOfColliders) override;

		//generalisiert für Helfer, muss in scarecrow Klasse überschrieben werden
		int attack() override;

	};
}