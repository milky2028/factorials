#include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Primes {
  uint32_t* data;
  size_t len;
} Primes;

bool isPrime(size_t n) {
  for (size_t i = 2; i < n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 1 && n != 0;
}

EMSCRIPTEN_KEEPALIVE
struct Primes* findPrimes(uint32_t max) {
  uint32_t* primes = malloc(sizeof(uint32_t));
  size_t index = 0;
  for (size_t i = 2; i <= max; ++i) {
    if (isPrime(i)) {
      primes[index++] = i;
      primes = realloc(primes, sizeof(uint32_t) * (index + 1));
    }
  }

  struct Primes* ptr = malloc(sizeof(uint32_t) * (index + 1));
  ptr->data = primes;
  ptr->len = index;
  return ptr;
}

EMSCRIPTEN_KEEPALIVE
uint32_t* getData(struct Primes* primes) {
  return primes->data;
}

EMSCRIPTEN_KEEPALIVE
size_t getLen(struct Primes* primes) {
  return primes->len;
}
