#ifndef RENDERER_H
#define RENDERER_H

namespace zge::rendering {

class Renderer {
 public:
  Renderer(void* load_proc);
  void Render();
};

}



#endif  // RENDERER_H
