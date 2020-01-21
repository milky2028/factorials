#include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <tgmath.h>

typedef struct UInt32Array {
  uint32_t* data;
  size_t len;
  size_t unitSize;
} UInt32Array;

bool isPrime(size_t n) {
  for (size_t i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 1 && n != 0;
}

EMSCRIPTEN_KEEPALIVE
UInt32Array* findPrimes(uint32_t max) {
  uint32_t* primes = calloc(1, sizeof(uint32_t));
  size_t index = 0;
  for (size_t i = 2; i <= max; ++i) {
    if (isPrime(i)) {
      primes[index++] = i;
      primes = realloc(primes, sizeof(uint32_t) * (index + 1));
    }
  }

  UInt32Array* ptr = malloc(index * sizeof(uint32_t) + sizeof(size_t) * 2);
  ptr->data = primes;
  ptr->len = index;
  ptr->unitSize = sizeof(uint32_t);
  return ptr;
}

EMSCRIPTEN_KEEPALIVE
uint32_t* getData(UInt32Array* restrict array) {
  return array ? array->data ? array->data : 0 : 0;
}

EMSCRIPTEN_KEEPALIVE
size_t getLen(UInt32Array* restrict array) {
  return array ? array->len : 0;
}

EMSCRIPTEN_KEEPALIVE
size_t getUnitSize(UInt32Array* restrict array) {
  return array ? array->unitSize : 0;
}

EMSCRIPTEN_KEEPALIVE
void cleanup(UInt32Array* restrict array) {
  free(array->data);
  free(array);
}
