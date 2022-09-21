#include "pitchfork.h"

weapon::Pitchfork::Pitchfork()
	:
	Weapon(
		LoadTexture("assets/graphics/skilltree/pitchfork/pitchfork.png"),
			{ {+0, -1}, {+0, -2}, {+0, -3} },
			{ {+0, +1}, {+0, +2}, {+0, +3} },
			{ {+1, +0}, {+2, +0}, {+3, +0} },
			{ {-1, +0}, {-2, +0}, {-3, +0} })
{
}
