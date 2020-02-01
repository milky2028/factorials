# How to Compile C Code to Standalone WASM

emcc [input filename] -O3 -o [output filename].wasm

-O3 (dash oh three) tells LLVM to compile with production-quality optimizations. Use EMSCRIPTEN_KEEPALIVE to make sure unused functions aren't optimized out.

To find the location of emscripten.h, compile with emcc -v [input filename], then look for "#include <...> search starts here." "%some root%/system/\*\*" is the path for this header file.

emcc main.c -s MODULARIZE=1 -s -o f.js && node main.js  
Use modularize to assemble into a module that you can use as a promise. If you don't do this it's easier to run into errors when you're trying to call a WASM function, but the code isn't yet instantiated.

TODO: Use Cmake for this part  
**Commands For Compilation and Running**

GCC/Clang  
gcc/clang primes-pure-c.c -o primes.o -lm -O3 && ./primes.o PRIMES_BELOW

Emscripten  
emcc primes-wasm.c -s MODULARIZE=1 -O3 -o primes.js && node main-c.js PRIMES_BELOW

I ended up creating a build script for benchmarking tests that runs rollup and builds.
It's run with ./build.sh PRIMES_BELOW ITERATIONS