#pragma once

#include <cstring>

#include "Vec2.h"

namespace GetArg {
	using Resolution = Vec2<>;

	static inline ssize_t __attribute__(( nonnull(1) ))
		charPos(const char* s, int c) {
			const char* loc = std::strchr(s, c);
			return loc ? loc - s : -1;
		}

	Resolution getResolution(int argc, char** argv) {
		Resolution res;
		if (argc > 2 && !strcmp(argv[1], "-window")) {
			int xPos = charPos(argv[2], 'x');

			if (xPos < 0) {
				return res;
			}

			argv[2][xPos] = '\0';

			res.x = atoi(argv[2]);
			res.y = atoi(argv[2] + xPos + 1);
		}

		return res;
	}
}
