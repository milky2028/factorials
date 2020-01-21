#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
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

struct UInt32Array* findPrimes(uint32_t max) {
  uint32_t* primes = calloc(1, sizeof(uint32_t));
  size_t index = 0;
  for (size_t i = 2; i <= max; ++i) {
    if (isPrime(i)) {
      primes[index++] = i;
      primes = realloc(primes, sizeof(uint32_t) * (index + 1));
    }
  }

  struct UInt32Array* ptr =
      malloc(index * sizeof(uint32_t) + sizeof(size_t) * 2);
  ptr->data = primes;
  ptr->len = index;
  ptr->unitSize = sizeof(uint32_t);
  return ptr;
}

uint32_t* getData(struct UInt32Array* array) {
  return array ? array->data ? array->data : 0 : 0;
}

size_t getLen(struct UInt32Array* array) {
  return array ? array->len : 0;
}

size_t getUnitSize(struct UInt32Array* array) {
  return array ? array->unitSize : 0;
}

int main(int argc, char* argv[argc + 1]) {
  if (argc < 2) {
    printf(
        "\n===============================================================\n");
    printf("Error: no arguments specified. Please specify an upper bound.\n");
    printf(
        "===============================================================\n\n");
    exit(EXIT_FAILURE);
  };

  char** ptr = malloc(sizeof(char) * 16);
  size_t max = strtoul(argv[1], ptr, 10);
  free(ptr);

  struct UInt32Array* primes = findPrimes(max);
  for (size_t i = 0; i < getLen(primes); ++i) {
    printf("%d\n", getData(primes)[i]);
  }

  free(primes);

  return EXIT_SUCCESS;
}