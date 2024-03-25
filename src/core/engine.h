#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <window.h>

namespace zge::core {

class Engine {
 public:
  Engine();
  int Run();

 private:
  std::shared_ptr<Window> window_;
};

}  // namespace zge::core

#endif  // __ENGINE_H__
