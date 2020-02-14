#include <cstdio>
#include <cstdlib>
#include "../primes.h"

void printBoundedError(char const* const msg) {
  printf("\n===============================================================\n");
  printf("%s\n", msg);
  printf("===============================================================\n\n");
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printBoundedError(
        "Error: no arguments specified. Please specify an upper bound.");
    return EXIT_FAILURE;
  };

  char** ptr = (char**)malloc(sizeof(char) * 16);
  size_t max = strtoul(argv[1], ptr, 10);
  if (!max) {
    printBoundedError("Please specify a valid number.");
    return EXIT_FAILURE;
  }
  free(ptr);

  UInt32Array* primes = findPrimes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    printf("%d\n", primes->data[i]);
  }

  free(primes->data);
  free(primes);

  return EXIT_SUCCESS;
}