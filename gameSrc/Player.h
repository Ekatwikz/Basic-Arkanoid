#pragma once

#include "MovableEntity.h"
#include "Keyboard.h"

class Player : public MovableEntity {
private:
	static constexpr Vec2<> defaultSize { 200, 40 };
	KeyboardState keyboard;

public:
	void updateKeyboard(FRKey key, bool isPressed) {
		keyboard.handleKeyPress(key, isPressed);
		velocity = keyboard.getVec2();
	}

	Player (Vec2<> position, const char* spritePath)
		: MovableEntity{ position, defaultSize, spritePath, 2 } { }

	void setVelocity(CollisionType boundaryCollision) {
		if ( (velocity.x < 0 && boundaryCollision & Collision::LEFT)
				|| (velocity.x > 0 && boundaryCollision & Collision::RIGHT) ) {
			velocity.x = 0;
		}

		if ( (velocity.y < 0 && boundaryCollision & Collision::TOP)
				|| (velocity.y > 0 && boundaryCollision & Collision::BOTTOM) ) {
			velocity.y = 0;
		}
	}
};
