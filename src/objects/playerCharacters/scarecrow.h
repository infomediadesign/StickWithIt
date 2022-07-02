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

		//sp�ter bei npc Klasse nicht mehr virtual
		bool spawn(Vector2 position) override;

		//sp�ter bei npc Klasse nicht mehr virtual + private Funktion f�rs Pathfinding?
		void move(std::set<Vector2> positionsOfColliders) override;

		//generalisiert f�r Helfer, muss in scarecrow Klasse �berschrieben werden
		int attack() override;

	};
}