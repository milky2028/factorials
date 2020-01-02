#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(size_t n) {
  for (size_t i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

void findPrimes(size_t n, size_t primes[]) {
  primes[0] = 0;
  primes[1] = 1;
  for (size_t i = 2; i <= n; i++) {
    if (isPrime(i)) {
      primes[i] = i;
    } else {
      primes[i] = 0;
    }
  }
}

// void findPrimeFactorials(size_t n, size_t primes[], size_t factorials[]) {
//     for (size_t i = 0; i <= n; i++) {
//         if (primes[i] && (n % primes[i] == 0)) {
//             factorials[i] = primes[i];
//             findPrimeFactorials(n / primes[i], primes, factorials);
//         } else {
//             factorials[i] = 0;
//         }
//     }
// }

int main(int argc, char* argv[argc + 1]) {
  size_t n = (size_t)atoi(argv[1]) + 1;
  size_t primeNumbers[n];
  findPrimes(n, primeNumbers);

  // size_t factorials[n];
  // findPrimeFactorials(n, primeNumbers, factorials);

  for (size_t i = 0; i < n; i++) {
    printf("%lu\n", primeNumbers[i]);
  }

  return EXIT_SUCCESS;
}