#include <emscripten.h>
#include <stdint.h>
#include <stdlib.h>
#include "../primes.h"

EMSCRIPTEN_KEEPALIVE
UInt32Array* findPrimesWasm(size_t max) {
  return findPrimes(max);
};

EMSCRIPTEN_KEEPALIVE
uint32_t* getData(UInt32Array array[static 1]) {
  return array->data;
}

EMSCRIPTEN_KEEPALIVE
size_t getLen(UInt32Array array[static 1]) {
  return array->len;
}

EMSCRIPTEN_KEEPALIVE
size_t getUnitSize(UInt32Array array[static 1]) {
  return array->unitSize;
}

EMSCRIPTEN_KEEPALIVE
void cleanup(UInt32Array array[static 1]) {
  free(array->data);
  free(array);
}
