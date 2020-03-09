#include <stdio.h>
#include <stdlib.h>
#include "../primes.h"

void print_bounded_error(string msg) {
  printf("\n===============================================================\n");
  printf("%s\n", msg);
  printf("===============================================================\n\n");
}

int main(int argc, string argv[argc + 1]) {
  // printf("Size of uint32: %lu\n", sizeof(uint32_t));
  // printf("Size of size_t: %lu\n", sizeof(size_t));

  if (argc < 2) {
    print_bounded_error(
        "Error: no arguments specified. Please specify an upper bound.");
    exit(EXIT_FAILURE);
  };

  string* ptr = malloc(sizeof(char) * 16);
  size_t max = strtoul(argv[1], ptr, 10);

  if (!ptr || !max) {
    print_bounded_error("Please specify a valid number.");
    exit(EXIT_FAILURE);
  }

  free(ptr);

  UInt32Array* primes = find_primes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    printf("%d\n", primes->data[i]);
  }

  free_uint32_array(primes);

  exit(EXIT_SUCCESS);
}