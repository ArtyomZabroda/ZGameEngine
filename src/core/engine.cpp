#include <engine.h>
#include <log.h>
#include <window.h>
#include <memory>

zge::core::Engine::Engine() {
  window_ = std::make_shared<Window>(800, 600);
}

int zge::core::Engine::Run() {
  try {
    Log("Running engine");
    window_->Run();
  } catch (std::exception& e) {
    Log(e.what(), LogSeverity::kFatal);
    return 1;
  }
  Log("Engine has finished running successfully");
  return 0;
}
