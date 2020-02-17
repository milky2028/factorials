#include <cstdint>
#include <cstdlib>
#include <ctgmath>
#include <vector>

using std::vector;

bool is_prime(size_t n) {
  for (size_t i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 0 && n != 1;
}

vector<uint32_t> find_primes(size_t max) {
  vector<uint32_t> primes;
  for (size_t i = 2; i <= max; ++i) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  return primes;
}