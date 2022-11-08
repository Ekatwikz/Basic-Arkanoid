#pragma once

#include "Framework.h"

#include "Vec2.h"

class Entity {
protected:
	Vec2 position;
	Vec2 size;

public:
	Entity (Vec2 position_, Vec2 size_) : position{ position_ }, size{ size_ } { }

	void setPos(Vec2 position_) {
		position = position_;
	}

	[[ nodiscard ]] virtual Vec2 getSize() const {
		return size;
	}

	Entity& operator+=(Vec2 vec) {
		position += vec;
		return *this;
	}

	enum CollisionType { COLLIDE_NONE, COLLIDE_HORIZONTAL, COLLIDE_VERTICAL, COLLIDE_BOTH };
	CollisionType hasCollided(const Entity& lhs, const Entity& rhs) {
		int collisionType = COLLIDE_NONE;

		Vec2 lhsPos = lhs.position;
		Vec2 lhsSize = lhs.getSize();
		int lhsRight = lhsPos.x + lhsSize.x;
		int lhsBottom = lhsPos.y + lhsSize.y;

		Vec2 rhsPos = rhs.position;
		Vec2 rhsSize = rhs.getSize();
		int rhsRight = rhsPos.x + rhsSize.x;
		int rhsBottom = rhsPos.y + rhsSize.y;

		if (lhsPos.x <= rhsRight && rhsPos.x <= lhsRight) {
			collisionType = COLLIDE_HORIZONTAL;
		}

		if (lhsPos.y <= rhsBottom && rhsPos.y <= lhsBottom) {
			collisionType |= COLLIDE_VERTICAL;
		}

		return (CollisionType) collisionType;
	}

	CollisionType hasCollided(const Entity& rhs) {
		return hasCollided(*this, rhs);
	}
};
