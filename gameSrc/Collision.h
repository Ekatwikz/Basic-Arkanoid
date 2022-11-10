#include "Vec2.h"

namespace Collision {
	template <typename T>
	[[ nodiscard ]] inline bool straightPerpEdges(const Vec2<T>& horizEdgeLeft, T width, const Vec2<T>& vertEdgeTop, T height) {
		return horizEdgeLeft.x <= vertEdgeTop.x && vertEdgeTop.x <= horizEdgeLeft.x + width
			&& vertEdgeTop.y <= horizEdgeLeft.y && horizEdgeLeft.y <= vertEdgeTop.y + height;
	}

	// can I combine these two?
	template <typename T>
	[[ nodiscard ]] inline bool horizEdgeWithBox(const Vec2<T>& edgeLeft, T width, const Vec2<T>& boxPos, const Vec2<T>& boxSize) {
		return straightPerpEdges(edgeLeft, width, boxPos, boxSize.y) // with left
			|| straightPerpEdges(edgeLeft, boxSize.x, {boxPos.x + boxSize.x, boxPos.y}, boxSize.y); // or with right
	}
	template <typename T>
	[[ nodiscard ]] inline bool vertEdgeWithBox(const Vec2<T>& edgeTop, T height, const Vec2<T>& boxPos, const Vec2<T>& boxSize) {
		return straightPerpEdges(boxPos, boxSize.x, edgeTop, height) // with top
			|| straightPerpEdges({boxPos.x, boxPos.y + boxSize.y}, boxSize.x, edgeTop, height); // or with bottom
	}

	enum CollisionType { NONE, TOP, BOTTOM, VERTICAL, LEFT, RIGHT = 0b1000, HORIZONTAL = 0b1100, ANY = 0b1111 };
	template <typename T>
	[[ nodiscard ]] CollisionType edgesOfBoxWithBox(const Vec2<T>& lhsPos, const Vec2<T>& lhsSize, const Vec2<T>& rhsPos, const Vec2<T>& rhsSize) {
		// ^ie: lhs' edges with the box of the rhs

		int collisionType = NONE;

		// collision with top edge, etc
		if (horizEdgeWithBox(lhsPos, lhsSize.x, rhsPos, rhsSize)) {
			collisionType |= TOP;
		}

		if (horizEdgeWithBox({lhsPos.x, lhsPos.y + lhsSize.y}, lhsSize.x, rhsPos, rhsSize)) {
			collisionType |= BOTTOM;
		}

		if (vertEdgeWithBox(lhsPos, lhsSize.y, rhsPos, rhsSize)) {
			collisionType |= LEFT;
		}

		if (vertEdgeWithBox({lhsPos.x + lhsSize.x, lhsPos.y}, lhsSize.y, rhsPos, rhsSize)) {
			collisionType |= RIGHT;
		}

		return (CollisionType) collisionType;
	}

	// TODO: boxWithBox?
}
