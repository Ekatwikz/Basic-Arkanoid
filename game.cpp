#include "Framework.h"

#include "Game.h"
#include "getResolution.h"

using GetArg::Resolution;
using GetArg::getResolution;

/* Test Framework realization */
class MyFramework : public Framework {
private:
	static constexpr Resolution defaultRes { 600, 800 };
	Resolution resolution;

public:
	virtual void PreInit(int& width, int& height, bool& fullscreen) {
		width = resolution.x;
		height = resolution.y;
		fullscreen = false;
	}

	virtual bool Init() {
		Game::getGame()->setSize(resolution);
		return true;
	}

	virtual void Close() {
	}

	virtual bool Tick() {
		drawTestBackground();
		Game::getGame()->render();

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		Game::getGame()->setMousePos(x, y);
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		Game::getGame()->handleClick(button, isReleased);
	}

	virtual void onKeyPressed(FRKey k) {
		Game::getGame()->handleKeyPress(k, true);
	}

	virtual void onKeyReleased(FRKey k) {
		Game::getGame()->handleKeyPress(k, false);
	}

	virtual const char* GetTitle() override {
		return "Arcanoid";
	}

	MyFramework(Resolution res) : resolution{ res.x && res.y ? res : defaultRes } { }
};

int main(int argc, char** argv) {
	return run(new MyFramework(getResolution(argc, argv)));
}
