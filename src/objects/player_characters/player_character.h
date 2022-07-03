// virtual class for every playable object in the game like helpers and the main character
// moves depending on input given

#include "../object.h"

namespace objects
{

	class PlayerCharacter : public Object
	{

	public:

		// pure virtual class must have defined destructor
		virtual ~PlayerCharacter() = 0;

		//sp�ter bei npc Klasse nicht mehr virtual
		virtual void spawn(Vector2 position) = 0;

		//sp�ter bei npc Klasse nicht mehr virtual + private Funktion f�rs Pathfinding?
		virtual void move(std::vector<Vector2> positionsOfColliders) = 0;

		//generalisiert f�r Helfer, muss in scarecrow Klasse �berschrieben werden
		virtual std::tuple<int, std::vector<Vector2>> attack() = 0;

		//getDamage for all helpers, for player theres another function in scarecrowh.h
		virtual void getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions);

		int getActionPoints(); void setActionPoints(int actionPoints);

		int getIsAlive();
 
	protected:

		//check in gamescene if any playerobject isAlive == false, only scarecrow could be false
		bool isAlive = true;

		int mActionPoints{};
	};
}