#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <vector>

using std::vector;

template <typename T>
bool is_prime(T n) {
  for (T i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 0 && n != 1;
}

template <typename T>
vector<T> find_primes(T max) {
  vector<T> primes;
  for (T i = 2; i <= max; ++i) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }

  return primes;
}