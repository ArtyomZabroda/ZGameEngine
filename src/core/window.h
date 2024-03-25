#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>
#include <SDL_video.h>
#include <renderer.h>
#include <optional>

namespace zge::core {

class Window {
 public:
  Window(int width, int height);
  ~Window();
  int Run();

 private:
  std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> sdl_window_ptr_;
  SDL_GLContext gl_context_;
  std::optional<rendering::Renderer> renderer_;
};

}  // namespace zge::core

#endif  // __WINDOW_H__
