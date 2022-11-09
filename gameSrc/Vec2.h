#pragma once

#include <iostream>

// god forgive me for templating this
template <typename T = int>
struct Vec2 {
	T x, y;

	template <typename U>
	Vec2 operator*(U val) const {
		return { x * val, y * val };
	}

	template <typename U>
	Vec2& operator*=(U val) {
		x *= val;
		y *= val;
		return *this;
	}

	template <typename U>
	Vec2& operator+=(const Vec2<U>& vec) {
		x += vec.x;
		y += vec.y;

		return *this;
	}

	template <typename U>
	Vec2& operator=(const Vec2<U>& vec) {
		x = vec.x;
		y = vec.y;

		return *this;
	}

	// for debugging :)
	friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
		return stream << vec.x << " " << vec.y << '\n';
	}
};
