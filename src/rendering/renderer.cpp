#include "renderer.h"
#include <glad/glad.h>
#include <log.h>

zge::rendering::Renderer::Renderer(void* load_proc) {
  zge::core::Log("Starting renderer");
  gladLoadGLLoader(reinterpret_cast<GLADloadproc>(load_proc));
}

void zge::rendering::Renderer::Render() {
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}
