find_package(Boost COMPONENTS log REQUIRED)

add_library(zge_util STATIC "log.h" "log.cpp")
target_include_directories(zge_util PUBLIC .)

target_link_libraries(zge_util PUBLIC Boost::log_setup Boost::log)