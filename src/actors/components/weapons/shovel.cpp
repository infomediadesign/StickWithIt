#include "shovel.h"

weapon::Shovel::Shovel()
	:
	Weapon(LoadTexture("assets/graphics/skilltree/shovel/shovel.png"),
		{ {+0, -1} },
		{ {+0, +1} },
		{ {+1, +0} },
		{ {-1, +0} })
{
}
