#ifndef RENDERER_H
#define RENDERER_H

namespace zge::rendering {

class Renderer {
 public:
  Renderer(void* load_proc, int width, int height);
  void Render();
};

}  // namespace zge::rendering

#endif  // RENDERER_H
