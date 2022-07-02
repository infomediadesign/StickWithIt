//// virtual class for every playable object in the game like helpers and the main character
//// moves depending on input given
//
//#include "../object.h"
//
//namespace objects
//{
//
//	class PlayerCharacter : public Object
//	{
//
//	public:
//
//		PlayerCharacter(Texture2D texture, int lives, int damage, int movePoints, 
//			int actionPoints, bool isCurrentObjectSelected);
//
//		virtual ~PlayerCharacter() = 0;
//
//		//später bei npc Klasse nicht mehr virtual
//		virtual bool spawn(Vector2 position) = 0;
//
//		//später bei npc Klasse nicht mehr virtual + private Funktion fürs Pathfinding?
//		virtual void move(std::set<Vector2> positionsOfColliders) = 0;
//
//		//generalisiert für Helfer, muss in scarecrow Klasse überschrieben werden
//		virtual int attack();
//
//		bool switchBetweenPlayerCharacters(bool forwardOrBackward);
//
//		int getActionPoints(); void setActionPoints();
// 
//		bool checkIfAlive();
//
//	protected:
//
//		int mActionPoints;
//
//		bool mIsCurrentObjectSelected;
//
//	};
//}