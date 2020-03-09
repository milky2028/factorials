#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include "../primes.h"

using std::cout;
using std::endl;
using std::exit;
using std::invalid_argument;
using std::stoul;
using std::string;
using std::vector;

void print_bounded_error(const string msg) {
  cout << "\n===============================================================\n";
  cout << msg << endl;
  cout << "===============================================================\n\n";
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    print_bounded_error(
        "Error: no arguments specified. Please specify an upper bound.");
  };

  try {
    uint32_t max = stoul(argv[1]);

    auto primes = find_primes(max);
    for (auto& prime_number : primes) {
      cout << prime_number << endl;
    }
  } catch (invalid_argument e) {
    print_bounded_error("Please specify a valid number.");
  }

  return EXIT_SUCCESS;
}