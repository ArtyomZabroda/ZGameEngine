#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <functional>

namespace zge::rendering {

class Renderer {
 public:
  Renderer(void* (*load_proc)(const char*), int width, int height);
  void Render();
};

}  // namespace zge::rendering

#endif  // RENDERER_H
