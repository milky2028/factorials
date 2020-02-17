#include <emscripten.h>
#include <emscripten/bind.h>
#include <vector>
#include "../primes.h"

using std::vector;
using namespace emscripten;

auto find_primes_cc(uint32_t max) {
  return find_primes(max);
}

EMSCRIPTEN_BINDINGS(module) {
  function("findPrimes", &find_primes_cc);
  register_vector<uint32_t>("vector<uint32_t>");
}