// virtual class for every playable object in the game like helpers and the main character
// moves depending on input given

#include "../object.h"

namespace objects
{

	class PlayerCharacter : public Object
	{

	public:

		PlayerCharacter(
			Texture2D texture,
			int spritesheetWidth,
			int spritesheetHeight,
			Vector2 offset,
			int columns,
			int rows,
			int playbackSpeed,
			int lives,
			int attackDamage,
			int movePoints,
			Vector2 position,
			Vector2 futurePosition,
			AnimationHandler* mAnimationHandler,
			int actionPoints
			);

		// pure virtual class must have defined destructor
		virtual ~PlayerCharacter() = 0;

		//später bei npc Klasse nicht mehr virtual
		virtual bool spawn(Vector2 position) = 0;

		//später bei npc Klasse nicht mehr virtual + private Funktion fürs Pathfinding?
		virtual void move(std::vector<Vector2> positionsOfColliders) = 0;

		//generalisiert für Helfer, muss in scarecrow Klasse überschrieben werden
		virtual std::tuple<int, std::vector<Vector2>> attack() = 0;

		//getDamage for all helpers, for player theres another function in scarecrowh.h
		virtual void getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions);

		int getActionPoints(); void setActionPoints(int actionPoints);

		//check in gamescene if any playerobject isAlive == false, only scarecrow could be false
		bool isAlive = true;
 
	protected:

		int mActionPoints;
	};
}