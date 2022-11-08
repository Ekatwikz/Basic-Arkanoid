#pragma once

#include <iostream>

typedef struct Vec2 {
	int x, y;

	Vec2& operator*(int val) {
		x *= val;
		y *= val;

		return *this;
	}

	Vec2& operator+=(const Vec2& vec) {
		x += vec.x;
		y += vec.y;

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
		return stream << vec.x << " " << vec.y << '\n';
	}
} Vec2;
