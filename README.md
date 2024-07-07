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

Alternatively, use this command instead of `make`:
```
cmake --build .
```

## Build with Emscripten for WASM

Use the same commands as above, but replace `cmake ..` with this:

```
cmake -DUSE_EMSCRIPTEN=ON ..
```


NOTE: If you switch back to normal building, use this command for the 
first time to disable the cached key:

````
cmake -DUSE_EMSCRIPTEN=OFF ..
```

## Start Game

```
./build/game
```

## One Line Command

Run from `build` directory
```
cmake .. && make && ./game
```