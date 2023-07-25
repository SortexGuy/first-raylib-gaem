#include <stdint.h>
#include <iostream>
#include <raylib-cpp.hpp>

using namespace std;

class App {
 private:
  raylib::Window window;
 public:
  App(int16_t scrWidth, int16_t scrHeight, const char* title);
  ~App();
  void Run();
};

App::App(int16_t scrWidth, int16_t scrHeight, const char* title) {
  window.Init(scrWidth, scrHeight, title, 0U);
  window.SetTargetFPS(60);
}

App::~App() {
  window.Close();
}

void App::Run() {
  while (!window.ShouldClose()) {

    window.BeginDrawing();
    window.ClearBackground(RAYWHITE);

    window.DrawFPS(20, 20);

    window.EndDrawing();
  }
}

int main(void) {
  cout << "Hello world" << endl;

  int16_t scrWidth = 960, scrHeight = 540;
  App myApp(scrWidth, scrHeight, "Hello world");

  myApp.Run();
  return 0;
}
