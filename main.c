#include <assert.h>
#include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EMSCRIPTEN_KEEPALIVE
bool isPrime(size_t n) {
  for (size_t i = 2; i < n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

// typedef struct stringData {
//   char const* const txt;
//   size_t len;
// } stringData;

// EMSCRIPTEN_KEEPALIVE
// char* heyThere() { return "Tyler"; }

// EMSCRIPTEN_KEEPALIVE
// int stringLength(char* string) { return strlen(string); }

EMSCRIPTEN_KEEPALIVE
double sumArray(size_t memoryStartPosition, size_t arrayLength) {
  double* memory = (double*)memoryStartPosition;

  double total = 0;
  for (size_t i = 0; i < arrayLength; ++i) {
    total += memory[i];
  }

  return total;
}

EMSCRIPTEN_KEEPALIVE
double* addTwoNonMutating(size_t memoryStartPosition, size_t arrayLength) {
  double* memory = (double*)memoryStartPosition;
  double* output = (double*)(memoryStartPosition + arrayLength * 8);

  for (size_t i = 0; i < arrayLength; ++i) {
    output[i] = memory[i] + 2;
  }

  return output;
}

EMSCRIPTEN_KEEPALIVE
uint32_t* findPrimes(uint32_t n) {
  uint32_t* primes = malloc(sizeof(uint32_t) * n);
  primes[0] = 0;
  primes[1] = 1;
  for (size_t i = 2; i <= n; ++i) {
    primes[i] = isPrime(i) ? i : 0;
  }

  return primes;
}

// void findPrimeFactorials(size_t n, size_t primes[n], size_t factorials[n]) {
//   for (size_t i = 0; i <= n; i++) {
//     if (primes[i]) {
//       prsize_tf("%lu\n", primes[i]);
//     }
//   }
// }
