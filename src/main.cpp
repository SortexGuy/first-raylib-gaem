#include <stdint.h>
#include <iostream>
#include <raylib-cpp.hpp>
#include <entt/entt.hpp>

using namespace std;

struct BoundingBoxComponent {
  raylib::Rectangle bb;

  BoundingBoxComponent() = default;
  BoundingBoxComponent(const BoundingBoxComponent&) = default;
  BoundingBoxComponent(const raylib::Rectangle& rect) : bb(rect) {};

  operator const raylib::Rectangle&() const { return bb; };
};

class App {
 private:
  raylib::Window window;

  entt::entity player;
  entt::entity ground;
  entt::entity obstacle;
  entt::registry m_registry;
 public:
  App(int16_t scrWidth, int16_t scrHeight, const char* title);
  ~App();
  void Run();
};

App::App(int16_t scrWidth, int16_t scrHeight, const char* title) {
  window = raylib::Window(scrWidth, scrHeight, title);
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
