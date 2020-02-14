#include <iostream>
#include <string>
#include "../primes.h"

using namespace std;

void print_bounded_error(string msg) {
  cout << "\n===============================================================\n";
  cout << msg << endl;
  cout << "===============================================================\n\n";
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    print_bounded_error(
      "Error: no arguments specified. Please specify an upper bound.");
    exit(EXIT_FAILURE);
  };

  size_t max = stoul(argv[1]);
  if (!max) {
    print_bounded_error("Please specify a valid number.");
    exit(EXIT_FAILURE);
  }

  UInt32Array* primes = find_primes(max);
  for (size_t i = 0; i < primes->len; ++i) {
    cout << primes->data[i] << endl;
  }

  free(primes->data);
  free(primes);

  return EXIT_SUCCESS;
}