#include <assert.h>
// #include <emscripten.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// EMSCRIPTEN_KEEPALIVE
char const* const boolToString(bool b) {
  return b ? "true" : "false";
}

// EMSCRIPTEN_KEEPALIVE
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

// EMSCRIPTEN_KEEPALIVE
double sumArray(size_t memoryStartPosition, size_t arrayLength) {
  double* memory = (double*)memoryStartPosition;

  double total = 0;
  for (size_t i = 0; i < arrayLength; ++i) {
    total += memory[i];
  }

  return total;
}

// EMSCRIPTEN_KEEPALIVE
double* addTwoNonMutating(size_t memoryStartPosition, size_t arrayLength) {
  double* memory = (double*)memoryStartPosition;
  double* output = (double*)(memoryStartPosition + arrayLength * 8);

  for (size_t i = 0; i < arrayLength; ++i) {
    output[i] = memory[i] + 2;
  }

  return output;
}

// EMSCRIPTEN_KEEPALIVE
void findPrimes(size_t n, size_t primes[n]) {
  primes[0] = 0;
  primes[1] = 1;
  for (size_t i = 2; i <= n; ++i) {
    primes[i] = isPrime(i) ? i : 0;
  }
}

// void findPrimeFactorials(size_t n, size_t primes[n], size_t factorials[n]) {
//   for (size_t i = 0; i <= n; i++) {
//     if (primes[i]) {
//       prsize_tf("%lu\n", primes[i]);
//     }
//   }
// }

// int main(size_t argc, char* argv[argc + 1]) {
//   size_t n = (size_t)atoi(argv[1]);

//   size_t primeNumbers[n];
//   findPrimes(n, primeNumbers);

//   for (size_t i = 0; i <= n; ++i) {
//     if (primeNumbers[i]) {
//       printf("%lu\n", primeNumbers[i]);
//     }
//   }

//   return EXIT_SUCCESS;
// }

int main(int argc, char* argv[argc + 1]) {
  if (argv[1] && !strcmp(argv[1], "test")) {
    assert(isPrime(1));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(!isPrime(12));
    assert(!isPrime(42));
    printf("%s\n", "Tests passed");
  } else {
    printf("%s\n", "Run");
  }

  return EXIT_SUCCESS;
}