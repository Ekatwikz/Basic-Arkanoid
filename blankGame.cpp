#include "Framework.h"

#include "GetArg.h"

using GetArg::Resolution;
using GetArg::getResolution;

// might be useful for hunting down memory leak
class BlankFrame : public Framework {
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
		return true;
	}

	virtual void Close() {
	}

	virtual bool Tick() {
		//drawTestBackground();
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

	BlankFrame(Resolution res) : resolution{ res.x && res.y ? res : defaultRes } { }
};

int main(int argc, char** argv) {
	return run(new BlankFrame(getResolution(argc, argv)));
}
