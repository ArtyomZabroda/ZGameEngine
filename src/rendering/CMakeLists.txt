find_package(Boost COMPONENTS log REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

add_library(zge_rendering STATIC "renderer.h" "renderer.cpp")
target_include_directories(zge_rendering PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(zge_rendering PRIVATE glad zge_util)

target_link_libraries(zge_rendering PUBLIC OpenGL::GL SDL2::SDL2)
