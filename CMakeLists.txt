cmake_minimum_required(VERSION 3.23)

set(VCPKG_ROOT "vcpkg")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "Vcpkg")

project(zgameengine)

set (CMAKE_CXX_STANDARD 20)

add_subdirectory(ext)
add_subdirectory(src)
add_subdirectory(samples)

add_subdirectory(tests)
