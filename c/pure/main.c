#include <stdio.h>
#include <stdlib.h>
#include "../primes.h"

void print_bounded_error(char* msg) {
  printf("\n===============================================================\n");
  printf("%s\n", msg);
  printf("===============================================================\n\n");
}

int main(int argc, char* argv[argc + 1]) {
  if (argc < 2) {
    print_bounded_error(
        "Error: no arguments specified. Please specify an upper bound.");
    exit(EXIT_FAILURE);
  };

  char** extra_args = malloc(sizeof(char) * 16);
  size_t max = strtoul(argv[1], extra_args, 10);

  if (!max) {
    print_bounded_error("Please specify a valid number.");
    exit(EXIT_FAILURE);
  }

  if (!extra_args) {
    allocation_error();
  } else {
    free(extra_args);
  }

  UInt32Array* primes = find_primes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    printf("%d\n", primes->data[i]);
  }

  free_uint32_array(primes);

  exit(EXIT_SUCCESS);
}