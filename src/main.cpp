#include <iostream>
#include <stdint.h>
#include <raylib-cpp.hpp>

using namespace std;

int main(void) {
	cout << "Hello world" << endl;

	int16_t scrWidth = 960, scrHeight = 540;
	raylib::Window window(scrWidth, scrHeight, "Hello world");
	SetTargetFPS(60);

	while (!window.ShouldClose()) {
		BeginDrawing();
		window.ClearBackground(RAYWHITE);

		window.DrawFPS(50, 50);

		EndDrawing();
	}
	return 0;
}
