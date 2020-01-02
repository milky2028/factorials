# How to Compile C Code to Standalone WASM
emcc [input filename] -O3 -o [output filename].wasm

-O3 (dash oh three) tells LLVM to compile with production-quality optimizations. Use EMSCRIPTEN_KEEPALIVE to make sure unused functions aren't optimized out. 