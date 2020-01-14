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
struct UInt32Array* findPrimes(uint32_t max) {
  uint32_t* primes = malloc(sizeof(uint32_t));
  size_t index = 0;
  for (size_t i = 2; i <= max; ++i) {
    if (isPrime(i)) {
      primes[index++] = i;
      primes = realloc(primes, sizeof(uint32_t) * (index + 1));
    }
  }

  struct UInt32Array* ptr = malloc(sizeof(uint32_t) * (index + 2));
  ptr->data = primes;
  ptr->len = index;
  ptr->unitSize = sizeof(uint32_t);
  return ptr;
}

EMSCRIPTEN_KEEPALIVE
uint32_t* getData(struct UInt32Array* array) {
  return array->data;
}

EMSCRIPTEN_KEEPALIVE
size_t getLen(struct UInt32Array* array) {
  return array->len;
}

EMSCRIPTEN_KEEPALIVE
size_t getUnitSize(struct UInt32Array* array) {
  return array->unitSize;
}
