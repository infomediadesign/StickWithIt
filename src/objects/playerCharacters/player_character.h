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
//		//sp�ter bei npc Klasse nicht mehr virtual
//		virtual bool spawn(Vector2 position) = 0;
//
//		//sp�ter bei npc Klasse nicht mehr virtual + private Funktion f�rs Pathfinding?
//		virtual void move(std::set<Vector2> positionsOfColliders) = 0;
//
//		//generalisiert f�r Helfer, muss in scarecrow Klasse �berschrieben werden
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