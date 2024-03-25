find_package(OpenGL REQUIRED)

add_library(glad STATIC "include/glad/glad.h" "include/KHR/khrplatform.h" "src/glad.c")

target_link_libraries(glad PUBLIC OpenGL::OpenGL OpenGL::GLX)
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
