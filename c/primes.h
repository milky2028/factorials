#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <tgmath.h>

#define ALLOC_FAIL 0
#define ALLOC_SUCCESS 1

typedef char* string;
typedef struct _UInt32Array UInt32Array;
struct _UInt32Array {
  uint32_t* data;
  size_t len;
};

UInt32Array* new_uint32_array() {
  UInt32Array* def = malloc(sizeof(UInt32Array));

  if (!def) {
    return ALLOC_FAIL;
  }

  def->data = malloc(sizeof(uint32_t));

  if (!def->data) {
    return ALLOC_FAIL;
  }

  def->len = 0;

  return def;
}

int push_to_uint32_array(UInt32Array* arr, uint32_t item) {
  arr->data = realloc(arr->data, (arr->len * sizeof(uint32_t)));

  if (!arr->data) {
    return ALLOC_FAIL;
  } else {
    arr->data[arr->len++] = item;
    return ALLOC_SUCCESS;
  }
}

void free_uint32_array(UInt32Array* arr) {
  if (arr) {
    if (arr->data) {
      free(arr->data);
    }

    free(arr);
  }
}

bool is_prime(size_t n) {
  for (size_t i = 2; i < sqrt(n); ++i) {
    if (n % i == 0) {
      return false;
    }
  }

  return n != 0 && n != 1;
}

UInt32Array* find_primes(size_t max) {
  UInt32Array* primes = new_uint32_array();
  if (!primes) {
    return ALLOC_FAIL;
  }

  for (uint32_t i = 2; i <= max; i++) {
    if (is_prime(i)) {
      push_to_uint32_array(primes, i);
    }
  }

  return primes;
}