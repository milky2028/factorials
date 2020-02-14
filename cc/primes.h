#include <cstdint>
#include <cstdlib>
#include <ctgmath>
#include <vector>

using std::vector;

typedef struct UInt32Array {
  vector<uint32_t> data;
  size_t len;
  size_t unit_size;
} UInt32Array;

bool is_prime(size_t n) {
  for (size_t i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 0 && n != 1;
}

UInt32Array* find_primes(size_t max) {
  vector<uint32_t> primes;
  for (size_t i = 2; i <= max; ++i) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  UInt32Array* ptr =
      (UInt32Array*)malloc(primes.size() * sizeof(uint32_t) + sizeof(size_t) * 2);
  ptr->data = primes;
  ptr->len = primes.size();
  ptr->unit_size = sizeof(primes[0]);
  return ptr;
}