#include "Vec2.h"

namespace Collision {
	template <typename T>
		[[ nodiscard ]] static inline bool straightPerpEdgesIntersect(const Vec2<T>& horizEdgeLeft, T width, const Vec2<T>& vertEdgeTop, T height) {
			return horizEdgeLeft.x <= vertEdgeTop.x && vertEdgeTop.x <= horizEdgeLeft.x + width
				&& vertEdgeTop.y <= horizEdgeLeft.y && horizEdgeLeft.y <= vertEdgeTop.y + height;
		}

	template <typename T>
		[[ nodiscard ]] static inline bool horizEdgeIntersectsRect(const Vec2<T>& edgeLeft, T width, const Vec2<T>& rectPos, const Vec2<T>& rectSize) {
			return straightPerpEdgesIntersect(edgeLeft, width, rectPos, rectSize.y) // with left
				|| straightPerpEdgesIntersect(edgeLeft, rectSize.x, {rectPos.x + rectSize.x, rectPos.y}, rectSize.y); // or with right
		}
	template <typename T>
		[[ nodiscard ]] static inline bool vertEdgeIntersectsRect(const Vec2<T>& edgeTop, T height, const Vec2<T>& rectPos, const Vec2<T>& rectSize) {
			return straightPerpEdgesIntersect(rectPos, rectSize.x, edgeTop, height) // with top
				|| straightPerpEdgesIntersect({rectPos.x, rectPos.y + rectSize.y}, rectSize.x, edgeTop, height); // or with bottom
		}

	template <typename T>
		[[ nodiscard ]] static inline bool rectOverlapsRect(const Vec2<T>& lhsPos, const Vec2<T>& lhsSize, const Vec2<T>& rhsPos, const Vec2<T>& rhsSize) {
			return lhsPos.x + lhsSize.x 	>= rhsPos.x		&&	// lhs rEdge right of rhs lEdge
				lhsPos.x 		<= rhsPos.x + rhsSize.x &&	// lhs lEdge left of rhs rEdge
				lhsPos.y + lhsSize.y 	>= rhsPos.y		&&	// lhs bEdge below rhs tEdge
				lhsPos.y 		<= rhsPos.y + rhsSize.y;	// lhs tEdge above rhs bEdge
		}

	// NB: these aren't the same idea!
	enum CollisionType { NONE, TOP, BOTTOM, VERTICAL, LEFT, RIGHT = 0b1000, HORIZONTAL = 0b1100, ANY = 0b1111 };
	template <typename T>
		[[ nodiscard ]] CollisionType edgesOfRectIntersectRect(const Vec2<T>& lhsPos, const Vec2<T>& lhsSize, const Vec2<T>& rhsPos, const Vec2<T>& rhsSize) {
			// ^ie: lhs' edges with the rect of the rhs

			int collisionType = NONE;

			// collision with top edge, etc
			if (horizEdgeIntersectsRect(lhsPos, lhsSize.x, rhsPos, rhsSize)) {
				collisionType |= TOP;
			}

			if (horizEdgeIntersectsRect({lhsPos.x, lhsPos.y + lhsSize.y}, lhsSize.x, rhsPos, rhsSize)) {
				collisionType |= BOTTOM;
			}

			if (vertEdgeIntersectsRect(lhsPos, lhsSize.y, rhsPos, rhsSize)) {
				collisionType |= LEFT;
			}

			if (vertEdgeIntersectsRect({lhsPos.x + lhsSize.x, lhsPos.y}, lhsSize.y, rhsPos, rhsSize)) {
				collisionType |= RIGHT;
			}

			return (CollisionType) collisionType;
		}
}
