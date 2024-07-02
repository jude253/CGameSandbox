## Overview
This project is a sandbox for me to learn CMake, SDL and C/C++ better.

## Dependencies:
- CMake
  - Docs: https://cmake.org/
  - Installation: https://github.com/Kitware/CMake?tab=readme-ov-file#unixmac-osxmingwmsyscygwin
- SDL2
  - Docs: https://www.libsdl.org/
  - Source Code: https://github.com/libsdl-org/SDL/tree/SDL2
  - Installation: https://wiki.libsdl.org/SDL2/Installation


## Helpful Resources
- https://wiki.libsdl.org/SDL2/Tutorials


## Build Commands

Make a build (doesn't have to be named `build/`) directory, run `cmake` with relative path to project root from there, then run `make`.  Somewhat like the unix style build, but with no `configure` step yet.

```
mkdir build

cd build

cmake ..

make

```


## Start Game

```
./build/dist/game.out
```
