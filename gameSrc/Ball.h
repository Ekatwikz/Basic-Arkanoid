#pragma once

#include "MovableEntity.h"

class Ball : public MovableEntity {
private:
	static constexpr Vec2<> defaultSize { 20, 20 };
	static constexpr float defaultSpeed = 1;

public:
	Ball (Vec2<> position, const char* spritePath)
		: MovableEntity{ position, defaultSize, spritePath, defaultSpeed, {2, 2} /*tmp*/ } { }

	// false if bottom bounce
	bool setVelocity(CollisionType boundaryCollision, CollisionType playerCollision) {
		if (boundaryCollision & Collision::BOTTOM) { [[ unlikely ]]
			speed = defaultSpeed;
			return false;
		}

		if ((boundaryCollision | playerCollision) & Collision::HORIZONTAL) { [[ unlikely ]]
			velocity.x *= -1;
		}

		if ((boundaryCollision | playerCollision) & Collision::VERTICAL) { [[ unlikely ]]
			velocity.y *= -1;
		}

		if (boundaryCollision & Collision::ANY) { [[ unlikely ]]
			speed *= 1.1;
			if (speed > 3) { [[ unlikely ]]
				speed = 3;
			}
		}

		return true;
	}
};
