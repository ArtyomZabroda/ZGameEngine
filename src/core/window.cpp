#include <SDL.h>
#include <SDL_video.h>
#include <window.h>
#include <format>
#include <memory>

zge::core::Window::Window(int width, int height)
    : sdl_window_ptr_(nullptr, SDL_DestroyWindow) {
  //Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::runtime_error(std::format(
        "SDL could not initialize! SDL_Error: {}\n", SDL_GetError()));
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

  sdl_window_ptr_.reset(SDL_CreateWindow("ZGameEngine", SDL_WINDOWPOS_UNDEFINED,
                                         SDL_WINDOWPOS_UNDEFINED, width, height,
                                         SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL));
  if (sdl_window_ptr_ == nullptr) {
    throw std::runtime_error(std::format(
        "Window could not be created! SDL_Error: %s\n", SDL_GetError()));
  }

  gl_context_ = SDL_GL_CreateContext(sdl_window_ptr_.get());
  if (gl_context_ == nullptr) {
    throw std::runtime_error(std::format(
        "OpenGL Context could not be created! SDL_Error: %s\n", SDL_GetError()));
  }
  SDL_GL_SetSwapInterval(1);

  renderer_.emplace(reinterpret_cast<void*>(SDL_GL_GetProcAddress));
}

zge::core::Window::~Window()
{
  SDL_GL_DeleteContext(gl_context_);
  SDL_Quit();
}


int zge::core::Window::Run() {
  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) quit = true;
    }
    renderer_->Render();
  }
  return 0;
}
