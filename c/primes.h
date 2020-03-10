#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <tgmath.h>

#define NULL_PTR 0

typedef struct _UInt32Array UInt32Array;
struct _UInt32Array {
  uint32_t* data;
  size_t len;
};

void allocation_error() {
  printf("Allocation error");
  exit(EXIT_FAILURE);
}

UInt32Array* new_uint32_array() {
  UInt32Array* def = malloc(sizeof(UInt32Array));

  if (!def) {
    allocation_error();
  }

  def->data = NULL_PTR;
  def->len = 0;

  return def;
}

void push_to_uint32_array(UInt32Array* arr, uint32_t item) {
  if (arr->data) {
    arr->data = realloc(arr->data, ((arr->len + 1) * sizeof(uint32_t)));
  } else {
    arr->data = malloc(sizeof(uint32_t));
  }

  if (arr->data) {
    arr->data[arr->len++] = item;
  } else {
    allocation_error();
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

  for (uint32_t i = 2; i <= max; i++) {
    if (is_prime(i)) {
      push_to_uint32_array(primes, i);
    }
  }

  return primes;
}