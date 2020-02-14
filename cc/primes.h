#include <cstdint>
#include <cstdlib>
#include <ctgmath>

typedef struct UInt32Array {
  uint32_t* data;
  size_t len;
  size_t unitSize;
} UInt32Array;

bool is_prime(size_t n) {
  for (size_t i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 1 && n != 0;
}

UInt32Array* find_primes(size_t max) {
  uint32_t* primes = (uint32_t*)calloc(1, sizeof(uint32_t));
  size_t index = 0;
  for (size_t i = 2; i <= max; ++i) {
    if (is_prime(i)) {
      primes[index++] = i;
      primes = (uint32_t*)realloc(primes, sizeof(uint32_t) * (index + 1));
    }
  }

  UInt32Array* ptr =
      (UInt32Array*)malloc(index * sizeof(uint32_t) + sizeof(size_t) * 2);
  ptr->data = primes;
  ptr->len = index;
  ptr->unitSize = sizeof(uint32_t);
  return ptr;
}