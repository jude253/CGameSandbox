# Following SDL2 CMakeLists.txt: https://github.com/libsdl-org/SDL/blob/288aea3b40faf882f26411e6a3fe06329bba2c05/CMakeLists.txt
if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code and run `cmake ..` (path to project root) from there.")
endif()

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(CGameSandbox VERSION 0.1.0 LANGUAGES C CXX)

message("CMAKE_CURRENT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

set(PROJECT_ROOT_DIR  ${PROJECT_SOURCE_DIR}        CACHE STRING "PROJECT_ROOT_DIR")
set(BUILD_ROOT_DIR    ${CMAKE_CURRENT_BINARY_DIR}  CACHE STRING "BUILD_ROOT_DIR")
set(DIST_DIR          ${BUILD_ROOT_DIR}/dist       CACHE STRING "DIST_DIR")

file(GLOB C_SOURCE ${PROJECT_ROOT_DIR}/src/*.c CACHE STRING "C_SOURCE")

# Build Release by default
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build Type")


add_custom_command(
  OUTPUT game.out
  COMMAND rm -rf ${DIST_DIR}
  COMMAND mkdir  ${DIST_DIR}
  COMMAND gcc ${C_SOURCE} -o ${DIST_DIR}/game.out -lSDL2
  VERBATIM
)
add_custom_target(CGameSandbox ALL DEPENDS game.out)

set_property(TARGET CGameSandbox PROPERTY CXX_STANDARD 11)