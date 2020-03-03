# A Comparison of Finding Prime Numbers in C, C++, and Rust and Compiling Those to WebAssembly

## Some Notes

For Standalone WASM  
emcc [input filename] -O3 -o [output filename].wasm

-O3 (dash oh three) tells LLVM to compile with production-quality optimizations. Use EMSCRIPTEN_KEEPALIVE to make sure unused functions aren't optimized out.

To find the location of emscripten.h, compile with emcc -v [input filename], then look for "#include <...> search starts here." "%some root%/system/\*\*" is the path for this header file.

Use modularize to tell Emscripten compile code into a module that you can use as a promise. If you don't do this it's easier to run into errors when you're trying to call a WASM function, but the code isn't yet instantiated.

TODO: Use Cmake/Emmake for this part below

## Commands For Compilation, Running, and Testing

GCC/Clang for C w/Debugging
clang pure/main.c -Wall -std=c11 -ggdb3 -o primes.o -lm

Emscripten for C  
emcc wasm/main.c -s MODULARIZE=1 -O3 -o primes.js

Valgrind for C or C++
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./executable commandLineArgs
         
GCC/Clang for C++ w/Debugging
clang pure/main.cc -Wall -Wextra -Werror -std=c++17 -lstdc++ -ggdb3 -o primes.o -lm

Emscripten for C++  
emcc wasm/main.cc --bind -s MODULARIZE=1 -O3 -o primes.js -std=c++17
