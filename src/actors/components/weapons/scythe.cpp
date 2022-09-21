#include "scythe.h"

weapon::Scythe::Scythe()
	:
	Weapon(LoadTexture("assets/graphics/skilltree/scythe/scythe.png"),
		{ {-1, -1}, {+0, -1}, {+1, -1} },
		{ {-1, +1}, {+0, +1}, {+1, +1} },
		{ {+1, +1}, {+1, +0}, {+1, -1} },
		{ {-1, +1}, {-1, +0}, {-1, -1} })
{
}
