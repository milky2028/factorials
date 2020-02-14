#include <iostream>
#include <string>
#include "../primes.h"

void print_bounded_error(std::string msg) {
  std::cout << "\n===============================================================\n";
  std::cout << msg << std::endl;
  std::cout << "===============================================================\n\n";
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    print_bounded_error(
      "Error: no arguments specified. Please specify an upper bound.");
    std::exit(EXIT_FAILURE);
  };

  size_t max = std::stoul(argv[1]);
  if (!max) {
    print_bounded_error("Please specify a valid number.");
    std::exit(EXIT_FAILURE);
  }

  UInt32Array* primes = findPrimes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    std::cout << primes->data[i] << std::endl;
  }

  free(primes->data);
  free(primes);

  return EXIT_SUCCESS;
}