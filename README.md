# How to Compile C Code to Standalone WASM
emcc [input filename] -O3 -o [output filename].wasm

-O3 (dash oh three) tells LLVM to compile with production-quality optimizations. Use EMSCRIPTEN_KEEPALIVE to make sure unused functions aren't optimized out.

To find the location of emscripten.h, compile with emcc -v [input filename], then look for "#include <...> search starts here." "<some root>/system/**" is the path for this header file. 

emcc main.c -s MODULARIZE=1 -s -o f.js && node main.js
Use modularize to assemble into a module that you can use as a promise