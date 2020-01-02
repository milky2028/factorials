#include <emscripten.h>
// #include <stdbool.h>
#include <stdint.h>
// #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// EMSCRIPTEN_KEEPALIVE
// char const* const boolToString(bool b) { return b ? "true" : "false"; }

// EMSCRIPTEN_KEEPALIVE
// bool isPrime(size_t n) {
//   for (size_t i = 2; i < n; i++) {
//     if (n % i == 0) {
//       return boolToString(false);
//     }
//   }

//   return boolToString(true);
// }

// typedef struct stringData {
//   char const* const txt;
//   size_t len;
// } stringData;

// const uint32_t MEMORY_LENGTH = 256;
// uint32_t memory[MEMORY_LENGTH];

// EMSCRIPTEN_KEEPALIVE
// char* heyThere() { return "Tyler"; }

// EMSCRIPTEN_KEEPALIVE
// int stringLength(char* string) { return strlen(string); }

// EMSCRIPTEN_KEEPALIVE
// uint32_t* read_memory() { return &memory[0]; }

EMSCRIPTEN_KEEPALIVE
void addTwo(uint32_t memoryStartPosition, size_t arrayLength) {
  uint32_t* memory = (uint32_t*)memoryStartPosition;

  for (size_t i = 0; i < arrayLength; i++) {
    memory[i] = memory[i] + 2;
  }
}

// EMSCRIPTEN_KEEPALIVE
// size_t* findPrimes(size_t n, size_t primes[n]) {
//   primes[0] = 0;
//   primes[1] = 1;
//   for (size_t i = 2; i <= n; i++) {
//     primes[i] = isPrime(i) ? i : 0;
//   }

//   return primes;
// }

// int main() {
//   printf("%d\n", heyThere()[1]);
//   return EXIT_SUCCESS;
// }

// void findPrimeFactorials(size_t n, size_t primes[n], size_t factorials[n]) {
//   for (size_t i = 0; i <= n; i++) {
//     if (primes[i]) {
//       prsize_tf("%lu\n", primes[i]);
//     }
//   }
// }

// size_t main(size_t argc, char* argv[argc + 1]) {
//   size_t n = (size_t)atoi(argv[1]) + 1;
//   size_t primeNumbers[n];
//   findPrimes(n, primeNumbers);

//   size_t factorials[n];
//   findPrimeFactorials(n, primeNumbers, factorials);

//   return 0;
// }