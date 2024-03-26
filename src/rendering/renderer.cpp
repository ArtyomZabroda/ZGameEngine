#include "renderer.h"
#include <glad/glad.h>
#include <logging.h>
#include <format>
#include <stdexcept>

zge::rendering::Renderer::Renderer(void* load_proc, int width, int height) {
  zge::core::Log("Starting renderer");
  if (!gladLoadGLLoader((GLADloadproc)load_proc)) {
    throw std::runtime_error("Failed to initialize GLAD");
  }
  zge::core::Log(std::format(
      "Vendor: {}", reinterpret_cast<const char*>(glGetString(GL_VENDOR))));
  printf("Vendor:   %s\n", glGetString(GL_VENDOR));
  zge::core::Log(std::format(
      "Renderer: {}", reinterpret_cast<const char*>(glGetString(GL_RENDERER))));
  zge::core::Log(std::format(
      "Version: {}", reinterpret_cast<const char*>(glGetString(GL_VERSION))));

  glViewport(0, 0, width, height);
}

void zge::rendering::Renderer::Render() {
  glClearColor(0.0, 1.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}
