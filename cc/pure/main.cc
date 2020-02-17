#include <cstdlib>
#include <iostream>
#include <string>
#include "../primes.h"

using std::cout;
using std::endl;
using std::exit;
using std::stoul;
using std::string;
using std::vector;

void print_bounded_error(const string msg) {
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

  // TODO: This exception is not properly handled
  size_t max = stoul(argv[1]);
  if (!max) {
    print_bounded_error("Please specify a valid number.");
    exit(EXIT_FAILURE);
  }

  auto primes = find_primes(max);
  for (auto& prime_number : primes) {
    cout << prime_number << endl;
  }

  return EXIT_SUCCESS;
}