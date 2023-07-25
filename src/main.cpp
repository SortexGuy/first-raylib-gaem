#include <stdint.h>
#include <iostream>
#include <raylib-cpp.hpp>
#include <entt/entt.hpp>

using namespace std;

struct BoundingBoxComponent {
	raylib::Vector2 halfLen;
  raylib::Rectangle bb;

  BoundingBoxComponent() = default;
  BoundingBoxComponent(const BoundingBoxComponent&) = default;
  BoundingBoxComponent(const raylib::Rectangle& rect) : bb(rect) {};

  operator const raylib::Rectangle&() const { return bb; };
};

struct PositionComponent {
	raylib::Vector2 pos;
	
  PositionComponent() = default;
  PositionComponent(const PositionComponent&) = default;
  PositionComponent(const raylib::Vector2& vec2) : pos(vec2) {};

  operator const raylib::Vector2&() const { return pos; };
};

class App {
 private:
  raylib::Window window;

  entt::entity player;
  entt::entity ground;
  entt::entity obstacle;
  entt::registry m_reg;
 public:
  App(int16_t scrWidth, int16_t scrHeight, const char* title);
  ~App();
  void Run();
};

App::App(int16_t scrWidth, int16_t scrHeight, const char* title) {
  window.Init(scrWidth, scrHeight, title, 0U);
  window.SetTargetFPS(60);

	player = m_reg.create();
	// ground = m_reg.create();
	// obstacle = m_reg.create();
	auto p_pos = raylib::Vector2(50.0, 50.0);
	auto p_rect = raylib::Rectangle(p_pos, raylib::Vector2(120.0, 120.0));

	m_reg.emplace<PositionComponent>(player, p_pos);
	m_reg.emplace<BoundingBoxComponent>(player, p_rect);
}

App::~App() {
  window.Close();
}

void App::Run() {
  while (!window.ShouldClose()) {

    window.BeginDrawing();
    window.ClearBackground(RAYWHITE);

		for (auto entity: m_reg.view<BoundingBoxComponent>()) {
			auto &bb = m_reg.get<BoundingBoxComponent>(entity);
			DrawRectangleRec(bb, raylib::Color::Blue());
		}

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
