#include "Framework.h"

#include "Player.h"

/* Test Framework realization */
class MyFramework : public Framework {
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen) {
		width = 1320;
		height = 720;
		fullscreen = false;
	}

	virtual bool Init() {
		Player player {{50, 50}, "./data/49-Breakout-Tiles.png"}; // tmp
		player.draw(); // tmp
		return true;
	}

	virtual void Close() {
	}

	virtual bool Tick() {
		drawTestBackground();

		Player player {{50, 50}, "./data/49-Breakout-Tiles.png"}; // tmp
		player.draw(); // tmp

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
	}

	virtual void onKeyPressed(FRKey k) {
	}

	virtual void onKeyReleased(FRKey k) {
	}

	virtual const char* GetTitle() override {
		return "Arcanoid";
	}
};

int main(int argc, char** argv) {
	return run(new MyFramework());
}
