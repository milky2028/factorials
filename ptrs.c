#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(size_t n) {
  for (size_t i = 2; i < n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 1 && n != 0;
}

typedef struct Primes {
  uint32_t* data;
  size_t len;
} Primes;

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

int main(int argc, char* argv[argc + 1]) {
  char** ptr = malloc(sizeof(char) * 16);
  size_t max = strtoul(argv[1], ptr, 10);
  free(ptr);

  struct Primes* primes = findPrimes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    printf("%d\n", primes->data[i]);
  }

  free(primes);

  return EXIT_SUCCESS;
}