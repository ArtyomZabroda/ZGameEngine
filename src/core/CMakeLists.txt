find_package(SDL2 CONFIG REQUIRED)

add_library(zgameengine STATIC "window.h" "window.cpp" "engine.h" "engine.cpp")
target_include_directories(zgameengine PUBLIC .)

target_link_libraries(zgameengine
         PUBLIC
         $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
         $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
         zge_rendering
         zge_util
     )

